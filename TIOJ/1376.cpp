//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&(-x)) 

int n,m,mp[15],mq[105];
bitset<15> vis;
vector<int> v[15];
bool dfs(int x){
    vis[x]=1;
    for(int i:v[x])
        if(!~mq[i]||!vis[mq[i]]&&dfs(mq[i])) return mp[mq[i]=x]=i,1;
    return 0;
}
int main(){Rosario
    cin>>n>>m;int a,b;
    REP(i,m) cin>>a>>b,v[a].em(b);
    a=0;
    memset(mp,-1,sizeof(mp)),memset(mq,-1,sizeof(mq));
    REP(i,n) if(vis.reset(),dfs(i)) a++;
    cout<<a<<"\n";
//    system("pause");
    return 0;
}
