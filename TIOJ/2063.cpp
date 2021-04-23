//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace std;
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

const int z=3e6+5;
int a,n,l,r,q,zero[z],neg[z];
long double lg[z];
int main(){//Rosario
    scanf("%d%d",&n,&q);
    REP1(i,1,n){
        zero[i]=zero[i-1],neg[i]=neg[i-1],lg[i]=lg[i-1];
        scanf("%d",&a);
        if(a==0) zero[i]++;
        else if(a<0) neg[i]++,lg[i]+=log10l(-a);
        else lg[i]+=log10l(a);
    }
    while(q--){
        scanf("%d%d",&l,&r);
        if(zero[l]!=zero[r]) puts("0");
        else{
            if((neg[r]-neg[l])%2) putchar(45);
            printf("%.10LfE+%1.Lf\n",powl(10,lg[r]-lg[l]-floorl(lg[r]-lg[l])),floorl(lg[r]-lg[l]));
        }
    }
//    system("pause");
    return 0;
}
