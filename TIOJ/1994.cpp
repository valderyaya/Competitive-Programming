//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int a[2050][2050],n;
void dfs(int l,int r,int x,int y,int ck){
    if(r-l==3){
        if(ck==1) a[x][y]=l,a[x+1][y]=l+1,a[x+1][y+1]=r-1,a[x][y+1]=r;
        else if(ck==2) a[x][y]=l,a[x+1][y]=r,a[x+1][y+1]=r-1,a[x][y+1]=l+1;
        else if(ck==3) a[x][y]=r-1,a[x+1][y]=r,a[x+1][y+1]=l,a[x][y+1]=l+1;
        else if(ck==4) a[x][y]=r-1,a[x+1][y]=l+1,a[x+1][y+1]=l,a[x][y+1]=r;
        return ;
    }
    int p=(r-l+1)/4,o=sqrt(r-l+1)/2;
    if(ck==1) dfs(l,l+p-1,x,y,2),dfs(l+p,l+p+p-1,x+o,y,1),dfs(l+p+p,r-p,x+o,y+o,1),dfs(r-p+1,r,x,y+o,4);
    else if(ck==2) dfs(l,l+p-1,x,y,1),dfs(r-p+1,r,x+o,y,3),dfs(l+p+p,r-p,x+o,y+o,2),dfs(l+p,l+p+p-1,x,y+o,2);
    else if(ck==3) dfs(l+p+p,r-p,x,y,3),dfs(r-p+1,r,x+o,y,2),dfs(l,l+p-1,x+o,y+o,4),dfs(l+p,l+p+p-1,x,y+o,3);
    else dfs(l+p+p,r-p,x,y,4),dfs(l+p,l+p+p-1,x+o,y,4),dfs(l,l+p-1,x+o,y+o,3),dfs(r-p+1,r,x,y+o,1);
}
int main(){Rosario
    cin>>n;
    if(!n) cout<<"0\n";
    else{
        dfs(1,(1<<n)*(1<<n),1,1,1);
        REP1(i,1,1<<n) REP1(j,1,1<<n) cout<<a[i][j]-1<<" \n"[j==1<<n];
    }
    return 0;
}
