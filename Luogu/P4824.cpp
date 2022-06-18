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

const int z=1e6+5;
char a[z],b[z];
int st[z],top,fa[z],fb[z];
int main(){Rosario
    scanf("%s%s",a+1,b+1);
    int la=strlen(a+1),lb=strlen(b+1);
    for(int i=2,j=0;i<=lb;++i){
        while(j&&b[i]!=b[j+1]) j=fb[j];
        if(b[i]==b[j+1]) ++j;
        fb[i]=j;
    }
    for(int i=1,j=0;i<=la;++i){
        while(j&&a[i]!=b[j+1]) j=fb[j];
        if(a[i]==b[j+1]) ++j;
        fa[i]=j, st[++top]=i;
        if(j==lb) top-=lb,j=fa[st[top]];
    }
    REP1(i,1,top) cout<<a[st[i]];
    return 0;
}
