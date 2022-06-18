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

const int z=900005;
int tr[z][26],n,cnt,fail[z],ed[z];
struct qwq{
    int c=0;
    string s;
}a[155];
void init(){
    REP(i,z) memset(tr[i],0,sizeof(tr[i]));
    memset(fail,0,sizeof(fail));
    memset(ed,0,sizeof(ed));
}
void insert(string s,int id){
    int p=0,u;
    for(auto &i:s){
        u=i-'a';
        if(!tr[p][u]) tr[p][u]=++cnt;
        p=tr[p][u];
    }
    ed[p]=id;
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
void solve(string s){
    int p=0,mx=0;
    for(auto &i:s){
        p=tr[p][i-'a'];
        for(int j=p;j;j=fail[j]){
            if(ed[j]){
                a[ed[j]].c++;
                mx=max(mx,a[ed[j]].c);
            }
        }
    }
    cout<<mx<<"\n";
    REP1(i,1,n)
        if(a[i].c==mx) cout<<a[i].s<<"\n";
}
string s;
int main(){Rosario
    while(cin>>n,n){
        init();
        REP1(i,1,n) cin>>a[i].s,a[i].c=0,insert(a[i].s,i);
        cin>>s; build(); solve(s);
    }
    return 0;
}
