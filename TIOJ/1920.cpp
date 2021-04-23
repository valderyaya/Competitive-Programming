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

const int maxn= 100005;
int tri[maxn<<5][2],cnt[maxn<<5],rt=0,n,m,s[10005]={},root[10005];
void insert(int &x,int pre,int ss){
    x=++rt;
    int k=x,c;
    for(int i=30;~i;--i){
        c=(ss>>i)&1;
        tri[k][c^1]=tri[pre][c^1];
        tri[k][c]=++rt;
        k=tri[k][c],pre=tri[pre][c];
        cnt[k]=cnt[pre]+1;
    }
}
int query(int l,int r,int x){
    int ret=0,c;
    for(int i=30;~i;--i){
        c=(x>>i)&1;
        if(cnt[tri[l][c^1]]>cnt[tri[r][c^1]]){
            ret|=(1<<i);
            l=tri[l][c^1],r=tri[r][c^1];
        }else l=tri[l][c],r=tri[r][c];
    }
    return ret;
}
int main(){Rosario
    cin>>n>>m;int a,b,x,ans;
    insert(root[n],0,0);
    REP(i,n) cin>>s[i];
    for(int i=n-1;i>=0;--i) s[i]^=s[i+1],insert(root[i],root[i+1],s[i]);
    //REP(i,n) cout<<s[i]<<" \n"[i==n-1];
    while(m--){
        cin>>a>>b>>x;
        cout<<query(root[a],root[b],s[b]^x)<<"\n";
    }
   //system("pause");
    return 0;
}
