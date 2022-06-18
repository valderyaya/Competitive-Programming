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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

const int z=1e5+5;
int n,m,b[2][z];
void add(int id,int x){for(;x<=n;x+=lb(x)) ++b[id][x];}
int get(int id,int x){
    int res=0;
    for(;x;x-=lb(x)) res+=b[id][x];
    return res;
}
int main(){Rosario
    int x,y,c;
    cin>>n>>m;
    while(m--){
        cin>>c>>x>>y;
        if(c==1) add(0,x),add(1,y);
        else cout<<get(0,y)-get(1,x-1)<<"\n";
    }
    return 0;
}
