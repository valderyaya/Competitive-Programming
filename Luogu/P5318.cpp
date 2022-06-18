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

int n,m;
vector<int> v[100005];
queue<int> q;
bitset<100005> vis;
void dfs(int x){
    cout<<x<<' ';
    vis[x]=1;
    for(auto &i:v[x]) if(!vis[i]) dfs(i);
}
int main(){Rosario
    cin>>n>>m;
    int a,b;
    REP(i,m) cin>>a>>b,v[a].em(b);
    REP1(i,1,n) sort(ALL(v[i]));
    dfs(1);cout<<"\n";q.emplace(1);vis.reset();vis[1]=1;
    while(!q.empty()){
        a=q.front();q.pop();
        cout<<a<<' ';
        for(auto &i:v[a]) if(!vis[i]) vis[i]=1,q.emplace(i);
    }cout<<"\n";
//    system("pause");
    return 0;
}
