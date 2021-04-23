#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
//#define REP1()
int main(){
    string str;
    while(cin>>str){
        REP(i,str.length()){
            str[i]-=7;
        }
        cout<<str<<endl;
    }

 //   system("pause");
    return 0;
}
