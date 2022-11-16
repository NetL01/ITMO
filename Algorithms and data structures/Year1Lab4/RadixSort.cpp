#include <iostream>
using namespace std;


void Counting_Sort(std::string array[], int n, int m, int k) {
    int Count['z'];
    std::string Result[n];
    for (int i = 0; i < 'z'; i++) {
        Count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        Count[array[i][m - k]]++;
    }
    for (int i = 1; i < 'z'; i++) {
        Count[i] += Count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        Result[Count[array[i][m - k]] - 1] = array[i];
        Count[array[i][m - k]]--;
    }

    for (int i = 0; i < n; i++) array[i] = Result[i];
}

void Radix_Sort (std::string array[], int n, int m, int k) {
    for (int i = 1; i <= k; i++) Counting_Sort(array, n, m, i);
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    std::string array[n];
    for (int i = 0; i < n; i++) cin >> array[i];
    Radix_Sort(array, n, m, k);
    for (auto string : array) cout << string << "\n";
    return 0;
}