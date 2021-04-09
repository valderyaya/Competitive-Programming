#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
 
int n,m,ans=0,idx;
vector<int> v[10005];
bool vis[10005];
void dfs(int x,int d){
    vis[x]=1;
    if(d>ans){
        ans=d;idx=x;
    }
    for(int i:v[x]){
        if(!vis[i]) dfs(i,d+1);
    }
    vis[x]=0;
}
int main(){
    oi;
    cin>>n;
    REP(i,n){
        while(cin>>m,m!=-1){
            v[i].em(m);v[m].em(i);
        }
    }
    dfs(0,0);
    ans=0;
    dfs(idx,0);
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
