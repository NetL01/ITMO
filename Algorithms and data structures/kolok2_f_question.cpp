#include <iostream>
#define int long long
signed  main(){
    int n;
    std::cin >> n;
    int dp[n][10];
    dp[0][0] = 0;
    for (int i = 1; i < 10; i++){
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < 10;j++){

            dp[i][j] = dp[i-1][j];
            if (j != 0){

                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j!=9) {

                dp[i][j] += dp[i - 1][j + 1];
            }

        }
    }
    /* ответ - сумма последнего ряда */
    int sum = 0 ;
    for (int k = 0; k < 10;k++){
        sum += dp[n-1][k];
    }
    std::cout << sum;
};