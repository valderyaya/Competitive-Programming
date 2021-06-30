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
//#define lb(x) (x&-x)

const int z=1e5+5;
vector<int> v[z];
int ans,n,m,st,A,B,ds[z],da[z],db[z];
queue<int> q;
void bfs(int x,int *d){
    q.emplace(x);
    while(!q.empty()){
        int t=q.front(); q.pop();
        for(auto &i:v[t]) if(!d[i]&&i!=x) d[i]=d[t]+1,q.emplace(i);
    }
}
int main(){Rosario
    cin>>n>>m>>st>>A>>B;
    for(int x,y;m;--m){
        cin>>x>>y;
        v[x].em(y);
        v[y].em(x);
    }
    bfs(st,ds);
    bfs(A,da);
    bfs(B,db);
    REP1(i,1,n) if(ds[A]==ds[i]+da[i]&&ds[B]==ds[i]+db[i]) ans=max(ans,ds[i]);
    cout<<ans<<"\n";
    return 0;
}
