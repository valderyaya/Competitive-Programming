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

const int z=5000005;
int dfn[z],n,low[z],tot=0,in[z],col[z],cnt=0,out[z];
vector<int> v[z];
stack<int> st;
bitset<z> ins;
void dfs(int x){
    dfn[x]=low[x]=++tot;
    ins[x]=1;st.emplace(x);
    for(auto &i:v[x])
        if(!dfn[i]) dfs(i),low[x]=min(low[x],low[i]);
        else if(ins[i]) low[x]=min(low[x],dfn[i]);
    if(low[x]==dfn[x]){++cnt;
        for(int u=-1;u!=x;st.pop()) u=st.top(),ins[u]=0,col[u]=cnt;
    }
}
int main(){Rosario
    cin>>n;
    int x,y=0;
    REP1(i,1,n) while(cin>>x,x) v[i].em(x);
    REP1(i,1,n) if(!dfn[i]) dfs(i);
    REP1(i,1,n) for(auto &j:v[i]) if(col[i]!=col[j]) in[col[j]]++,out[col[i]]++;
    x=0;
    REP1(i,1,cnt){
        if(!in[i]) ++x;
        if(!out[i]) ++y;
    }
    cout<<x<<'\n'<<max(x,y)<<"\n";
//    system("pause");
    return 0;
}
