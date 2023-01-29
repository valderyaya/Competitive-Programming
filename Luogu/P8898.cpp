#include<bits/stdc++.h>
using namespace std;

string s;
int t, n, k;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin >> n >> k >> s;
        string ans;
        for(int i=0;i<n;++i) ans+='.';
        int tot = 0, farthestH = -1, farthestG = -1;
        for(int i = 0; i < n; ++i){
            if(s[i]=='H' && farthestH < i){
                ++tot;
                for(int j=min(i+k,n-1); j>=0; --j)
                    if(ans[j]=='.'){
                        ans[j]='H';
                        farthestH = j+k;
                        break;
                    }
            }else if(s[i]=='G' && farthestG < i){
                ++tot;
                for(int j=min(i+k,n-1); j>=0; --j)
                    if(ans[j]=='.'){
                        ans[j]='G';
                        farthestG = j+k;
                        break;
                    }
            }
        }
        cout<< tot << '\n' << ans << '\n';
    }
}
