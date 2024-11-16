#include <bits/stdc++.h>
using namespace std;

#define MAX_IDENTIFIERS 100

bool Invalid = false;

typedef struct {
    char name[50];
    int location;
    char type[10];
    int size;
} SymbolTableEntry;

int isValidIdentifier(char *identifier) {
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return 0;
    }
    for (int i = 1; i < strlen(identifier); i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    SymbolTableEntry symbolTable[MAX_IDENTIFIERS];
    char input[256];
    int location = 1000;
    int index = 0;
    cout << "Enter declarations: ";
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, " ,;\n");
    while (token != NULL) {
        if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 ||
            strcmp(token, "char") == 0 || strcmp(token, "double") == 0) {
            char type[10];
            strcpy(type, token);
            int size = 0;
            int num = 1;
            token = strtok(NULL, " ,;\n");
            while (token != NULL && (strcmp(token, "int") != 0 && strcmp(token, "float") != 0 &&
                                    strcmp(token, "char") != 0 && strcmp(token, "double") != 0)) {
                if (strchr(token, '[') != NULL) {
                    char identifier[50] = {0};
                    int arrSize = 1;
                    sscanf(token, "%[^[][%d]", identifier, &arrSize);
                    if (isValidIdentifier(identifier)) {
                        strcpy(symbolTable[index].name, identifier);
                        symbolTable[index].location = location;
                        if (strcmp(type, "int") == 0) size = arrSize * 2;
                        else if (strcmp(type, "float") == 0) size = arrSize * 4;
                        else if (strcmp(type, "double") == 0) size = arrSize * 8;
                        else if (strcmp(type, "char") == 0) size = arrSize * 1;
                        strcpy(symbolTable[index].type, type);
                        symbolTable[index].size = size;
                        location += size;
                        index++;
                    } else {
                        cout << "Invalid identifier: " << token << endl;
                        Invalid = true;
                    }
                } else {
                    if (isValidIdentifier(token)) {
                        strcpy(symbolTable[index].name, token);
                        symbolTable[index].location = location;
                        if (strcmp(type, "int") == 0) size = 2;
                        else if (strcmp(type, "float") == 0) size = 4;
                        else if (strcmp(type, "double") == 0) size = 8;
                        else if (strcmp(type, "char") == 0) size = 1;
                        strcpy(symbolTable[index].type, type);
                        symbolTable[index].size = size;
                        location += size;
                        index++;
                    } else {
                        cout << "Invalid identifier: " << token << endl;
                        Invalid = true;
                    }
                }
                token = strtok(NULL, " ,;\n");
            }
            continue;
        } else {
            if (strlen(token) > 1) {
                cout << "Invalid identifier: " << token << endl;
                Invalid = true;
            }
        }
        token = strtok(NULL, " ,;\n");
    }

    if (!Invalid) {
        cout << "\nSymbol Table:\n";
        cout << "Name\t\tLocation\tSize\tType\n";
        for (int i = 0; i < index; i++) {
            printf("%s\t\t%d\t\t%d\t%s\n",
                   symbolTable[i].name,
                   symbolTable[i].location,
                   symbolTable[i].size,
                   symbolTable[i].type);
        }
    }

    return 0;
}
