//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int cnt=0;
void solve(int n,int a,int b,int c){
    if(n==1) cout<<'#'<<++cnt<<" : move the dish from #"<<a<<" to #"<<c<<"\n";
    else{
        solve(n-1,a,c,b);
        solve(1,a,b,c);
        solve(n-1,b,a,c);
    }
}
int main(){Rosario
    int n;
    cin>>n;
    solve(n,1,2,3);
    return 0;
}
