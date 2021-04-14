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
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)


int n,m;
int main(){Rosario
    cin>>n;
    while(n--){
        cin>>m;
        int a=0,b=0;
        for(int i=1;i*i<m;i++){
            if(m%i==0){
                a+=2;
                b+=i+m/i;
            }
        }
        if(sqrt(m)==int(sqrt(m))) a++,b+=sqrt(m);
        cout<<a*b<<"\n";
    }
//    system("pause");
    return 0;
}
