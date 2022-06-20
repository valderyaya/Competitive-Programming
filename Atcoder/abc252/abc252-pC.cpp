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

int cnt[10][10],n,mn=1e9;
string s[100];
signed main(){valder
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>s[i];
        for(int j=0;j<10;++j) cnt[s[i][j]-'0'][j]++;
    }
    for(int i=0;i<10;++i){
        int mx=0;
        for(int j=0;j<10;++j)
            mx=max(mx,10*(cnt[i][j]-1)+j);
        mn=min(mn,mx);
    }
    cout<<mn;
}
