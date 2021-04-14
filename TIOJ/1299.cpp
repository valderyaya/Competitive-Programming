#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

string s;
int main(){Rosario
    while(cin>>s){
        int sum=0;
        REP(i,s.size()) sum+=toupper(s[i])-'A'+1;
        sum%=17;
        if(sum<3) cout<<"D\n";
        else if(sum<6) cout<<"C\n";
        else if(sum<10) cout<<"B\n";
        else if(sum<13) cout<<"A\n";
        else cout<<"SA\n";
    }
//    system("pause");
    return 0;
}
