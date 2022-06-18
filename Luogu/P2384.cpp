// luogu-judger-enable-o2
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
//#define lowbit(x) (x&(-x)) 

priority_queue<pii,vector<pii>,greater<pii>> q;
vector<pii> v[1001];
int dis[1001];
int n,m,a,b,c;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
    REP1(i,1,n) dis[i]=2147483647;
    while(m--){
        cin>>a>>b>>c;
        v[a].em(mkp(b,c));
    }
    dis[1]=1;q.emplace(mkp(1,1));
    while(q.size()){
        int d=q.top().F,u=q.top().S;q.pop();
        if(d!=dis[u])continue;
        for(auto e:v[u]){
            if(dis[e.F]>dis[u]*e.S){
                dis[e.F]=dis[u]*e.S%9987;
                q.emplace(mkp(dis[e.F],e.F));
            }
        }
    }
    cout<<dis[n]<<endl;
//    system("pause");
    return 0;
}
