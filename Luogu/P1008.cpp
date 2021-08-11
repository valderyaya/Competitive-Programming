#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
//#define pb push_back
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair


int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s="123456789";
    do{
        int a=stoi(s.substr(0,3)),b=stoi(s.substr(3,3)),c=stoi(s.substr(6,3));
        if(a*2==b&&a*3==c) cout<<a<<' '<<b<<' '<<c<<"\n";
    }while(next_permutation(ALL(s)));
//    system("pause");
    return 0;
}
