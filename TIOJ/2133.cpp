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
string s;
int main(){Rosario
    cin>>n;
    while(n--){
        cin>>s;int mx=1;
        REP(i,s.size()){
            int c=1;
            for(int j=i-1,k=i+1;j>=0&&k<s.size()&&s[j]==s[k];--j,++k,++c);
            mx=max(mx,(c<<1)-1);c=0;
            for(int j=i,k=i+1;j>=0&&k<s.size()&&s[j]==s[k];--j,++k,++c);
            mx=max(mx,c<<1);
        }
        cout<<mx<<"\n";
    }
    return 0;
}
