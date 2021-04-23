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

const int z=2e6+1;
int m[]={0,1,2},p[3][z],n,x;
string s;
int main(){Rosario
    cin>>n>>s;
    for(int i=1;i<=n;++i){
        REP(j,3) p[j][i]=p[j][i-1];
        if(s[i-1]=='P') ++p[0][i];
        else if(s[i-1]=='E') ++p[1][i];
        else ++p[2][i];
    }x=0;
    do{
        int mx=0;
        REP1(i,1,n){
            mx=max(mx,p[m[0]][i]-p[m[1]][i]);
            x=max(x,mx+p[m[1]][i]+p[m[2]][n]-p[m[2]][i]);
        }
    }while(next_permutation(m,m+3));
    cout<<x<<"\n";
    return 0;
}
