#include<bits/stdc++.h>
using namespace std;

// Function to check if two types are matched
bool isTypeMatched(const string& type1, const string& type2) {
    return type1 == type2; // Returns true if types are identical
}

// Function to parse variable declarations and store their types in the map
void parseDeclarations(stringstream& ss, unordered_map<string, string>& typeMap) {
    string type, var;
    while (ss >> type) { // Read the type (e.g., int, float, char)
        if (type == "int" || type == "float" || type == "char") { // Check for valid types
            while (getline(ss, var, ',')) { // Process variables separated by commas
                var.erase(0, var.find_first_not_of(" \t")); // Trim leading spaces
                var.erase(var.find_last_not_of(" \t;") + 1); // Trim trailing spaces and semicolon
                if (!var.empty()) {
                    typeMap[var] = type; // Map variable to its type
                }
                if (var.find(';') != string::npos) { // Break at the end of the declaration
                    break;
                }
            }
        }
    }
}

// Function to check type consistency in assignments
void checkAssignments(const string& stmt, unordered_map<string, string>& typeMap) {
    size_t pos = stmt.find('='); // Find the assignment operator
    if (pos == string::npos) return; // No assignment found
    string lhs = stmt.substr(0, pos); // Extract left-hand side (LHS)
    string rhs = stmt.substr(pos + 1); // Extract right-hand side (RHS)

    // // Trim spaces and semicolon from RHS
    rhs.erase(rhs.find_last_not_of("; ") + 1);
    lhs.erase(0, lhs.find_first_not_of(" \t")); // Trim leading spaces from LHS
    lhs.erase(lhs.find_last_not_of(" \t") + 1); // Trim trailing spaces from LHS

    // Tokenize the RHS to extract variables/operands
    vector<string> tokens;
    string token;
    for (char ch : rhs) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') { // Operators
            if (!token.empty()) {
                tokens.push_back(token); // Push completed token
                token.clear();
            }
        } else if (!isspace(ch)) {
            token += ch; // Build token
        }
    }
    if (!token.empty()) {
        tokens.push_back(token); // Push the last token
    }

    // Check if LHS type matches with RHS operand types
    string lhsType = typeMap[lhs]; // Get the type of LHS
    cout << "In " << stmt << endl;
    for (const auto& var : tokens) { // Iterate over RHS tokens
        if (typeMap.find(var) != typeMap.end()) { // Check if token is a declared variable
            cout << "Type of " << lhs << " & " << var << " --> ";
            if (isTypeMatched(lhsType, typeMap[var])) { // Compare types
                cout << "MATCHED" << endl;
            } else {
                cout << "NOT MATCHED" << endl;
                return; // Stop checking if any type mismatch is found
            }
        }
    }
}

int main() {
    unordered_map<string, string> typeMap; // Map to store variable types
    string input;
    cout << "Enter expressions: ";
    getline(cin, input); // Read the entire input as a single line
    stringstream ss(input);
    string stmt;

    // First pass: Parse declarations
    while (getline(ss, stmt, ';')) { // Split input by semicolons
        if (stmt.find('=') == string::npos) { // If not an assignment
            stringstream declStream(stmt + ";"); // Add semicolon for parsing
            parseDeclarations(declStream, typeMap);
        }
    }

    // Reset the stringstream for a second pass
    ss.clear();
    ss.str(input);

    // Second pass: Check assignments
    while (getline(ss, stmt, ';')) { // Split input by semicolons
        if (stmt.find('=') != string::npos) { // If an assignment is found
            checkAssignments(stmt + ";", typeMap); // Validate assignment
        }
    }

    return 0;
}
