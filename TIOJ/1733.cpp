//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)


int n,m,a[55][55]={};
int main(){Rosario
    while(cin>>n>>m){
        REP1(i,1,n) REP1(j,1,m) cin>>a[i][j],a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        int mx=-1e9;
        REP1(i,1,n)
            REP1(j,1,m)
                for(int k=0;k<i;k++)
                    for(int l=0;l<j;l++)
                        mx=max(mx,a[i][j]-a[i][l]-a[k][j]+a[k][l]);
        cout<<mx<<"\n";
    }
//    system("pause");
    return 0;
}
