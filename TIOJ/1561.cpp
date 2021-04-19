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

int st,ed,n,m,dis1[105],dis2[105];
vector<pii> v[105];
void dijk(){
    REP(i,n) dis1[i]=dis2[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.emplace(mkp(0,st));dis1[st]=0;
    while(!q.empty()){
        int d=q.top().F,u=q.top().S;q.pop();
        if(dis2[u]<d) continue;
        for(auto &i:v[u]){
            int dis=i.S+d;
            if(dis1[i.F]>dis){
                dis2[i.F]=dis1[i.F];
                dis1[i.F]=dis;
                q.emplace(mkp(dis1[i.F],i.F));
            }else if(dis>dis1[i.F]&&dis<dis2[i.F]){
                dis2[i.F]=dis;
                q.emplace(mkp(dis2[i.F],i.F));
            }
        }
    }
}
int main(){Rosario
    while(cin>>n>>m){
        REP(i,n) v[i].clear();
    int a,b,c;
    while(m--) cin>>a>>b>>c,v[a].em(mkp(b,c)),v[b].em(mkp(a,c));
    cin>>st>>ed;
    dijk();
    cout<<(dis2[ed]==1e9?-1:dis2[ed])<<'\n';}
//    system("pause");
    return 0;
}
