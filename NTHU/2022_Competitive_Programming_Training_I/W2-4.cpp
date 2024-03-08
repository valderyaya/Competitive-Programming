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


string s[10];
int ck[10],cal;
bool chk(int x){
    for(int i=x-1;i;--i) if(ck[i]==ck[x] || abs(i-x) == abs(ck[i]-ck[x])) return 0;
    return 1;
}
void dfs(int row){
    if(row==9) return ++cal,void();
    REP1(i,1,8){
        if(s[row][i-1]=='*') continue;
        ck[row] = i;
        if(chk(row)) dfs(row + 1);
        ck[row] = 0;
    }
}
signed main(){StarBurstStream
    REP1(i,1,8) cin>>s[i];
    dfs(1);
    cout<<cal<<"\n";
    return 0;
}
