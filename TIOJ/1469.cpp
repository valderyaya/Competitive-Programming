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
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int n,m,mp[105],mq[3605],ans,q;
bitset<105> vis;
vector<int> v[105];
bool dfs(int x){
    vis[x]=1;
    for(int i:v[x])
        if(!~mq[i]||!vis[mq[i]]&&dfs(mq[i])) return mp[mq[i]=x]=i,1;
    return 0;
}
string a,b;
void add(int x,string s){
    if(s=="XXL") for(int i=0;i<q;i++) v[x].em(i);
    else if(s=="XL") for(int i=600;i<600+q;i++) v[x].em(i);
    else if(s=="L") for(int i=1200;i<1200+q;i++) v[x].em(i);
    else if(s=="M") for(int i=1800;i<1800+q;i++) v[x].em(i);
    else if(s=="S") for(int i=2400;i<2400+q;i++) v[x].em(i);
    else for(int i=3000;i<3000+q;i++) v[x].em(i); 
}
int main(){Rosario
    while(cin>>n>>m){q=n/6;
        memset(mq,-1,sizeof(mq)),memset(mp,-1,sizeof(mp));
        REP(i,n) v[i].clear();
        REP(i,m) cin>>a>>b,add(i,a),add(i,b);
        ans=0;
        REP(i,m) if(vis.reset(),dfs(i)) ans++;
        cout<<(ans==m?"YES\n":"NO\n");
    }
//    system("pause");
    return 0;
}
