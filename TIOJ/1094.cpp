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


int n,m;
bitset<1048576> v;
int main(){Rosario
    while(cin>>n,n){v.reset();v[0]=1;
        REP(i,n){
            cin>>m;
            for(int j=0;j<1048576;j++){
                if(v[j]) v[j^m]=1;
            }
        }
        for(int i=1048575;i>=0;i--) {
            if(v[i]){
                cout<<i<<"\n";break;
            }
        }
    }
//    system("pause");
    return 0;
}
