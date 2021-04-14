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

int dis[1005],n,m,st,sd;
priority_queue<pii> q;
vector<pii> v[1005];
void dijk(){
    while(q.size()) q.pop();
    REP1(i,1,n) dis[i]=1e9;
    dis[st]=0;q.emplace(mkp(0,st));
    while(q.size()){
        int d=q.top().F,e=q.top().S;q.pop();
        if(dis[e]!=d) continue;
        for(auto i:v[e]){
            if(dis[i.F]>i.S+d){
                dis[i.F]=i.S+d;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
}
int main(){Rosario
    while(cin>>n>>m>>st>>sd){
        REP1(i,1,n) v[i].clear();
        int a,b,c;
        REP(i,m) cin>>a>>b>>c,v[a].em(mkp(b,c)),v[b].em(mkp(a,c));
        dijk();
        if(dis[sd]==1e9) cout<<"He is very hot\n";
        else cout<<dis[sd]<<"\n";
    }
//    system("pause");
    return 0;
}
