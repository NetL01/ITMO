using namespace std;

#include <vector>
#include <iostream>
typedef struct CodeSymbol {
    char letter;
    int first;
    int last;
} CodeSymbol;

CodeSymbol CreateCodeSymbol(char letter, int first, int last) {
    CodeSymbol code_symbol;
    code_symbol.letter = letter;
    code_symbol.first = first;
    code_symbol.last = last;
    return code_symbol;
}

std::vector<CodeSymbol> Create_Array(string& code) {
    vector<CodeSymbol> code_symbols;
    int start = 0;
    int end;
    std::string number;
    char symbol;
    for (int i = 0; i < code.length(); i++) {
        if ((int)code[i]>=48 && (int)code[i]<=57) {
            number += code[i];
        }
        else {
            if (i != 0){
                end = start + std::stoi(number) - 1;
                number = "";
                CodeSymbol codeSymbol = CreateCodeSymbol(symbol, start, end);
                code_symbols.push_back(codeSymbol);
                start += end - start + 1;
            }
            symbol = code[i];
        }
    }
    end = start + std::stoi(number) - 1;
    CodeSymbol codeSymbol = CreateCodeSymbol(symbol, start, end);
    code_symbols.push_back(codeSymbol);
    return code_symbols;
}

int main() {
    int n;
    int m;
    int k;

    int index = 0;
    int i = 0;
    int j = 0;
    int count = 0;

    string masha;
    string second_part;
    cin >> n >> m >> k;
    cin >> masha;
    cin >> second_part;
    vector<CodeSymbol> masha_symbols = Create_Array(masha);
    vector<CodeSymbol> sasha_symbols = Create_Array(second_part);

    while (i < masha_symbols.size() && j < sasha_symbols.size()){
        if (masha_symbols[i].last > sasha_symbols[j].last){
            if (masha_symbols[i].letter != sasha_symbols[j].letter){
                count += sasha_symbols[j].last - index + 1;
            }
            index = sasha_symbols[++j].first;
        }else{
            if (masha_symbols[i].letter != sasha_symbols[j].letter){
                count += masha_symbols[i].last - index + 1;
            }
            index = masha_symbols[++i].first;
        }
    }
    if (count < k){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}