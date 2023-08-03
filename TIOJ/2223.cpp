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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair

struct qwq{
    int x,c;
    bool operator<(const qwq &p)const{
        return c>p.c;
    }
}a[1005];
int n,m,s;
signed main(){StarBurstStream
    cin>>n>>m;
    REP(i,n) cin>>a[i].x>>a[i].c;
    sort(a,a+n);
    REP(i,n){
        if(a[i].x<m){
            s+=a[i].x*a[i].c;
            m-=a[i].x;
        }else{
            s+=a[i].c*m;
            break;
        }
    }
    cout<<s<<"\n";
    return 0;
}
