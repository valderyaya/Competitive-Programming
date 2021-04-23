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
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&(-x)) 

int n,m;
inline int op(int a,int q){
    int an=1;
    for(;q;q>>=1,a*=a)
        if(q&1) an*=a;
    return an;
}
inline int cal1(){
    int ret=0,c=log10(m)+1,t=m;
    for(;t;ret+=op(t%10,c),t/=10);
    return ret;
}
inline int cal2(){
    int ret=m%10,t=m/10,a=n;
    for(;t;ret+=a*(t%10),a*=n,t/=10);
    return ret;
}
int main(){Rosario
    while(cin>>n>>m){
    if(cal1()==cal2()) cout<<"YES\n";
    else cout<<"NO\n";}
//    system("pause");
    return 0;
}
