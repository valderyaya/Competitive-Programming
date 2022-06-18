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

int f[41][41][41][41],n,m,a[355],c[5];
void up(int &x,int y){
    if(x<y) x=y;
}
int main(){Rosario
    cin>>n>>m; int x;
    REP1(i,1,n) cin>>a[i];
    REP(i,m) cin>>x,c[x]++;
    f[0][0][0][0]=a[1];
    REP1(i,0,c[1])
        REP1(j,0,c[2])
            REP1(k,0,c[3])
                REP1(l,0,c[4]){
                    x=1+i+j*2+k*3+l*4;
                    if(i) up(f[i][j][k][l],f[i-1][j][k][l]+a[x]);
                    if(j) up(f[i][j][k][l],f[i][j-1][k][l]+a[x]);
                    if(k) up(f[i][j][k][l],f[i][j][k-1][l]+a[x]);
                    if(l) up(f[i][j][k][l],f[i][j][k][l-1]+a[x]);
                }
    cout<<f[c[1]][c[2]][c[3]][c[4]]<<"\n";
    return 0;
}
