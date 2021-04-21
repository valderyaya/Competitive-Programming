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
#define wait system("pause");

int n,mn=1e6,c=0,mx=0,cnt=0;
pii tr[100001];
void dfs(int x,int d){
    if(!~x) return mn=min(mn,d),mx=max(mx,d),void();
    dfs(tr[x].F,d+1),dfs(tr[x].S,d+1);
}
int dfs2(int x,int d){
    if(!~x) return d==mn?0:1;
    int a=dfs2(tr[x].F,d+1),b=dfs2(tr[x].S,d+1);
    if((a==0&&b==1) || (a==2&&b==1) || (a==0&&b==2)) ++cnt;
    if(a+b==4) return c=1,2;
    if(a==2||b==2||a+b==1) return 2;
    return a+b?1:0;
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>tr[i].F>>tr[i].S;
    dfs(1,0);
    if(mx==mn) cout<<0;
    else if(mx-mn>1) cout<<-1;
    else{
        dfs2(1,0);
        if(c) cout<<-1;
        else cout<<cnt;
    }
//    system("pause");
    return 0;
}
