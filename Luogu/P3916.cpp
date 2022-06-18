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

int n,m,ans[100005]={};
vector<int> v[100005];
void dfs(int x,int mx){
    if(ans[x]) return;
    ans[x]=mx;
    for(auto &i:v[x]) dfs(i,mx);
}
int main(){Rosario
    cin>>n>>m;
    int a,b;
    REP(i,m) cin>>a>>b,v[b].em(a);
    for(int i=n;i>0;i--) dfs(i,i);
    REP1(i,1,n) cout<<ans[i]<<' ';
//    system("pause");
    return 0;
}
