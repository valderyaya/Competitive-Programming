//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

int a[125][125]={},n,mx=0;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) REP1(j,1,n){
        cin>>a[i][j];a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
    }
    REP1(i,1,n)
        REP1(j,1,n)
            for(int k=1;k<=i;k++) 
                for(int l=1;l<=j;l++)
                    mx=max(mx,a[i][j]-a[k-1][j]-a[i][l-1]+a[k-1][l-1]);
    cout<<mx<<"\n";
//    system("pause");
    return 0;
}
