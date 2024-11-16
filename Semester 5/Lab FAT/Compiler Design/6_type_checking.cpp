#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isTypeMatched(const string& type1, const string& type2) {
    return type1 == type2;
}

void parseDeclarations(stringstream& ss, unordered_map<string, string>& typeMap) {
    string type, var;
    while (ss >> type) {
        if (type == "int" || type == "float" || type == "char") {
            while (getline(ss, var, ',')) {
                var.erase(0, var.find_first_not_of(" \t"));
                var.erase(var.find_last_not_of(" \t;") + 1);
                if (!var.empty()) {
                    typeMap[var] = type;
                }
                if (var.find(';') != string::npos) {
                    break;
                }
            }
        }
    }
}

void checkAssignments(const string& stmt, unordered_map<string, string>& typeMap) {
    size_t pos = stmt.find('=');
    if (pos == string::npos) return;
    string lhs = stmt.substr(0, pos);
    string rhs = stmt.substr(pos + 1);
    rhs.erase(rhs.find_last_not_of("; ") + 1);
    lhs.erase(0, lhs.find_first_not_of(" \t"));
    lhs.erase(lhs.find_last_not_of(" \t") + 1);
    vector<string> tokens;
    string token;
    for (char ch : rhs) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else if (!isspace(ch)) {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    string lhsType = typeMap[lhs];
    cout << "In " << stmt << endl;
    for (const auto& var : tokens) {
        if (typeMap.find(var) != typeMap.end()) {
            cout << "Type of " << lhs << " & " << var << " --> ";
            if (isTypeMatched(lhsType, typeMap[var])) {
                cout << "MATCHED" << endl;
            } else {
                cout << "NOT MATCHED" << endl;
                return;
            }
        }
    }
}

int main() {
    unordered_map<string, string> typeMap;
    string input;
    cout << "Enter expressions: ";
    getline(cin, input);
    stringstream ss(input);
    string stmt;
    while (getline(ss, stmt, ';')) {
        stmt.erase(0, stmt.find_first_not_of(" \t"));
        stmt.erase(stmt.find_last_not_of(" \t") + 1);
        if (stmt.find('=') == string::npos) {
            stringstream declStream(stmt + ";");
            parseDeclarations(declStream, typeMap);
        }
    }
    ss.clear();
    ss.str(input);
    while (getline(ss, stmt, ';')) {
        stmt.erase(0, stmt.find_first_not_of(" \t"));
        stmt.erase(stmt.find_last_not_of(" \t") + 1);
        if (stmt.find('=') != string::npos) {
            checkAssignments(stmt + ";", typeMap);
        }
    }
    return 0;
}
