//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const double mx[3][3]={{0.5149,0.3244,0.1607},{0.2654,0.6704,0.0642},{0.0248,0.1248,0.8504}};
int n,m[3];
double sum,a,b,c; 
int main(){Rosario
    cin>>n;
    REP(i,n){
        REP(j,n){a=b=c=0;
            REP(k,3) cin>>m[k];
            REP(k,3) a+=mx[0][k]*m[k];
            REP(k,3) b+=mx[1][k]*m[k];
            REP(k,3) c+=mx[2][k]*m[k];
            sum+=b;
            cout<<fixed<<setprecision(4)<<a<<' '<<b<<' '<<c<<"\n";
        }
    }
    cout<<fixed<<setprecision(4)<<"The average of Y is "<<sum/n/n<<"\n";
    return 0;
}
