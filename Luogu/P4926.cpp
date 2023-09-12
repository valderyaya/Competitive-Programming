//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long

const double eps = 1e-5;
int n,m,k, cnt[1005];
double dis[1005], L=0, R=10;
struct edge{int x,y;double z;};
vector<edge> v[1005];
bitset<1005> in;
bool spfa(double f){
    in.reset();
    REP1(i,0,n) cnt[i]=0, dis[i]=-1e9;
    dis[n+1]=0; cnt[n+1]=0, in[n+1]=1;
    queue<int> q;
    q.emplace(n+1);
    while(!q.empty()){
        int x=q.front(); in[x]=0; q.pop();
        for(auto &i:v[x]){
            double w=0;
            if(!i.y) w=i.z;
            else if(i.y==1) w=log2(i.z-f);
            else w=-log2(i.z+f);
            if(dis[i.x] < dis[x]+w){
                dis[i.x]=dis[x]+w;
                if(++cnt[i.x]>=n+2) return 1;
                if(!in[i.x]) in[i.x]=1, q.emplace(i.x);
            }
        }
    }
    return 0;
}
signed main(){
    cin>>n>>m>>k;
    double x,ans;
    for(int i=0;i<=n;++i) v[n+1].em(edge{i,0,0});
    for(int op,a,b,i=0;i<m;++i){
        cin>>op>>a>>b>>x;
        v[b].em(edge{a,op,x});
        if(op==1) R=fmin(R,x);
    }
    for(int i=0,c;i<k;++i){
        cin>>c>>x;
        v[c].em(edge{0,0,-log2(x)});
        v[0].em(edge{c,0,log2(x)});
    }
    if(!spfa(0)) return cout<<-1,0;
    while(R-L>eps){
        double mid = (L+R)/2;
        if(spfa(mid)) L=mid, ans=mid;
        else R=mid;
    }
    cout<<fixed<<setprecision(5)<<ans<<"\n";
    return 0;
}
