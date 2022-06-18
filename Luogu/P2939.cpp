#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n,m,k,dis[2100005];
vector<pii> v[2100005];
void dijkstra(){
    REP1(i,1,(k+1)*n) dis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.emplace(mkp(0,1));dis[1]=0;
    while(!q.empty()){
        int d=q.top().F,x=q.top().S;q.pop();
        if(d!=dis[x]) continue;
        for(auto &i:v[x]){
            if(dis[i.F]>d+i.S){
                dis[i.F]=i.S+d;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
}
int main(){Rosario
    cin>>n>>m>>k;
    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        REP1(i,0,k){
            v[a+i*n].em(mkp(b+i*n,c));
            v[b+i*n].em(mkp(a+i*n,c));
            if(i!=k) v[a+i*n].em(mkp(b+(i+1)*n,0)),v[b+i*n].em(mkp(a+(i+1)*n,0));
        }
    }dijkstra();
    int ans=1e9;
    for(int i=n;i<=(k+1)*n;i+=n) ans=min(ans,dis[i]);
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
