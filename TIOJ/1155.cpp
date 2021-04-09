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
#define wait system("pause");

int n;
priority_queue<double,vector<double>,greater<double>>q;
char c;
double x,y,sum=0;
int main(){Rosario
    cin>>n;
    while(n--) cin>>c>>x,q.emplace(x);
    while(q.size()>1){
        x=q.top();q.pop();
        y=q.top();q.pop();
        sum+=x+y;
        q.emplace(x+y);
    }cout<<fixed<<setprecision(2)<<sum;
//    system("pause");
    return 0;
}
