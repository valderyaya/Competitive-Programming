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


ll k,n,tmp[]={11,111,1111,11111,111111,1111111,11111111,111111111,1111111111,11111111111,111111111111,1111111111111};
void f(){
    for(int i=1;i<10;++i){
        if(n<=0) break;
        for(int j=1;j<10;++j){
            if(n-->0) cout<<0<<i<<j<<i+j<<"\n";
            if(n-->0) cout<<i<<0<<j<<i+j<<"\n";
            if(n-->0) cout<<i<<j<<0<<i+j<<"\n";
            if(n-->0) cout<<i<<j<<i+j<<0<<"\n";
        }
    }
}
void s(){
    for(int i=1;i<=n;++i) cout<<0<<i<<i<<"\n";
}
void t(){
    while(n>0){
        REP(i,12){
            if(n<=0) break;
            for(ll k=tmp[i],j=1,c=0;c<9&&n>0;++c,k+=tmp[i],j++) cout<<j<<k<<j+k<<"\n",n--;
        }
    }
}
int main(){//Rosario
    cin>>k>>n;
    if(k==0) f();
    else if(k==1) s();
    else t();
//    system("pause");
    return 0;
}
