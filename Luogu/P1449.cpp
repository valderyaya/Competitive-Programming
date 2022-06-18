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

stack<int> st;
char c;
int x,a,b;
int main(){Rosario
    while(c=getchar(),c!='@'){
        if(c=='.') st.emplace(x),x=0;
        else if(isdigit(c)) x=(x<<3)+(x<<1)+(c^48);
        else{
            b=st.top(); st.pop(); a=st.top(); st.pop();
            if(c=='-') st.emplace(a-b);
            else if(c=='+') st.emplace(a+b);
            else if(c=='*') st.emplace(a*b);
            else if(c=='/') st.emplace(a/b);
            else if(c=='%') st.emplace(a%b); 
        }
    }
    cout<<st.top()<<"\n";
//    system("pause");
    return 0;
}
