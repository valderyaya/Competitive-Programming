//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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

int n,m,mp[1005],mq[1005],e,cnt=0;
bitset<1005> vis;
vector<int> v[1005];
bool dfs(int x){
    vis[x]=1;
    for(int i:v[x])
        if(!~mq[i]||!vis[mq[i]]&&dfs(mq[i])) return mp[mq[i]=x]=i,1;
    return 0;
}
int main(){Rosario
    cin>>n>>m>>e;
    memset(mp,-1,sizeof(mp));memset(mq,-1,sizeof(mq));
    for(int a,b,i=0;i<e;i++){
        cin>>a>>b;
        if(a>n||b>m) continue;
        v[a].em(b);
    }
    REP1(i,1,n) if(vis.reset(),dfs(i)) cnt++;
    cout<<cnt<<"\n";
//    system("pause");
    return 0;
}
