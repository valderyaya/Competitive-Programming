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

ll n,c[40][40];
int main(){//Rosario
    for(int i=1;i<=36;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    cin>>n;
    cout<<c[n<<1][n]/(n+1)<<"\n";
//    system("pause");
    return 0;
}
