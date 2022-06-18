#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

int p=0,fp,x,n,a[80005]={-1},last[80005]={};
char c;
int main(){Rosario
    cin>>n;
    REP1(i,1,n){
        cin>>c;
        if(c=='a') cin>>x,a[i]=x,last[i]=p,cout<<x<<"\n";
        else if(c=='s') fp=last[p],cout<<a[fp]<<"\n",p=last[fp],last[i]=p,a[i]=a[fp];
        else cin>>x,cout<<a[--x]<<"\n",last[i]=last[x],a[i]=a[x];
        p=i; 
    }
//    system("pause");
    return 0;
}
