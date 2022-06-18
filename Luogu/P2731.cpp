//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=505;
int ans[z*z],n,st=1,mx,mn=550,dg[z],id,v[z][z];
void dfs(int x){
    REP1(i,mn,mx)
        if(v[x][i]>0){
            --v[x][i],--v[i][x];
            dfs(i);
        }
    ans[++id]=x;
}
int main(){Rosario
    cin>>n;
    int x,y;
    while(n--){
        cin>>x>>y;
        mn=min({mn,x,y});
        mx=max({mx,x,y});
        ++v[x][y],++v[y][x];
        ++dg[x],++dg[y];
    }
    REP1(i,mn,mx) if(dg[i]&1){st=i;break;}
    dfs(st);
    for(;id;--id) cout<<ans[id]<<"\n";
    return 0;
}
