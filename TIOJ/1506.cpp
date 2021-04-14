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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int a,aa,b,bb;
int main(){
    oi;
    cin>>a>>aa>>b>>bb;
    double x=(double)-(b-bb)/(a-aa);
    double y=x*a+b;
    if(abs(x)==0) x=0;
    if(abs(y)==0) y=0;
    cout<<fixed<<setprecision(2)<<x<<'\n'<<y<<"\n";
//    system("pause");
    return 0;
}
