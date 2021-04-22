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
#define lb(x) (x&-x)

int t,k;
int f(int n){
    if(n==1) return 0;
    return (f(n-1)+k)%n;
}
int main(){Rosario
    cin>>t;
    int n;
    REP1(i,1,t){
        cin>>n>>k;
        cout<<"Case "<<i<<": "<<f(n)+1<<"\n";
    }
//    system("pause");
    return 0;
}
