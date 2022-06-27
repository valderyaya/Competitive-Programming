#pragma GCC optimize("O2")
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

int n,x,y,d;
string s;
signed main(){valder
    cin>>n>>s;
    for(int i=0;i<n;++i){
        if(s[i]=='R') d=(d+1)%4;
        else{
            if(d==0) ++x;
            else if(d==1) --y;
            else if(d==2) --x;
            else ++y;
        }
    }
    cout<<x<<' '<<y;
}
