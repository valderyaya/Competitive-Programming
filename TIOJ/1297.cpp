//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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

int n;
int main(){Rosario
    while(cin>>n){
        if(n<0){cout<<"stupid\n";continue;}
        else if(n==0){cout<<"0\n";continue;}
        int x=(double)n*100./101-2;
        for(;x<1027;x++)
            if(int(double(x*101./100))==n) break;
        if(x<0||x>1024) cout<<"stupid\n";
        else cout<<x<<"\n"; 
    }
    return 0;
}
