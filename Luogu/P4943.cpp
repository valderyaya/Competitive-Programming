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
#define wait system("pause");

const int z=50005;
int n,m,k,dis[z];
vector<pii> v[z];
bool is[z];
void dijk(int c,int x){
    REP1(i,1,n) dis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.emplace(mkp(dis[x]=0,x));
    while(!q.empty()){
        int d=q.top().F,x=q.top().S;q.pop();
        if(dis[x]!=d) continue;
        for(auto &i:v[x]){
            if(c==2&&is[i.F]) continue;
            if(dis[i.F]>d+i.S){
                dis[i.F]=d+i.S;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
}
int main(){Rosario
    cin>>n>>m>>k;
    int a,b,c;
    while(k--) cin>>c,is[c]=1;
    REP(i,m){
        cin>>a>>b>>c;
        v[a].em(mkp(b,c));
        v[b].em(mkp(a,c));
    }
    cin>>a>>b;
    dijk(1,1);
    int a1=dis[a],b1=dis[b];
    dijk(2,1);
    int a2=dis[a],b2=dis[b];
    dijk(1,a);
    c=dis[b];
    cout<<min({max(a1,b2),max(a2,b1),min(a1,b1)+c})<<"\n";
//    system("pause");
    return 0;
}
