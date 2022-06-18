#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
//#define lb(x) (x&-x)
#define wait system("pause");

ll n,a[100005],m,p,s1,s2,sum;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    cin>>m>>p>>s1>>s2;a[p]+=s1;
    REP1(i,1,n) sum+=(m-i)*a[i];
    double idx=(double)sum/s2+m;
    if(idx<=1) cout<<1;
    else if(idx>=n) cout<<n;
    else if(idx==(int)idx) cout<<(int)idx;
    else{
        ll tmp=idx,x1,x2;
        x1=abs(sum+(m-tmp)*s2);
        x2=abs(sum+(m-tmp-1)*s2);
        cout<<(x1<=x2?tmp:tmp+1)<<"\n";
    }
//    system("pause");
    return 0;
}
