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
#define lb(x) (x&-x)
#define wait system("pause");

const int z=400005;
set<int> s;
bool in[200005];
map<int,int> m;
vector<pii> v[200005];
int n,k[200005],b[z],ans[200005],idx=0,mx=-1;
void add(int x,int v){for(;x<=z;x+=lb(x)) b[x]+=v;}
int que(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=b[x];
    return res;
}
void dfs(int x,int d){
    s.insert(-d);
    s.insert(-d-k[x]);
    for(auto &i:v[x]) dfs(i.F,d+i.S);
}

void DFS(int x,int d){
    int cnt=que(m[d]);
    if(mx<cnt) mx=cnt,idx=0,ans[idx++]=x;
    else if(mx==cnt) ans[idx++]=x;
    add(m[d+k[x]],1);
    for(auto &i:v[x]) DFS(i.F,d+i.S);
    add(m[d+k[x]],-1);
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>k[i];
    int x,y,c;
    REP(i,n-1) cin>>x>>y>>c,v[x].em(mkp(y,c)),in[y]=1;
    REP1(i,1,n) if(!in[i]){dfs(i,0);c=0;break;}
    for(auto &i:s) m[-i]=++c;
    // for(auto &i:m) cout<<i.F<<" "<<i.S<<" \n";
    DFS(1,0);
    sort(ans,ans+idx);
    REP(i,idx) cout<<ans[i]<<" \n"[i==idx-1];
//    wait
}
