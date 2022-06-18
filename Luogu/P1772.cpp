#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

// inline int read() {
//     int ret=0,f=1;char ch=getchar_unlocked();
//     while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
//     while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
//     return ret*f;
// }
int n,m,k,e,dis[25]={},dp[105],cant[105][25];
bool no[25];
map<set<int>,int> ma;
vector<pii> v[25];
inline int dijk(){
    REP1(i,2,m) dis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.emplace(mkp(0,1));
    while(q.size()){
        int d=q.top().F,u=q.top().S;q.pop();
        if(d!=dis[u]) continue;
        for(auto i:v[u]){
            if(dis[i.F]>d+i.S&&!no[i.F]){
                dis[i.F]=d+i.S;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
    return dis[m];
}
int main(){Rosario
    cin>>n>>m>>k>>e;
    int d,x,y,c,sum=0;
    REP(i,e) cin>>x>>y>>c,v[x].em(mkp(y,c)),v[y].em(mkp(x,c));
    cin>>d;
    REP1(i,1,n) dp[i]=1e9;
    REP(i,d){
        cin>>c>>x>>y;
        for(;x<=y;x++) cant[x][c]=1;
    }dp[0]=-k;
    REP1(i,1,n){
        REP1(j,1,m) no[j]=0;
        for(int j=i;j>0;j--){
            REP1(l,1,m) no[l]|=cant[j][l];
            x=dijk();
            if(x==1e9) continue;
            dp[i]=min(dp[i],dp[j-1]+(i-j+1)*x+k);
        }
    }cout<<dp[n]<<"\n";
//    system("pause");
    return 0;
}
