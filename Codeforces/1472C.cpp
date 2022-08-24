#include<bits/stdc++.h>
using namespace std;
long long n,dp[200005],mx,t;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("input01.in","r",stdin);
    //freopen("output01.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        mx=0;
        for(int i=0;i<n;++i)
            cin>>dp[i];
        for(int i=n-1;~i;--i){
            if(i+dp[i]<n)
                dp[i]+=dp[i+dp[i]];
            mx=max(mx,dp[i]);
        }
        cout<<mx<<"\n";
    }
}
