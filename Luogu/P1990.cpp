#include<bits/stdc++.h>
using namespace std;

int n, dp[1000001], dp2[1000001];
const int mod = 1e4;
int main(){
    cin >> n;
    dp[0] = 1;
    dp[1] = dp2[1] = 1;
    for(int i = 2; i <= n; ++i){
        dp[i] = ((dp[i-1] + dp[i-2]) % mod + 2 * dp2[i-2] % mod) % mod;
        dp2[i] = (dp2[i-1] + dp[i-1])%mod;
    }
    cout << dp[n] << "\n";
}
