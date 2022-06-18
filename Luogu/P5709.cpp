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
//#define lb(x) (x&-x)

int a,b,c;
int cel(int a,int b){
    return b/a+!!(b%a);
}
int main(){//Rosario
    cin>>a>>b>>c;
    if(b==0) cout<<a;
    else if(c>=a*b) cout<<0;
    else if(c%b==0||a<=0) cout<<a-c/b;
    else cout<<a-c/b-1;
//    system("pause");
    return 0;
}
