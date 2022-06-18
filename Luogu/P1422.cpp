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
    double ans=0;
    int n;
    cin>>n;
    if(n>400) ans+=(n-400)*0.5663,n=400;
    if(n>150) ans+=(n-150)*0.4663,n=150;
    if(n>0&&n<151) ans+=n*0.4463;
    cout<<fixed<<setprecision(1)<<ans;
//   system("pause");
    return 0;
}
