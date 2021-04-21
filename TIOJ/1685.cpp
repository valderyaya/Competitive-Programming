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
//#define lb(x) (x&-x)


vector<pii> v[205];
int n,m,p,w[205],dis[205][205],cnt=1;
priority_queue<pii,vector<pii>,greater<pii>> q;
void dijk(int x){
    REP1(i,1,n) dis[x][i]=1e9;
    while(q.size()) q.pop();
    dis[x][x]=0;q.emplace(mkp(0,x));
    while(q.size()){
        int d=q.top().F,u=q.top().S;q.pop();
        if(dis[x][u]!=d) continue;
        for(auto i:v[u]){
            if(w[i.F]<=w[x]&&dis[x][i.F]>d+i.S){
                dis[x][i.F]=d+i.S;
                q.emplace(mkp(dis[x][i.F],i.F));
            }
        }
    }
}
int main(){Rosario
    while(cin>>n>>m>>p,n){
        if(cnt>1) cout<<"\n";
        cout<<"Case #"<<cnt++<<"\n";
        REP1(i,1,n) cin>>w[i],v[i].clear();
        for(int i=0,a,b,c;i<m;i++) cin>>a>>b>>c,v[a].em(mkp(b,c)),v[b].em(mkp(a,c));
        REP1(i,1,n) dijk(i);
        for(int a,b,ans;p;p--){
            cin>>a>>b;ans=1e9;
            REP1(i,1,n) if(dis[i][a]!=1e9&&dis[i][b]!=1e9)ans=min(ans,dis[i][a]+dis[i][b]+w[i]);
            cout<<(ans==1e9?-1:ans)<<"\n";
        }
    }
//    system("pause");
    return 0;
}
