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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define lb(x) (x&(-x)) 


ll a,b,c;
int main(){
    //oi;
    cin>>a>>b>>c;
    cout<<(a+a+(b-a)*(c-1))*c/2<<"\n";
//    system("pause");
    return 0;
}
