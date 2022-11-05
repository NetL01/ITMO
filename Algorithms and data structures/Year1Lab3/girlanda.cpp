#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double func(vector<double> &girlands, int n) {
    double l = 0, r = girlands[0];
    while (r - l > 0.000000000001) {
        bool flag = true;
        girlands[1] = (l + r) / 2;
        for (int i = 2; i < n; i++) {
            girlands[i] = 2 * girlands[i - 1] - girlands[i - 2] + 2;
            if (girlands[i] <= 0) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            r = girlands[1];
        } else {
            l = girlands[1];
        }


    }
    return girlands[n - 1];

}

int main() {
    vector<double> girlands;
    int n;
    double a;
    cin >> n;
    cin >> a;
    girlands.resize(n);
    girlands[0] = a;
    double q = func(girlands, n);
    cout << fixed << setprecision(2) << q;
    return 0;
}