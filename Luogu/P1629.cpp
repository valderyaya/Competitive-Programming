#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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

int n,m,dis[1005],sum=0;
vector<pii> v[1003];
void dijk(int x){
    REP1(i,1,n) dis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.emplace(mkp(dis[x]=0,x));
    while(!q.empty()){
        pii x=q.top();q.pop();
        if(x.F!=dis[x.S]) continue;
        for(auto &i:v[x.S]){
            if(dis[i.F]>i.S+x.F){
                dis[i.F]=i.S+x.F;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
}
int main(){Rosario
    cin>>n>>m;
    int a,b,c;
    while(m--) cin>>a>>b>>c,v[a].em(mkp(b,c));
    REP1(i,1,n){
        dijk(i);
        sum+=dis[1];
        if(i==1) REP1(i,2,n) sum+=dis[i];
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
