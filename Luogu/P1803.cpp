#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

map<int,int> ma;
int main(){
    oi;
    int n,a,b,cnt=0;
    cin>>n;
    while(n--){
        cin>>a>>b;
        auto t=ma.find(b);
        if(t!=ma.end()){
            if(t->S<a) ma[b]=a;
        }else{
            ma[b]=a;
        }
    }
    a=0;
    for(auto x:ma){
        if(x.S>=a){cnt++;a=x.F;}
    }
    cout<<cnt<<"\n";
//    system("pause");
    return 0;
}
