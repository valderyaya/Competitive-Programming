#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n, q, arr[30][maxn], x, k;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> arr[0][i];
    
    for(int j = 1; j < 30; ++j)
        for(int i = 1; i <= n; ++i)
            arr[j][i] = arr[j-1][arr[j-1][i]];
    
    while(q--){
        cin >> x >> k;
        for(int i = 0; k; k >>= 1, ++i)
            if(k & 1) x = arr[i][x];
        cout << x << '\n';
    }

    return 0;
}