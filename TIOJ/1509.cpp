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

int n,m,dis[1000005];
vector<pii> v[1000005],z[1000005];
int main(){Rosario
    cin>>n>>m;
    int a,b,c;
    ll sum=0;
    REP(i,m) cin>>a>>b>>c,v[a].em(mkp(b,c)),z[b].em(mkp(a,c));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    REP1(i,1,n) dis[i]=1e9;
    dis[1]=0;q.emplace(mkp(0,1));
    while(q.size()){
        int d=q.top().F,e=q.top().S;q.pop();
        if(d>dis[e]) continue;
        for(auto i:v[e]){
            if(dis[i.F]>d+i.S){
                dis[i.F]=d+i.S;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
    REP1(i,1,n)
        if(dis[i]==1e9) {cout<<0;return 0;}
        else sum+=dis[i],dis[i]=1e9;
    dis[1]=0;q.emplace(mkp(0,1));
    while(q.size()){
        int d=q.top().F,e=q.top().S;q.pop();
        if(d>dis[e]) continue;
        for(auto i:z[e]){
            if(dis[i.F]>d+i.S){
                dis[i.F]=d+i.S;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
    REP1(i,1,n)
        if(dis[i]==1e9) {cout<<0;return 0;}
        else sum+=dis[i];
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
