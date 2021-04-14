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

string a,b,c;
map<string,string> ma,mb;
int main(){Rosario
    while(cin>>a>>b){
        if(a=="add"){
            cin>>c;
            ma[b]=c,mb[c]=b;
        }else if(a=="chk"){
            if(b[0]=='w'){
                b=b.substr(1);
                auto it=mb.find(b);
                if(it==mb.end()) cout<<"Not found.\n";
                else cout<<it->S<<' '<<b<<"\n";
            }else{
                b=b.substr(1);
                auto it=ma.find(b);
                if(it==ma.end()) cout<<"Not found.\n";
                else cout<<b<<' '<<it->S<<"\n";
            }
        }else{
            if(b[0]=='w') ma.erase(mb[b.substr(1)]),mb.erase(b.substr(1));
            else mb.erase(ma[b.substr(1)]),ma.erase(b.substr(1));
        }
    }
//    system("pause");
    return 0;
}
