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

const int maxn=600001;
int tri[maxn<<5][2],cnt[maxn<<5],rt=0,n,m,s=0,root[maxn<<5];
void insert(int &x,int pre){
    x=++rt;
    int k=x,c;
    for(int i=24;~i;--i){
        c=(s>>i)&1;
        tri[k][c^1]=tri[pre][c^1];
        tri[k][c]=++rt;
        k=tri[k][c],pre=tri[pre][c];
        cnt[k]=cnt[pre]+1;
    }
}
int query(int l,int r,int x){
    int ret=0,c;
    for(int i=24;~i;--i){
        c=(x>>i)&1;
        if(cnt[tri[r][c^1]]>cnt[tri[l][c^1]]){
            ret|=(1<<i);
            l=tri[l][c^1],r=tri[r][c^1];
        }else l=tri[l][c],r=tri[r][c];
    }
    return ret;
}
char c;
int main(){Rosario
    cin>>n>>m;
    int x,l,r;
    insert(root[1],root[0]);
    ++n;
    REP1(i,2,n) cin>>x,s^=x,insert(root[i],root[i-1]);
    while(m--){
        cin>>c;
        if(c=='A') cin>>x,s^=x,++n,insert(root[n],root[n-1]);
        else{
            cin>>l>>r>>x;
            cout<<query(root[l-1],root[r],s^x)<<"\n";
        }
    }
//    system("pause");
    return 0;
}
