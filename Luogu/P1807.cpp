//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
#include<bits/extc++.h>
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

int dis[1505]={},n,m;
vector<pii> v[1505];
priority_queue<pii> q;
void dijk(){
    q.emplace(mkp(0,1));
    while(!q.empty()){
        int d=q.top().F,x=q.top().S;q.pop();
        if(dis[x]!=d) continue;
        for(auto &i:v[x]){
            if(dis[i.F]<i.S+d){
                dis[i.F]=i.S+d;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
}
int main(){Rosario
    cin>>n>>m;
    int a,b,c;
    while(m--) cin>>a>>b>>c,v[a].em(mkp(b,c));
    dijk();
    cout<<(dis[n]?dis[n]:-1)<<"\n";
//    system("pause");
    return 0;
}
