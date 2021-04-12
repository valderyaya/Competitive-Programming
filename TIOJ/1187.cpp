#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef pair<int,int> pii;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
//#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair
//#define ios_base::sync_with_stdio(false),cin.tie(0);

// int power(int a,int n){
//     int ans=1;
//     for(;n;n>>=1,a=a*a)
//         if(n&1)
//             ans=ans*a;
//     return ans;
// }

int main(){
    int n;
    while(cin>>n,n){
        int an[n];
        double sum=0;
        REP(i,n) cin>>an[i];
        sort(an,an+n);
        REP1(i,1,n-2) sum+=an[i];
        sum/=n-2;
        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
//    system("pause");
    return 0;
}
