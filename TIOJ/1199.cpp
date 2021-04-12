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

int md;
int power(int a,int n){
    int r=1;
    for(;n;n>>=1,a=a*a%md) if(n&1) r=r*a%md;
    return r%md;
}
int c,n,x;
int main(){Rosario
    while(cin>>x>>n>>md,x||n||md){c=0;
        REP(i,md) if((i||n)&&power(i,n)==x) c++;
        cout<<c<<"\n";
    }
//    system("pause");
    return 0;
}
