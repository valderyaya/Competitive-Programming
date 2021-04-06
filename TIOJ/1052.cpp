#include<bits/stdc++.h>
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
#define lb(x) (x&-x)

int t,cnt=-1,cnt1=0,cnt2=0;
string s,str;
stringstream ss;
int main(){Rosario
    cin>>t;
    while(t--){
        while(getline(cin,s)){
            if(s=="=====") break;
            cnt++;cnt2+=s.size();
            ss.str("");ss.clear();ss<<s;
            while(ss>>s){cnt1++;}
        }cout<<cnt<<' '<<cnt1<<' '<<cnt2<<"\n";
        cnt=cnt1=cnt2=0;
    }
//    system("pause");
    return 0;
}
