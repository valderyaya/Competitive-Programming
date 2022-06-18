#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)

int main(){
    int a,b;
    cin>>a>>b;
    while(b--){
        if(a%10)
            a--;
        else
            a/=10;
    }
    cout<<a;
 //   system("pause");
    return 0;
}
