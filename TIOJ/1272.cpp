#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int in[100005],out[100005],t=0,n,m,x,k,tag[100005]={};
vector<int> v[100005];
void dfs(int a){
    in[a]=++t;
    for(int &i:v[a]) dfs(i);
    out[a]=t;
}
int get(int a){
    int r=0;
    for(;a;a-=lb(a)) r^=tag[a];
    return r;
}
void add(int a){
    for(;a<=n;a+=lb(a)) tag[a]^=1;
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n){
        cin>>k;
        while(k--) cin>>x,v[i].em(x);
    }dfs(1);
    while(m--){
        cin>>k>>x;
        if(k) cout<<get(in[x])<<"\n";
        else add(in[x]),add(out[x]+1);
    }
//    system("pause");
    return 0;
}
