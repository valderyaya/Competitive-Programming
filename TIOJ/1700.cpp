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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)

int a[25],n;
int main(){
    //oi;
    while(cin>>n){
    REP(i,n) cin>>a[i];
    int gc=a[0];
    REP1(i,1,n-1) gc=__gcd(gc,a[i]);
    cout<<gc<<"\n";
    }
//    system("pause");
    return 0;
}
