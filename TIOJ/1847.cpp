#include<bits/stdc++.h>
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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int sum=0,r,n,m,ab[100005],dis[100005];
bool vis[100005];
vector<int> v[100005];
int main(){
    oi;
    int a,b;
    cin>>n>>m;
    REP(i,n){dis[i]=1e9; cin>>ab[i];}
    REP(i,m){
        cin>>a>>b;
        v[a].em(b),v[b].em(a);
    }
    cin>>r;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.emplace(mkp(0,0));dis[0]=0;
    while(q.size()){
        int d=q.top().F,u=q.top().S;q.pop();
        if(dis[u]!=d) continue;
        for(auto &i : v[u]){
            if(dis[i]>d+1){
                dis[i]=d+1;
                q.emplace(mkp(dis[i],i));
            }
        }
    }
    REP(i,n){
        if(dis[i]<=r) sum+=ab[i];
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
