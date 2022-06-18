#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=-0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second

int n,m,a[25],ans,sum;
bool v[25],f[2505];
void dp(){
    memset(f,0,sizeof(f));  f[0]=1;
    REP1(i,1,n){
        if(v[i]) continue;
        for(int j=sum;j>=a[i];--j) f[j]|=f[j-a[i]];
    }
    int cnt=0;
    REP1(i,1,sum) cnt+=f[i];
    ans=max(ans,cnt);
}
void dfs(int x,int y){
    if(y>m||x>n+1) return;
    if(x==n+1&&y==m) return dp();
    v[x]=1; dfs(x+1,y+1); v[x]=0;
    dfs(x+1,y);
}
int main(){io
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i],sum+=a[i];
    dfs(1,0);
    cout<<ans<<"\n";
}
