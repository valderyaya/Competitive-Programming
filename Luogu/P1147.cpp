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

int n,sum;
int main(){//Rosario
    cin>>n;
    for(int i=1,j;i<=n/2;i++){
        sum=i;
        for(j=i+1;j<n&&sum<n;j++) sum+=j;
        if(sum==n) cout<<i<<' '<<j-1<<"\n";
    }
//    system("pause");
    return 0;
}
