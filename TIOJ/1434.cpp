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
#define lb(x) (x&-x)

inline int read() {
    int ret=0,f=1;char ch=getchar_unlocked();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
    while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
    return ret*f;
}
int n,m,now,c;
struct qq{
    int a,b;
    bool operator<(const qq &x)const{
        return b<x.b;
    }
}q[1005];
int main(){//Rosario
    n=read();
    while(n--){
        m=read();
        REP(i,m) q[i].a=read(),q[i].b=read();
        sort(q,q+m);
        now=0,c=1;
        REP(i,m){
            now+=q[i].a;
            if(now>q[i].b){c=0;break;}
        }puts(c?"schedulable":"unschedulable");
    }
//    system("pause");
    return 0;
}
