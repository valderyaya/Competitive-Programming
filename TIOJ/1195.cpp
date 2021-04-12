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

int n,sum=0;
string s;
int main(){Rosario
    cin>>n;
    while(n--){
        cin>>s;
        if(s[2]==s[3]&&s[3]==s[4]&&s[4]==s[5]) sum+=2000;
        else if(s[2]==s[3]&&s[4]==s[5]) sum+=1500;
        else sum+=1000;
    }
    cout<<sum<<"\n";
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

