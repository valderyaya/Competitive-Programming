#include<bits/stdc++.h>
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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
 
int n,a[10005],ans=0;
int main(){
    oi;
    cin>>n;
    REP(i,n) cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++) ans+=(a[i]-a[i-1])*(a[i]-a[i-1]);
    cout<<ans+a[0]*a[0]<<"\n";
//    system("pause");
    return 0;
}
