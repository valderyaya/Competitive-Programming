//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,m,bit[10000001];
void add(int x,int v){for(;x<=n;x+=lb(x)) bit[x]+=v;}
int que(int x){
    int r=0;
    for(;x;x-=lb(x)) r+=bit[x];
    return r;
}
int main(){Rosario
    cin>>n>>m;
    int x,y,z;
    while(m--){
        cin>>z>>x;
        if(z==1) cout<<que(x)<<"\n";
        else cin>>y,add(x,1),add(y+1,-1);
    }
    return 0;
}
