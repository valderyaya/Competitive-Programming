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

int pri(char c){
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}
char st[505],post[505];
string s;
void solve(){
    int i=0,j=0,top=0;
    for(;i<s.size();i++){
        if(s[i]=='(') st[++top]=s[i];
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            while(pri(st[top])>=pri(s[i])) post[j++]=st[top--];
            st[++top]=s[i];
        }else if(s[i]==')'){
            while(st[top]!='(') post[j++]=st[top--];
            --top;
        }else post[j++]=s[i];
    }
    while(top) post[j++]=st[top--];
    cout<<post<<"\n";
}
int main(){Rosario
    cin>>s;
    solve();
//    system("pause");
    return 0;
}
