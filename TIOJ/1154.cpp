#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)

int n;
string a[130];
void dfs(int x,int y,int xx,int yy){
    int c=0,w=0,b=0;
    REP1(i,x,xx-1){
        REP1(j,y,yy-1){c++;
            if(a[i][j]=='0') w++;
            else b++;
        }
    }
    if(w==c){cout<<"w ";return;}
    else if(b==c){cout<<"b ";return;}
    cout<<"g ";
    dfs(x,y+yy>>1,x+xx>>1,yy),dfs(x,y,xx+x>>1,yy+y>>1),dfs(xx+x>>1,y,xx,yy+y>>1),dfs(xx+x>>1,yy+y>>1,xx,yy);
}
int main(){
    Rosario
    cin>>n;
    REP(i,n) cin>>a[i];
    dfs(0,0,n,n);
//    system("pause");
    return 0;
}
