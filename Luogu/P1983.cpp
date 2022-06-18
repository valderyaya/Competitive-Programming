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

int n,m,in[1001]={},s[1001];
bitset<1001> vis;
bool ck[1001][1001];
vector<int> v[1001];
int main(){Rosario
    cin>>n>>m;
    for(int p,x,i=1;i<=m;++i){
        cin>>p; vis.reset();
        REP1(j,1,p) cin>>s[j],vis[s[j]]=1;
        REP1(j,s[1],s[p]) if(!vis[j]){
            REP1(k,1,p){
                if(!ck[j][s[k]]){
                    ck[j][s[k]]=1;
                    ++in[s[k]];
                    v[j].em(s[k]);
                }
            }
        }
    }
    queue<pii> q;  int ans=0;
    REP1(i,1,n) if(in[i]==0) q.emplace(mkp(i,1));
    while(!q.empty()){
        pii x=q.front(); q.pop();
        ans=max(ans,x.S);
        for(auto &i:v[x.F])
            if(--in[i]==0) q.emplace(mkp(i,x.S+1));
    }cout<<ans<<"\n";
    return 0;
}
