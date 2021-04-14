//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

inline int read(){
    int re=0;char c=getchar();
    while(c<'0'||c>'9'){c=getchar();}
    while(c>='0'&&c<='9'){re=re*10+c-'0';c=getchar();}
    return re;
}
int n,m,a[101],s;
bool dp[100001];
int main(){
    //Rosario
    cin>>n>>m;
    while(n--){
        memset(dp,0,sizeof(dp));dp[0]=1;s=0;
        REP(i,m) a[i]=read(),s+=a[i];
        if(s&1){puts("No");continue;}
        REP(i,m){
            for(int j=s;j>=a[i];j--) dp[j]|=dp[j-a[i]];
        }
        if(dp[s>>1]) puts("Yes");
        else puts("No");
    }
//    system("pause");
    return 0;
}
