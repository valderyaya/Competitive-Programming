//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

multiset<int> v[505];
int n,st,ans[2500],idx,m;
void dfs(int x){
    while(!v[x].empty()){
        int p=*v[x].begin();
        v[x].erase(v[x].begin());
        v[p].erase(v[p].find(x));
        dfs(p);
    }
    ans[++idx]=x;
}
int main(){Rosario
    int x,y;
    while(cin>>m,m){idx=n=0,st=1;
        while(m--) cin>>x>>y,v[x].insert(y),v[y].insert(x),n=max({n,x,y});
        REP1(i,1,n) if(v[i].size()%2){st=i;break;}
        dfs(st);
        for(int i=idx;i;--i) cout<<ans[i]<<"\n";
        cout<<"\n";
        REP1(i,1,n) v[i].clear();
    }
    return 0;
}
