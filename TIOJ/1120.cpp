#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)


int main(){Rosario
    int n;
    while(cin>>n){cout<<'(';
        n=n*6%40;
        if(n<=5) cout<<10+n<<','<<5<<")\n";
        else if(n<=15) cout<<15<<','<<n<<")\n";
        else if(n<=25) cout<<30-n<<','<<15<<")\n";
        else if(n<=35) cout<<5<<','<<40-n<<")\n";
        else cout<<n-30<<','<<5<<")\n";
    }
//    system("pause");
    return 0;
}
