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
//#define lb(x) (x&-x)

const int z=2e3+5;
int n,m,t,d[z],cnt[z];
vector<pii> v[z];
queue<int> q;
bool spfa(){
    REP1(i,2,n) d[i]=1e9;
    memset(cnt,0,sizeof(cnt));
    while(!q.empty()) q.pop();
    q.emplace(1);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &i:v[x]){
            if(d[i.F]>i.S+d[x]){
                if(++cnt[i.F]==n) return 1;
                d[i.F]=i.S+d[x];
                q.emplace(i.F);
            }
        }
    }
    return 0;
}
signed main(){Rosario
    cin>>t;
    while(t--){
        cin>>n>>m;
        REP1(i,1,n) v[i].clear();
        for(int x,y,k;m;--m){
            cin>>x>>y>>k;
            v[x].em(y,k);
            if(k>=0) v[y].em(x,k);
        }
        cout<<(spfa()?"YES":"NO")<<"\n";
    }
    return 0;
}
