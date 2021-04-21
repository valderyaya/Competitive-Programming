#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll n,a[20000005],s=0,sa=0;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i],s+=a[i],sa+=i*a[i];
    if(sa%s==0) return cout<<0<<' '<<(sa/s)-1<<"\n",0;
    for(int i=1;i<n/2;i++){
        sa-=i*a[i];sa-=(n-i+1)*a[n-i+1];
        sa+=i*a[n-i+1];sa+=(n-i+1)*a[i];
        if(sa%s==0) return cout<<i<<' '<<sa/s-1<<"\n",0;
    }
//    system("pause");
    return 0;
}
