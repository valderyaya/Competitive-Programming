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

int n,m,k,cnt[1005]={},ans=0,c[1005];
vector<int> v[1005];
bitset<1005> vis;
void solve(int x){
    queue<int> q;q.emplace(x);vis[x]=1;
    while(!q.empty()){
        x=q.front();q.pop();
        for(auto &i:v[x]) if(!vis[i]) q.emplace(i),cnt[i]++,vis[i]=1;
    }
}
int main(){Rosario
    cin>>k>>n>>m;
    int x,a,b;
    REP(i,k) cin>>c[i],cnt[c[i]]++;
    REP(i,m) cin>>a>>b,v[a].em(b);
    REP(i,k) vis.reset(),solve(c[i]);
    REP1(i,1,n) if(cnt[i]==k) ans++;
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
