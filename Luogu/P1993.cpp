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

const int inf=1e9,st=5002,ed=5003;
int n,m,d[5005],c[5005];
bitset<5005> vis;
queue<int> q;
vector<pii> v[5005];
bool spfa(){
    REP1(i,1,n) d[i]=inf;
    d[st]=0; q.emplace(st); vis[st]=1; c[st]++;
    while(!q.empty()){
        int x=q.front(); q.pop(); vis[x]=0;
        for(auto &i:v[x])
            if(d[i.F]>d[x]+i.S){
                d[i.F]=d[x]+i.S;
                if(!vis[i.F]) q.emplace(i.F),vis[i.F]=1;
                if(++c[i.F]>=n) return 0;
            }
    }
    return 1;
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) v[st].em(mkp(i,0)),v[i].em(mkp(ed,0));
    for(int k,x,y,z;m;--m){
        cin>>k;
        if(k==1) cin>>x>>y>>z,v[x].em(mkp(y,-z));
        else if(k==2) cin>>x>>y>>z,v[y].em(mkp(x,z));
        else cin>>x>>y,v[x].em(mkp(y,z)),v[y].em(mkp(x,z));
    }
    cout<<(spfa()?"Yes":"No")<<"\n";
    return 0;
}
