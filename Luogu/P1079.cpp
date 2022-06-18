//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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
//#define lb(x) (x&-x)

char ma[26][26],c;
string k,str;
int main(){Rosario
    REP1(i,1,25) ma[0][i]='z'-i+1;
    REP(i,26) ma[i][0]='a'+i;
    for(int i=1;i<26;i++)
        for(int j=1;j<26;j++) ma[i][j]=ma[i-1][j-1];
    cin>>k>>str;
    while(k.size()<str.size()) k+=k;
    REP(i,str.size()){
        c=ma[tolower(str[i])-'a'][tolower(k[i])-'a'];
        putchar((str[i]>='A'&&str[i]<='Z'?toupper(c):c));
    }
//    system("pause");
    return 0;
}
