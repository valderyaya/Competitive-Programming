//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
//#define line cout<<"-------------------------------\n";

string s;
int re(){
    for(int i=s.size()-1;;i--) if(isdigit(s[i])) return (s[i]^48);
}
int main(){Rosario
    cin>>s;
    if(s.substr(0,3)!="MDA") cout<<"1 1 1 1 1\n";
    else {
        int x=re();
        cout<<(x==1||x==9?1:0)<<" ";
        cout<<(x==2||x==8?1:0)<<" ";
        cout<<(x==3||x==7?1:0)<<" ";
        cout<<(x==4||x==6?1:0)<<" ";
        cout<<(x==5||x==0?1:0)<<"\n";
    }
//    system("pause");
    return 0;
}
