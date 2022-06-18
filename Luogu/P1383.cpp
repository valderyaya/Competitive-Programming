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
//#define line cout<<"-------------------------\n";

const int maxn=1e5+1;
int rt[maxn],ls[maxn<<5],cnt=0,n,m,rs[maxn<<5],sz[maxn<<5],idx=0;
char val[maxn<<5];
void up(int l,int r,int &x,int pre,char c){
    x=++cnt;
    rs[x]=rs[pre],ls[x]=ls[pre],sz[x]=sz[pre];
    if(l==r) return sz[x]=1,val[x]=c,void();
    int mid=l+r>>1;
    if(sz[ls[x]]==mid-l+1) up(mid+1,r,rs[x],rs[pre],c);
    else up(l,mid,ls[x],ls[x],c);
    sz[x]=sz[ls[x]]+sz[rs[x]];
}
void query(int l,int r,int x,int idx){
    if(l==r) return cout<<val[x]<<"\n",void();
    int mid=l+r>>1;
    if(idx<=sz[ls[x]]) return query(l,mid,ls[x],idx);
    else return query(mid+1,r,rs[x],idx-sz[ls[x]]);
}
int main(){Rosario
    cin>>n;
    char c,x;
    REP1(i,1,n){
        cin>>x;
        if(x=='T') cin>>c,++idx,up(1,n,rt[idx],rt[idx-1],c);
        else if(x=='U') cin>>m,++idx,rt[idx]=rt[idx-m-1];
        else cin>>m,query(1,n,rt[idx],m);
    }
//    system("pause");
    return 0;
}
