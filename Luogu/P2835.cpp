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

const int z=205;
int low[z],col[z],cl,dfn[z],cnt,tot,in[z],n;
vector<int> v[z];
stack<int> st;
bitset<z> vis;
void dfs(int x){
    low[x]=dfn[x]=++tot;
    st.emplace(x); vis[x]=1;
    for(auto &i:v[x]){
        if(!dfn[i]){
            dfs(i);
            low[x]=min(low[x],low[i]);
        }else if(vis[i]) low[x]=min(low[x],dfn[i]);
    }
    if(low[x]==dfn[x]){++cl;
        for(int u=0;u!=x;st.pop()) u=st.top(),vis[u]=0,col[u]=cl;
    }
}
int main(){Rosario
    cin>>n;
    for(int x,i=1;i<=n;++i){
        while(cin>>x,x) v[i].em(x);
    }
    REP1(i,1,n) if(!dfn[i]) dfs(i);
    REP1(i,1,n) for(auto &j:v[i]) if(col[i]!=col[j]) ++in[col[j]];
    int ans=0;
    REP1(i,1,cl) if(in[i]==0) ++ans;
    cout<<ans;
    return 0;
}
