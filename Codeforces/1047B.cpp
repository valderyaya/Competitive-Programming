#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)

int main(){
    int a,x,y,an=0;
    cin>>a;
    while(a--){
        cin>>x>>y;
        an=max(an,x+y);
    }
    cout<<an<<endl;
//    system("pause");
    return 0;
}
