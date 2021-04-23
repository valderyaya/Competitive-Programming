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

int t;
string s;
int main(){//Rosario
    cin>>t;getchar();
    while(t--) cin>>s,cout<<(s!="1")<<"\n";
//    system("pause");
    return 0;
}

// inline int read() {
//     int ret=0,f=1;char ch=getchar_unlocked();
//     while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
//     while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
//     return ret*f;
// }
