#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void buildcode(int n, vector<vector<bool>>&GrayCode){
    GrayCode[0][n - 1] = 0;
    GrayCode[1][n - 1] = 1;

    int p = 2;
    for (int i = 2; i <= n; i++) {
        int t = p;
        p *= 2;
        for (int k = p / 2 + 1; k <= p; k++) {
            GrayCode[k - 1] = GrayCode[t - 1];
            GrayCode[t - 1][n - i] = 0;
            GrayCode[k - 1][n - i] = 1;
            t--;
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<bool> y(n);
    vector<vector<bool>> GrayCode(pow(2,n), y);
    buildcode(n, GrayCode);
    for (int j=0; j<GrayCode.size(); j++){
        for (int h=0; h < n;h++){
            cout << GrayCode[j][h];
        }
        cout << endl;
    }
}

