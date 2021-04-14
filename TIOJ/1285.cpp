#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
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
// #define lb(x) (x&-x)


ll n,m,sum;
int main(){Rosario
    while(cin>>n>>m){
        sum=0;
        while(n>0&&m>0){
            if(n<m) n^=m,m^=n,n^=m;
            sum++;
            n-=m;
        }
        cout<<sum<<"\n";
    }
//    system("pause");
    return 0;
}
