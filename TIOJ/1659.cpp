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

vector<int> p;
int n;
int main(){Rosario
    for(int i=2;i<=5000;i++){
        bool c=1;
        for(int j=2;j*j<=i;j+=(j==2?1:2)){
            if(i%j==0){c=0;break;}
        }
        if(c) p.em(i);
    }
    while(cin>>n){
        cout<<"primes between 1 ~ "<<n<<": ";
        for(int i:p){
            if(i>n) break;
            cout<<i<<' ';
        }cout<<"\n";
    }
//    system("pause");
    return 0;
}
