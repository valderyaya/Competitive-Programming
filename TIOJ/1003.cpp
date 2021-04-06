#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())

int fun(int x){
    if (x==0) return 1;
    else {
        return fun(x-1)+x ;}
}
int main(){
    int a;
    while(cin>>a){
        cout<<fun(a)<<endl;
    }
//    system("pause");
    return 0;
}
