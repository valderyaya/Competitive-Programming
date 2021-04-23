//#pragma GCC optimize("Ofast")
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
//#define lb(x) (x&-x)

short a[3][3];
int main(){//Rosario
    for(short i=0;i<3;i++) for(short j=0;j<3;j++) scanf("%d",&a[i][j]);
    putchar('*');
    for(short k=2;k<=9;k++){
        bool c=1;
        for(short i=0;i<3;i++)
            for(short j=0;j<3;j++){
                if(a[i][j]==k){
                    if(i>0&&a[i-1][j]==k-1) putchar('D'),c=0;
                    else if(i<2&&a[i+1][j]==k-1) putchar('U'),c=0;
                    else if(j>0&&a[i][j-1]==k-1) putchar('R'),c=0;
                    else if(j<2&&a[i][j+1]==k-1) putchar('L'),c=0;
                }
            }
        if(c) break;
    }
//    system("pause");
    return 0;
}
