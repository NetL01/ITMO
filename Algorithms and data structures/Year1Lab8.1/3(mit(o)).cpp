#include <vector>

#include <iostream>

#include <cmath>
int main() {
    int num;
    std::cin >> num;
    std::string haff_codes_string[num];
    for (int i = 0; i < num; i++){
        std::cin >> haff_codes_string[i];
    }
    std::string elem;
    for (int i = 0; i < num; i++){
        elem = haff_codes_string[i];
        std::vector<int> errors;
        for (int j = 0; j <= log2((double)elem.length()); j++) {
            int controlN = (int)pow(2, j);
            int count = 0;
            for (int k = controlN - 1; k < elem.length(); k += 2 * controlN) {
                for (int l = k; l < k + controlN; l++) {
                    if (l >= elem.length()) {
                        break;
                    }
                    if (l != controlN - 1) {
                        if (elem[l] == '1') {
                            count += 1;
                        }
                    }
                }
            }
            if ((count % 2 == 0 && elem[controlN - 1] == '1')
                || (count % 2 == 1 && elem[controlN - 1] == '0')) {
                errors.push_back(controlN);
            }
        }
        if (!errors.empty()) {
            int sum = -1;
            for (int mistake : errors) {
                sum += mistake;
            }
            if (elem[sum] == '1') {
                elem[sum] = '0';
            }
            else {
                elem[sum] = '1';
            }
        }
        for (int i = 0; i < elem.length(); i++) {
            if (((i + 1) & i) == 0) {
                continue;
            }
            std::cout << elem[i];
        }
        std::cout << std::endl;
    }
    return 0;
}