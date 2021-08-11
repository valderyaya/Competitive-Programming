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

char c,cc;
int f=1,x=0,now=1,sum=0,k=0,ck;
int main(){Rosario
    while(cin>>c){
        if(c=='-') sum+=now*f*x,f=-1,ck=0,x=0;
        else if(c=='+') sum+=now*f*x,x=0,f=1,ck=0;
        else if(c=='=') sum+=now*f*x,f=1,now=-1,ck=0,x=0;
        if(isalpha(c)){
            if(ck) k+=now*f*x,x=0;
            else k+=now*f;
            cc=c,ck=0;
        }
        if(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),ck++;
    }
    sum+=now*f*x;
    double res=double(-sum)/k;
    if(res==-0) res=0;
    cout<<cc<<'='<<fixed<<setprecision(3)<<res<<"\n";
//    system("pause");
    return 0;
}
