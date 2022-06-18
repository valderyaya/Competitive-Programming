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


struct edge{int to,nxt;}e[120];
int sz[60],n,mn,t,h[60],cnt,a[60];
string ans[60];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x,int p){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        if(e[i].to==p) continue;
        int v=e[i].to;
        dfs(v,x);  sz[x]+=sz[v];
        a[x]=max(a[x],sz[v]);
    }
    a[x]=max(a[x],n-sz[x]);
    mn=min(mn,a[x]);
}
string dfs2(int x,int p){
    string res="0";
    vector<string> t;
    for(int i=h[x];i;i=e[i].nxt){
        if(e[i].to==p) continue;
        int v=e[i].to;
        t.em(dfs2(v,x));
    }
    sort(ALL(t));
    for(auto &i:t) res+=i;
    return res+"1";
}
int main(){Rosario
    cin>>t;
    for(int o=1;o<=t;o++){
        cin>>n; int x;
        memset(h,0,sizeof(h));
        memset(a,0,sizeof(a));
        cnt=0, mn=n+1, ans[o]="1";
        REP1(i,1,n){
            cin>>x;
            if(x) add(x,i),add(i,x);
        }dfs(1,0);
        REP1(i,1,n) if(mn==a[i]) ans[o]=min(ans[o],dfs2(i,0));
        for(int i=1;i<=o;i++) if(ans[i]==ans[o]){cout<<i<<"\n";break;}
    }
//    system("pause");
    return 0;
}
