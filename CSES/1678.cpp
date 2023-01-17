#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
#define mkp make_pair
 
const int z=1e5+5;
int n,m,in[z],out[z],dfn[z],t,st,ed,now,prv[z];
vector<int> v[z],ans;
bitset<z> vis;
bool dfs(int x){
    vis[x]=1;
    for(auto &i:v[x]){
        if(!dfn[i]) {
            dfn[i]=++t;
            prv[i]=x;
            if(dfs(i)) return 1;
        }else if(dfn[i]>=now&&vis[i]) return st=i,ed=x,1;
    }
    vis[x]=0;
    return 0;
}
signed main(){Rosario
    cin>>n>>m;
    for(int x,y;m--;) cin>>x>>y,++in[y],++out[x],v[x].em(y);
    REP1(i,1,n){
        if(in[i]&&out[i]&&!dfn[i]){
            dfn[i]=now=++t;
            if(dfs(i)){
                for(int j=ed;;j=prv[j]){
                    ans.em(j);
                    if(j==st) break;
                }
                reverse(ALL(ans));
                cout<<ans.size()+1<<"\n"<<ed<<' ';
                for(auto &j:ans) cout<<j<<' ';
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}
