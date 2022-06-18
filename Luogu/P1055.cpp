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
    char a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,t,s;
    cin>>a1>>t>>a2>>a3>>a4>>t>>a5>>a6>>a7>>a8>>a9>>t>>a10;
      s=(a1*1+a2*2+a3*3+a4*4+a5*5+a6*6+a7*7+a8*8+a9*9-'0'*45)%11+'0';
      if(s>'9') s='X';
      if(s==a10) cout<<"Right"<<endl;
      else cout<<a1<<t<<a2<<a3<<a4<<t<<a5<<a6<<a7<<a8<<a9<<t<<s<<endl;
    
//   system("pause");
    return 0;
}

