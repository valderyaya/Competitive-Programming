#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=-0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define lb(x) (x&(-x))

int n,m,s[4][2050][2050];
char ch;
void add(int x,int y,int v){
    for(int i=x;i<=n;i+=lb(i))
        for(int j=y;j<=m;j+=lb(j)){
            s[0][i][j]+=v;
            s[1][i][j]+=v*y;
            s[2][i][j]+=v*x;
            s[3][i][j]+=v*x*y;
        }
}
int qry(int x,int y){
    int r=0;
    for(int i=x;i;i-=lb(i))
        for(int j=y;j;j-=lb(j))
            r+=(x+1)*(y+1)*s[0][i][j]-(x+1)*s[1][i][j]-(y+1)*s[2][i][j]+s[3][i][j];
    return r;
}
int main(){io
    cin>>ch>>n>>m;
    int a,b,c,d,v;
    while(cin>>ch){
        cin>>a>>b>>c>>d;
        if(ch=='L'){
            cin>>v;
            add(a,b,v);
            add(c+1,b,-v);
            add(a,d+1,-v);
            add(c+1,d+1,v);
        }else cout<<qry(c,d)-qry(a-1,d)-qry(c,b-1)+qry(a-1,b-1)<<"\n";
    }
}
