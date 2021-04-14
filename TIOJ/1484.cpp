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
#define wait system("pause");

const int z=1e5+5;
int t,n,m,low[z],dep[z],vis[z],dfn;
vector<int> v[z];
bool dfs(int x){
    vis[x]=1;
    low[x]=dep[x]=++dfn;
    int cnt=0;
    for(auto &i:v[x]){
        if(!~vis[i]) return 0;
        if(vis[i]==1) ++cnt,low[x]=min(low[x],dep[i]);
        else{
            if(!dfs(i)) return 0;
            low[x]=min(low[x],low[i]);
            if(low[i]>dep[x]) return 0;
            if(low[i]<dep[x]) ++cnt;
        }
    }
    vis[x]=-1;
    return cnt<2;
}
int main(){Rosario
    cin>>t;
    while(t--){
        int a,b;
        cin>>n>>m; dfn=0;
        REP(i,n) v[i].clear();
        while(m--) cin>>a>>b,v[a].em(b);
        memset(vis,0,sizeof(vis));
        if(!dfs(0)) cout<<"NO\n";
        else{a=0;
            REP(i,n) if(!vis[i]){a=1;break;}
            cout<<(a?"NO":"YES")<<"\n";
        }
    }
//    system("pause");
    return 0;
}
