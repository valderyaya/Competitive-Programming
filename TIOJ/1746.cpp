//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";

int n,k,dis[100005],st,ed,max_=0,ans=0,to[100005];
vector<pii> v[100005];
bitset<100005> is;
bool ck=0;
void dfs(int x,int p,int d){
    if(d>max_) max_=d,ed=x;
    for(auto &i:v[x]){
        if(i.F!=p) dfs(i.F,x,d+1);
    }
}
void dp(int x,int p){
    for(auto &i:v[x]){
        if(i.F==p) continue;
        dp(i.F,x);
        ans=max(ans,dis[x]+dis[i.F]+i.S);
        dis[x]=max(dis[x],dis[i.F]+i.S);
    }
}
void dfs_find(int x,int p,int tar){
    if(ck) return;
    for(auto &i:v[x]){
        if(i.F==p) continue;
        if(i.F==tar){
            to[x]=i.F;
            ck=1;
            return ;
        }
        to[x]=i.F;
        dfs_find(i.F,x,tar);
        if(ck) return;
    }
}
int main(){Rosario
    cin>>n>>k;
    for(int a,b,i=0;i<n-1;i++) cin>>a>>b,v[a].em(mkp(b,1)),v[b].em(mkp(a,1));
    dfs(1,0,0);max_=0;st=ed;dfs(st,0,0);
    if(k==1){
        cout<<2*(n-1)-max_+1<<"\n";
        return 0;
    }
    dfs_find(st,0,ed);
    for(int i=st;i;i=to[i]) is[i]=1;
    REP1(i,1,n)
        if(is[i])
            for(auto &j:v[i]) if(is[j.F]) j.S=-1;
    dp(1,0);
    cout<<2*n-max_-ans<<"\n";
//    system("pause");
    return 0;
}
