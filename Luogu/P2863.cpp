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
#define wait system("pause");

int n,m,ans=0,dfn[10005],low[10005],tme=0;
vector<int> v[10005];
stack<int> st;
bitset<10005> in;
void dfs(int x){
    dfn[x]=low[x]=++tme;
    st.emplace(x),in[x]=1;
    for(auto &i:v[x])
        if(!dfn[i]) dfs(i),low[x]=min(low[x],low[i]);
        else if(dfn[i]<dfn[x]&&in[i]) low[x]=min(low[x],dfn[i]);
    if(dfn[x]==low[x]){
        int cnt=0;
        for(int u=0;u!=x;st.pop()) u=st.top(),cnt++,in[u]=0;
        if(cnt>1) ans++;
    }
}
int main(){Rosario
    cin>>n>>m;
    for(int a,b,i=0;i<m;i++) cin>>a>>b,v[a].em(b);
    REP1(i,1,n) if(!dfn[i]) dfs(i);
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
