#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long


int c,a[11][11];
signed main(){
    int c=0;
    cout<<10<<"\n";
    REP1(i,1,10){
        if(i&1) REP1(j,1,10) a[i][j]= ++c;
        else for(int j=10;j;--j) a[i][j]=++c;
    }
    REP1(i,1,10)
        REP1(j,1,10) cout<<a[i][j]<<" \n"[j==10];
    return 0;
}
