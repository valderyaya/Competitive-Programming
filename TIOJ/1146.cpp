#include<bits/stdc++.h>
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

int dp[35][35]={},n,a[35][35],res=0,x,y;
char c;
void mat(){
    int tmp[35][35]={};
    REP(i,n) REP(j,n) REP(k,n) tmp[i][j]+=dp[i][k]*a[k][j];
    REP(i,n) REP(j,n) dp[i][j]=tmp[i][j];
    res+=dp[x-1][y-1];
}
int main(){Rosario
    cin>>n;
    REP(i,n) dp[i][i]=1;
    REP(i,n) REP(j,n) cin>>c,a[i][j]=c-'0';
    int k;
    cin>>x>>y>>k;
    //res+=dp[x-1][y-1];
    while(k--) mat();
    cout<<res<<"\n";
//    system("pause");
    return 0;
}
