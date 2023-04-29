#include "header.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    three(&a, &b); /* по указателям */
    three(a, b); /* по ссылкам */
    cout << a << " " << b;
    float c;
    cin >> c;
    round_pointer(&c);
    round_link(c);
    change_radius_pointer(&a, &b);
    change_radius_link(a, b);
    vector<vector<int>> matrix;
    int t = 1;
    for (int i = 0; i < 3; i++) {
        vector<int> m;
        for (int j = 0; j < 3; j++) {
            m.push_back(t);
            t++;
        }
        matrix.push_back(m);
    }
    transp(&matrix);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\n";
        }
    }
    transp(matrix);
    return 0;
}