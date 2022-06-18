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
#define wait system("pause");

int n,x,c;
map<string,int> m;
string s;
int main(){Rosario
    cin>>n;
    while(n--){
        cin>>x;
        if(x==1){
            cin>>s>>c;
            m[s]=c;
            cout<<"OK\n";
        }else if(x==2){
            cin>>s;
            if(m.count(s)) cout<<m[s]<<"\n";
            else cout<<"Not found\n";
        }else if(x==3){
            cin>>s;
            if(m.count(s)) m.erase(s),cout<<"Deleted successfully\n";
            else cout<<"Not found\n";
        }else cout<<m.size()<<"\n";
    }
//    system("pause");
    return 0;
}
