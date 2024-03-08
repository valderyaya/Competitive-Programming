#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
#define mkp make_pair
 
 
int n,m,col[100001];
vector<int> v[100001];
void dfs(int x,int c){
    col[x]=c;
    for(auto &i:v[x])
        if(!col[i]){
            dfs(i,3-col[x]);
        }else if(col[i]==col[x]){
            cout<<"MANY\n";
            exit(0);
        }
}
signed main(){Rosario
    cin>>n>>m;
    for(int x,y;m--;) cin>>x>>y,v[x].em(y),v[y].em(x);
    REP1(i,1,n) if(!col[i]){
        dfs(i,1);
    }
    REP1(i,1,n) cout<<col[i]<<" \n"[i==n];
}
