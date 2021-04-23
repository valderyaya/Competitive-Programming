//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

string s;
int pre=0,p=0,m=0;
int main(){Rosario
    cin>>s;
    if(s[s.size()-1]=='?'){
        string tmp=s;tmp.pop_back();
        int a=stoi(tmp);
        REP(i,9)
            if((a-i*2)%7==0) cout<<a<<i<<"\n";
    }else{
        bool c=1;
        REP(i,s.size()){
            if(c&&isdigit(s[i])) pre=pre*10+s[i]-'0';
            if(!c) m=m*10+s[i]-'0';
            if(s[i]=='?'){c=0; p=s.size()-i-1;}
        }
        REP(i,10){
            int x=pre*pow(10,p)+i*pow(10,p-1)+m/10;
            if((x-2*(m%10))%7==0) cout<<x<<m%10<<"\n";
        }
    }
    return 0;
}
