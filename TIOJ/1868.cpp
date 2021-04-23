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

const int z=3e5+5;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-f; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
vector<int> v[z],v2[z];
int dfn[z],tot=0,low[z],col[z],cnt=0,a[z],w[z],ww[z];
bitset<z> in;
stack<int> st;
void dfs(int x){
    dfn[x]=low[x]=++tot;
    st.emplace(x); in[x]=1;
    for(auto &i:v[x])
        if(!dfn[i]) dfs(i),low[x]=min(low[x],low[i]);
        else if(in[i]) low[x]=min(dfn[i],low[x]);
    if(low[x]==dfn[x]){++cnt;
        for(int u=-1;u!=x;st.pop()) u=st.top(),in[u]=0,col[u]=cnt,w[cnt]+=u?1:0;
    }
}
int dfs2(int x){
    if(ww[x]) return ww[x];
    int mx=0,tmp;
    for(auto &i:v2[x]){
        tmp=dfs2(i);
        mx=max(mx,tmp);
    }
    return ww[x]=mx+w[x];
}
int main(){//Rosario
    int n,m;
    char ch;
    n=read(),m=read(),a[1]=read();
    v[0].em(1);
    REP1(i,2,n){
        a[i]=read();
        if(a[i]>=a[i-1]) v[i].em(i-1);
        if(a[i-1]>=a[i]) v[i-1].em(i);
        v[0].em(i);
    }
    REP1(i,1,n){
        ch=getchar();
        if(ch=='T') v[i].em(0);
    }
    REP1(i,0,n) if(!dfn[i]) dfs(i);
    REP1(i,0,n) for(auto &j:v[i]) if(col[i]!=col[j]) v2[col[i]].em(col[j]);
    printf("%d\n",dfs2(col[m]));
//    system("pause");
    return 0;
}
