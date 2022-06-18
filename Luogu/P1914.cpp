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


int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    REP(i,s.size()){
        if(s[i]+n>'z'){putchar('a'+(s[i]-'a'+n)%26);}
        else putchar(s[i]+n);
    }
//    system("pause");
    return 0;
}
