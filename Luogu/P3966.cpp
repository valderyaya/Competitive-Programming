//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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
const int z=1e6+5;
int tr[z][26],n,fail[z],cnt,val[z],ans[z];
vector<int> ed[z],v[z];
string str[z];
void insert(string s,int id){
    int p=0;
    for(auto &i:s){
        if(!tr[p][i-'a']) tr[p][i-'a']=++cnt;
        p=tr[p][i-'a'];
    }
    ed[p].em(id);
}
void build(){
    queue<int> q;
    REP(i,26) if(tr[0][i]) q.emplace(tr[0][i]);
    while(!q.empty()){
        int x=q.front(); q.pop();
        REP(i,26)
            if(tr[x][i]) fail[tr[x][i]]=tr[fail[x]][i],q.emplace(tr[x][i]);
            else tr[x][i]=tr[fail[x]][i];
    }
}
void add(string s){
    int p=0;
    for(auto &i:s){
        p=tr[p][i-'a'];
        val[p]++;
    }
}
void dfs(int x){
    for(auto &i:v[x]) dfs(i),val[x]+=val[i];
    for(auto &i:ed[x]) ans[i]=val[x];
}
void solve(){
    REP1(i,1,n) add(str[i]);
    REP1(i,1,cnt) v[fail[i]].em(i);
    dfs(0);
    REP1(i,1,n) cout<<ans[i]<<"\n";
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>str[i],insert(str[i],i);
    build();
    solve();
    return 0;
}
