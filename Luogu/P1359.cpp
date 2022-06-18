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

int n,m,dis[205];
vector<pii> v[205];
int dijk(){
    REP1(i,2,n) dis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii>> q;q.emplace(mkp(0,1));
    while(q.size()){
        int d=q.top().F,u=q.top().S;q.pop();
        if(d!=dis[u]) continue;
        for(auto i:v[u]){
            if(dis[i.F]>d+i.S){
                dis[i.F]=d+i.S;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
    return dis[n];
}
int main(){Rosario
    cin>>n;
    for(int i=n-1,c=1;i;i--,c++){
        for(int j=i,cn=c+1;j;j--,cn++) cin>>m,v[c].em(mkp(cn,m));
    }
    cout<<dijk()<<"\n";
//    system("pause");
    return 0;
}
