#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

int n,k,ans;
string s[15];
signed main(){valder
    cin>>n>>k;
    for(int i=0;i<n;++i) cin>>s[i];
    for(int i=0;i<(1<<n);++i){
        int cnt[26]={},c=0;
        for(int j=0;j<n;++j){
            if(i>>j&1)
                for(auto &k:s[j]) cnt[k-'a']++;
        }
        for(int i=0;i<26;++i) if(cnt[i]==k) ++c;
        ans=max(ans,c);
    }
    cout<<ans;
}
