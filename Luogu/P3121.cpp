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
//#define lb(x) (x&-x)

const int z=1e5+5;
int cnt,tr[z][26],fail[z],st[z],top,ed[z];
char ans[z];
void insert(string s){
    int p=0;
    for(auto &i:s){
        if(!tr[p][i-'a']) tr[p][i-'a']=++cnt;
        p=tr[p][i-'a'];
    }
    ed[p]=s.size();
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
string s,t;
int n;
void solve(){
    int p=0;
    for(auto &i:s){
        p=tr[p][i-'a'];
        st[++top]=p;
        ans[top]=i;
        if(ed[p]) top-=ed[p],p=st[top];
    }
    REP1(i,1,top) cout<<ans[i];
}
int main(){Rosario
    cin>>s>>n;
    while(n--) cin>>t,insert(t);
    build();
    solve();
    return 0;
}
