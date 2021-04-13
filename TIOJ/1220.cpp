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

int n,m,col[100005],cnt=0,pa[100005];
vector<int> v[100005];
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void bfs(int x){
    queue<int> q;
    q.emplace(x);pa[x]=fin(x+1);++cnt;
    while(!q.empty()){
        int w=q.front();q.pop();
        for(auto &i:v[w]) col[i]=w;
        for(int i=fin(1);i<=n;i=fin(i+1)) if(col[i]!=w) pa[i]=fin(i+1),q.emplace(i);
    }
}
int main(){Rosario
    cin>>n>>m;
    for(int a,b,i=0;i<m;i++) cin>>a>>b,v[a].em(b),v[b].em(a);
    REP1(i,1,n) pa[i]=i;
    pa[n+1]=n+1;
    for(int i=fin(1);i<=n;i=fin(i+1)) bfs(i);
    cout<<cnt<<"\n";
//    system("pause");
    return 0;
}
