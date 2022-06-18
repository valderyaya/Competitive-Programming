//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Alicization ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
 #define int ll
int n,m,fx=1,fy=1,sx,sy;
struct qwq{
    char c;
    int x,y;
}b[500005];
pii a[500005];
signed main(){Alicization
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i].F>>a[i].S;
    REP1(i,1,m){
        cin>>b[i].c;
        if(b[i].c=='m') cin>>b[i].x>>b[i].y;
    }
    for(int i=m;i;--i){
        if(b[i].c=='x') fx*=-1;
        else if(b[i].c=='y') fy*=-1;
        else{
            sx+=b[i].x*fx;
            sy+=b[i].y*fy;
        }
    }
    REP1(i,1,n) cout<<fx*(a[i].F+sx)<<' '<<fy*(a[i].S+sy)<<"\n";
    return 0;
}
