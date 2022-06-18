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

const int z=1e6+5;
int cnt=0,tr[z][26],fail[z],n,ed[z];
void insert(string s){
    int p=0;
    for(auto &i:s){
        if(!tr[p][i-'a']) tr[p][i-'a']=++cnt;
        p=tr[p][i-'a'];
    }
    ++ed[p];
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
int query(string s){
    int res=0,p=0;
    for(auto &i:s){
        p=tr[p][i-'a'];
        for(int j=p;j&&ed[j];j=fail[j])
            res+=ed[j],ed[j]=0;
    }
    return res;
}
int main(){Rosario
    cin>>n;
    string s;
    while(n--) cin>>s,insert(s);
    build();
    cin>>s;
    cout<<query(s)<<"\n";
    return 0;
}
