#include <iostream>
using namespace std;
  
int n, dp[1000005], mod = 1e9+7;
  
int main() {
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = i-6; j < i; j++){
            if (j >= 0){
                dp[i] += dp[j];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n] << "\n";
}
