//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
#include "lib1860.h"
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

int n,mx=0,m,t;
int main(){//Rosario
    t=Start_The_Loli_Dream();
    while(t--){
        mx=0;
        n=Count_How_Many_Loli();
        m=(int)round((double)n*0.36787944117);
        n-=m;
        while(m--) mx=max(mx,Get_Loli_Moeness());
        bool ck=1;
        while(n--){
            int x=Get_Loli_Moeness();
            if(x>mx){ck=0; You_Choose_This_Loli(); break;}
        }
        if(ck) You_Choose_This_Loli();
    }
    return 0;
}
