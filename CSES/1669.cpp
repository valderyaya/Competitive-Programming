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
 
int n,m,tme[100005],prv[100005],dfn,st,ed;
vector<int> v[100005],ans;
bool dfs(int x,int p){
    tme[x]=++dfn;
    prv[x]=p;
    bool ret=0;
    for(auto &i:v[x]){
        if(!tme[i]){
            ret|=dfs(i,x);
            if(ret) return ret;
        }else if(i!=p) return st=i,ed=x,1;
    }
    return ret;
}
signed main(){Rosario
    cin>>n>>m;
    for(int x,y;m--;) cin>>x>>y,v[x].em(y),v[y].em(x);
    REP1(i,1,n)
        if(!tme[i]){
            if(dfs(i,i)){
                for(int j=ed;;j=prv[j]){
                    ans.em(j);
                    if(j==st) break;
                }cout<<ans.size()+1<<"\n"<<st<<' ';
                for(auto &j:ans) cout<<j<<' ';
                return 0;
            }
        }
    cout<<"IMPOSSIBLE\n";
}
