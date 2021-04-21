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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&(-x)) 

int n,a[100005],h[100005];
stack<int> s;
int main(){Rosario
    while(cin>>n){
        REP1(i,1,n) cin>>h[i],a[i]=0;
        REP1(i,1,n){
            while(s.size()&&h[s.top()]<h[i]) s.pop();
            a[i]+= s.empty()?i-1:i-s.top();
            s.emplace(i);
        }while(s.size()) s.pop();
        for(int i=n;i>0;i--){
            while(s.size()&&h[s.top()]<h[i]) s.pop();
            a[i]+= s.empty()?n-i:s.top()-i;
            s.emplace(i);
        }while(s.size()) s.pop();
        REP1(i,1,n) cout<<a[i]+1<<' ';
        cout<<"\n";
    }
//    system("pause");
    return 0;
}

// int power(int a,int n){
//     int ans=1;
//     for(;n;n>>=1,a*=a)
//         if(n&1)
//             ans*=a;
//     return ans;
// }

// inline int read() {
//     int ret=0,f=1;char ch=getchar_unlocked();
//     while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
//     while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
//     return ret*f;
// }

