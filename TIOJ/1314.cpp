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

int n,a,b,c;
int main(){Rosario
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        if(a<0||b<0||c<0){cout<<"no\n";continue;}
        if(a>b) swap(a,b);
        if(b>c) swap(b,c);
        if(a>c) swap(a,c);
        if(a*a+b*b==c*c) cout<<"yes\n";
        else cout<<"no\n";
    }
//    system("pause");
    return 0;
}
