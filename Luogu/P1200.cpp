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
    string a,b;
    cin>>a>>b;
    int x=1,y=1;
    REP(i,a.size()){x*=a[i]-64;}
    REP(i,b.size()){y*=b[i]-64;}
    if(x%47==y%47) cout<<"GO";
    else cout<<"STAY";
//   system("pause");
    return 0;
}
