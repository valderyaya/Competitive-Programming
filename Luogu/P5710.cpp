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

int n;
bool c1(){return n%2==0;}
bool c2(){return n>4&&n<=12;}
int main(){//Rosario
    cin>>n;
    cout<<(c1()&&c2()?1:0)<<' ';
    cout<<(c1()||c2()?1:0)<<' ';
    cout<<(c1()^c2()?1:0)<<' ';
    cout<<(c1()==0&&c2()==0?1:0);
//    system("pause");
    return 0;
}
