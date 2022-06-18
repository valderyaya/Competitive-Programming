// luogu-judger-enable-o2
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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

vector<pii> v[2501];
int dis[2501],n,m;
void dijkstra(int x){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    REP1(i,1,n) dis[i]=1e9;
    dis[x]=0;q.emplace(mkp(0,x));
    while(q.size()){
        int d=q.top().F,e=q.top().S;q.pop();
        if(d!=dis[e]) continue;
        for(auto u:v[e]){
            if(dis[u.F]>d+u.S){
                dis[u.F]=d+u.S;
                q.emplace(mkp(dis[u.F],u.F));
            }
        }
    }
}
int main(){
    oi;
    int a,b,c,x,y;
    cin>>n>>m>>x>>y;
    while(m--){
        cin>>a>>b>>c;
        v[a].em(mkp(b,c));
        v[b].em(mkp(a,c));
    }
    dijkstra(x);
    cout<<dis[y]<<endl;
//    system("pause");
    return 0;
}
