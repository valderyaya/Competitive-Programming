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

int t,a[205][205]={},n,m,x,y,mx;
int main(){Rosario
    cin>>t;
    while(t--){mx=0;
        cin>>n>>m;
        REP1(i,1,n)
            REP1(j,1,m){
                cin>>x;
                x= x==0?1:0;
                a[i][j]=a[i-1][j]+a[i][j-1]+x-a[i-1][j-1];
            }
        REP1(i,1,n)
            REP1(j,1,m)
                for(int k=i;k<=n;k++)
                    for(int l=j;l<=m;l++){
                        x=a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1];
                        y=(k-i+1)*(l-j+1);
                        if(x+x>y) mx=max(mx,y);
                    }
        cout<<mx<<"\n";
    }
//    system("pause");
    return 0;
}
