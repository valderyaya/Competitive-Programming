//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
#include<bits/extc++.h>
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

int n,m,t=1,dfn[5005]={},low[5005];
vector<int> v[5005],ans,tmp;
stack<int> st;
bitset<5005> in;
void dfs(int x){
    dfn[x]=low[x]=t++;
    in[x]=1;st.emplace(x);
    for(auto &i:v[x]){
        if(!dfn[i]) dfs(i),low[x]=min(low[x],low[i]);
        else if(in[i]&&dfn[i]<dfn[x]) low[x]=min(dfn[i],low[x]);
    }
    if(low[x]==dfn[x]){
        for(int u=0;u!=x;st.pop())
            u=st.top(),tmp.em(u),in[u]=0;
        sort(ALL(tmp));
        if(tmp.size()>ans.size()||(tmp.size()==ans.size()&&tmp<ans)) ans=tmp;
        tmp.clear();
    }
}
int main(){Rosario
   cin>>n>>m;
   int a,b,c;
   REP(i,m){
       cin>>a>>b>>c;
       v[a].em(b);
       if(c==2) v[b].em(a);
   }
   REP1(i,1,n) if(!dfn[i]) dfs(i);
   cout<<ans.size()<<"\n";
   for(int i:ans) cout<<i<<' ';
//    system("pause");
    return 0;
}
