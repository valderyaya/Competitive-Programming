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
#define lb(x) (x&(-x)) 

int n,cnt=1,m,a,b,mp[1005],mq[1005];
bitset<1005> vis;
vector<int> v[1005];
bool dfs(int x){
    vis[x]=1;
    for(int i:v[x])
        if(!~mq[i]||!vis[mq[i]]&&dfs(mq[i])) return mq[mp[x]=i]=x,1;
    return 0;
}
int main(){Rosario
    while(cin >>n>>m,n){
        cout<<"Case #"<<cnt++<<":";int ans=0;
        REP1(i,1,n) v[i].clear();
        memset(mq,-1,sizeof(mq)),memset(mp,-1,sizeof(mp));
        REP(i,m) cin>>a>>b,v[a].em(b);
        REP1(i,1,n) if(vis.reset(),dfs(i)) ans++;
        cout<<ans<<"\n";
    }
//    system("pause");
    return 0;
}


// int power(int a,int n){
//     int ans=1;
//     for(;n;n>>=1,a*=a)
//         if(n&1)
//             ans*=a;
//     return ans;
// }

// inline int read() {
//     int ret=0,f=1;char ch=getchar_unlocked();
//     while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
//     while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
//     return ret*f;
// }
