//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,q,l[1000005],r[1000005];
vector<vector<string>> v;
int main(){Rosario
    cin>>n>>m;
    v.resize(n+1,vector<string>(m+1));
    REP1(i,1,n) REP1(j,1,m) cin>>v[i][j];
    REP1(i,1,n) l[i]=i;
    REP1(i,1,m) r[i]=i;
    cin>>q; char c; int x,y,xx,yy;
    while(q--){
        cin>>c;
        if(c=='S') cin>>x>>y>>xx>>yy,swap(v[l[x]][r[y]],v[l[xx]][r[yy]]);
        else if(c=='R') cin>>x>>y,swap(l[x],l[y]);
        else cin>>x>>y,swap(r[x],r[y]);
    }
    REP1(i,1,n) REP1(j,1,m) cout<<v[l[i]][r[j]]<<" \n"[j==m];
    return 0;
}
