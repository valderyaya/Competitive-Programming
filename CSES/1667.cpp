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
 
int n,m,d[100005],pre[100001];
queue<int> q;
vector<int> v[100005];
void dfs(int x){
    if(!pre[x]) return cout<<x<<' ',void();
    dfs(pre[x]);
    cout<<x<<' ';
}
signed main(){Rosario
    cin>>n>>m;
    for(int x,y;m--;) cin>>x>>y,v[x].em(y),v[y].em(x);
    q.emplace(1);
    d[1]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &i:v[x]) if(!d[i]){
            d[i]=d[x]+1;
            pre[i]=x;
            q.emplace(i);
        }
    }
    if(d[n]){
        cout<<d[n]<<"\n";
        dfs(n);
    }else cout<<"IMPOSSIBLE\n";
}
