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

int n,a,b;
set<int> s;
int main(){Rosario
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a==1){
            if(s.count(b)) cout<<"Already Exist\n";
            else s.insert(b);
        }else{
            if(s.empty()) cout<<"Empty\n";
            else{
                if(s.count(b)) s.erase(b),cout<<b<<"\n";
                else{
                    auto it=s.lower_bound(b),itl=prev(it);
                    if(it==s.begin()) cout<<*it<<"\n",s.erase(it);
                    else if(abs(*itl-b)<=abs(*it-b)) cout<<*itl<<"\n",s.erase(itl);
                    else cout<<*it<<"\n",s.erase(it);
                }
            }
        }
    }
//    system("pause");
    return 0;
}
