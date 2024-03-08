//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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


int n;
vector<pair<int,string>> ans[20];
string rev(string s){
    return s[0]=='i'?"out":"in";
}
signed main(){StarBurstStream
    ans[1].push_back({1,"out"});
    ans[2].push_back({2,"out"});
    ans[2].push_back({1,"out"});
    for(int i=3;i<19;++i){
        for(auto &j:ans[i-2]) ans[i].em(j);
        ans[i].push_back({i,"out"});
        for(int j=ans[i-2].size()-1;j>=0;--j) ans[i].push_back({ans[i-2][j].F,rev(ans[i-2][j].S)});
        for(auto &j:ans[i-1]) ans[i].em(j);
    }
    cin>>n;
    for(auto &i:ans[n]) cout<<"Move ring "<<i.F<<' '<<i.S<<"\n";
}
