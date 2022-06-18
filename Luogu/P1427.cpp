#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
//#define pb push_back
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair


int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int a[100],n,m=0;
    while(cin>>n,n){a[m++]=n;}
    for(int i=m-1;i>=0;i--) cout<<a[i]<<' ';
//    system("pause");
    return 0;
}
