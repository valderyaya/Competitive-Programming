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

int n,m,st,d[200005];
vector<pii> v[200005];
const int inf=1e9+5;
void dijk(){
    REP1(i,1,n) d[i]=inf;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.emplace(d[st]=0,st);
    int x,dis;
    while(!q.empty()){
        tie(dis,x)=q.top(); q.pop();
        if(d[x]!=dis) continue;
        for(auto &i:v[x])
            if(d[i.F]>dis+i.S)
                q.emplace(d[i.F]=dis+i.S,i.F);
    }
}
signed main(){Alicization
    cin>>n>>m>>st;
    for(int x,y,z;m;--m){
        cin>>x>>y>>z;
        v[x].em(y,z);
    }
    dijk();
    REP1(i,1,n) cout<<d[i]<<" \n"[i==n];
    return 0;
}
