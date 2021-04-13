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

const int z=105;
struct edge{int to,nxt;}e[200];
int mn,cnt,n,sz[z],mx[z],h[z];
string ans[2];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x,int p){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        if(e[i].to==p) continue;
        int v=e[i].to;
        dfs(v,x); sz[x]+=sz[v];
        mx[x]=max(mx[x],sz[v]);
    }
    mx[x]=max(mx[x],n-sz[x]);
    mn=min(mn,mx[x]);
}
string dfs2(int x,int p){
    vector<string> t;
    string res="<";
    for(int i=h[x];i;i=e[i].nxt){
        if(e[i].to==p) continue;
        t.em(dfs2(e[i].to,x));
    }
    sort(ALL(t));
    for(auto &i:t) res+=i;
    return res+">";
}
int main(){Rosario
    while(cin>>n,n){
        for(int o=0;o<2;o++){
            memset(h,0,sizeof(h));
            memset(mx,0,sizeof(mx));
            cnt=0,mn=z; int a,b;
            REP(i,n-1) cin>>a>>b,add(a,b),add(b,a);
            dfs(1,0);  ans[o]=">";
            REP1(i,1,n) if(mx[i]==mn) ans[o]=min(ans[o],dfs2(i,0));
        }
        if(ans[0]==ans[1]) cout<<"Same\n";
        else cout<<"Different\n";
    }
//    system("pause");
    return 0;
}
