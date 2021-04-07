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


char a,b,c,d;
int e[4];
int main(){Rosario
    while(cin>>a>>b>>c>>d){
        if(a=='b') cout<<"X, ";
        else{
            if(b=='a'&&c=='a'&&d=='a') cout<<"Y, ";
            else{
                if(d!='a') cout<<'A';
                if(b!='a') cout<<'B';
                if(c!='a') cout<<'C';
                cout<<", ";
            }
        }
        if(b=='b') cout<<"X, ";
        else{
            if(a=='a'&&c=='a'&&d=='a') cout<<"Y, ";
            else{
                if(a!='a') cout<<'A';
                if(c!='a') cout<<'B';
                if(d!='a') cout<<'C';
                cout<<", ";
            }
        }
        if(c=='b') cout<<"X, ";
        else{
            if(a=='a'&&b=='a'&&d=='a') cout<<"Y, ";
            else{
                if(b!='a') cout<<'A';
                if(d!='a') cout<<'B';
                if(a!='a') cout<<'C';
                cout<<", ";
            }
        }
        if(d=='b') cout<<"X ";
        else{
            if(a=='a'&&c=='a'&&b=='a') cout<<"Y ";
            else{
                if(c!='a') cout<<'A';
                if(a!='a') cout<<'B';
                if(b!='a') cout<<'C';
            }
        }
        cout<<"\n";
    }
    return 0;
}
