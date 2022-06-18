#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define lb(x) (x&(-x)) 

string a,b,r;
map<char,char> n,m;
int main(){
    oi;
    bool c=0;
    cin>>a>>b>>r;
    REP(i,a.size()){
        if(n.find(a[i])==n.end()) n[a[i]]=b[i];
        else{
            if(n[a[i]]!=b[i]){c=1;break;}
        }
        if(m.find(b[i])==m.end()) m[b[i]]=a[i];
        else{
            if(m[b[i]]!=a[i]){c=1;break;}
        }
    }
    if(n.size()<26||m.size()<26||c) cout<<"Failed\n";
    else{
        REP(i,r.size()) cout<<n[r[i]];
    }
//    system("pause");
    return 0;
}
