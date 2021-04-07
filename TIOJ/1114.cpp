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

map<string,pii> m;
string s;
int main(){Rosario
    while(getline(cin,s)){m.clear();
        string x="";
        for(auto &i:s)
            if(isalpha(i)) x.push_back(tolower(i));
            else if(x!="") m[x].F++,x="";
        if(x!="") m[x].F++; 
        x=""; getline(cin,s);
        for(auto &i:s)
            if(isalpha(i)) x.push_back(tolower(i));
            else if(x!="") m[x].S++,x="";
        if(x!="")m[x].S++;
        bool c=0;
        for(auto &i:m) if(i.S.F>1&&i.S.S>1) c=1,cout<<i.F<<"\n";
        if(!c) cout<<"<NONE>\n";
        cout<<"\n";
    }
    return 0;
}
