#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

#define int ll
const int mod=9997;
int power(int a,int n){
    int ret=1;
    for(;n;n>>=1,a=a*a%mod) if(n&1) ret=ret*a%mod;
    return ret%mod;
}
int n,m,k,dfn[10005],low[10005],t=0,ck=0;
vector<int> v[10005];
stack<int> st;
bitset<10005> in;
void dfs(int x){
    low[x]=dfn[x]=++t;
    in[x]=1;st.emplace(x);
    for(auto &i:v[x])  
        if(!dfn[i]) dfs(i),low[x]=min(low[x],low[i]);
        else if(in[i]&&dfn[i]<dfn[x]) low[x]=min(low[x],dfn[i]);
    if(dfn[x]==low[x]){
        int cnt=0;
        for(int u=0;u!=x;st.pop()) u=st.top(),cnt++,in[u]=0;
        if(cnt>1) ck=1;
    }
}
main(){Rosario
    cin>>n>>m>>k;
    for(int a,b,i=0;i<m;i++) cin>>a>>b,v[a].em(b);
    REP1(i,1,n) if(!dfn[i]) dfs(i);
    cout<<(ck?"No\n":"Yes\n");
    cout<<(ck?k*k:power(2,k))<<"\n";
//    system("pause");
    return 0;
}
