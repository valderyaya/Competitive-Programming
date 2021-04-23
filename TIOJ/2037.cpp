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

int t,n,m,q,mp[100005],mq[100005];
bitset<100005> vis;
vector<int> v[100005];
bool dfs(int x){
    vis[x]=1;
    for(int i:v[x])
        if(!~mq[i]||!vis[mq[i]]&&dfs(mq[i])) return mp[mq[i]=x]=i,1;
    return 0;
}
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        REP1(i,1,n) v[i].clear();
        memset(mp,-1,sizeof(mp)),memset(mq,-1,sizeof(mq));
        int a,b;
        while(q--) cin>>a>>b,v[a].em(b);
        a=0;
        REP1(i,1,n) if(vis.reset(),dfs(i)) a++;
        cout<<a<<"\n";
    }
//    system("pause");
    return 0;
}
