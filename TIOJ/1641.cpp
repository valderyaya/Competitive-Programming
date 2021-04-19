//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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

const int z=10005,inf=1e9;
const double eps=1e-7;
int n,m,s,t;
double dis[z];
priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> q;
vector<pair<int,double>> v[z];
double dijkstra(){
    REP1(i,1,n) dis[i]=inf;
    dis[s]=0; q.emplace(mkp(0,s));
    double y;int x;
    while(!q.empty()){
        tie(y,x)=q.top();q.pop();
        if(dis[x]!=y) continue;
        for(auto &i:v[x])
            if(dis[i.F]>y+i.S){
                dis[i.F]=y+i.S;
                q.emplace(mkp(dis[i.F],i.F));
            }
    }
    return dis[t];
}
int main(){//Rosario
    scanf("%d %d %d %d",&n,&m,&s,&t);
    int a,b;double c;
    while(m--) cin>>a>>b>>c,v[a].em(mkp(b,log10(c+1)));
    double ans=dijkstra();
    //cout<<ans<<endl;
    int x=int(floor(ans+eps)+eps); ans-=x;
    printf("%.2fe+%03d\n",pow(10,ans),x);
}
