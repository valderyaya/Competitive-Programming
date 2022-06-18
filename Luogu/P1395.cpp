#include<bits/stdc++.h>
//#include<bits/extc++.h>
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
#define wait system("pause");

int n,ans,mi=1e9,d[50005],sum=0;
vector<int> v[50005];
void dfs(int x,int p){
    d[x]=1;
    int mx=0;
    for(auto &i:v[x])
        if(i!=p) dfs(i,x),d[x]+=d[i],mx=max(mx,d[i]);
    mx=max(n-d[x],mx);
    if(mx<mi) ans=x,mi=mx;
    else if(mx==mi) ans=min(ans,x);
}
void dfs2(int x,int p){
    d[x]=1;
    for(auto &i:v[x])
        if(i!=p) dfs2(i,x),d[x]+=d[i];
    sum+=d[x];
}
int main(){Rosario
    cin>>n;
    for(int a,b,i=0;i<n-1;i++) cin>>a>>b,v[a].em(b),v[b].em(a);
    dfs(1,1);dfs2(ans,0);
    cout<<ans<<" "<<sum-n<<"\n";
//    system("pause");
    return 0;
}
