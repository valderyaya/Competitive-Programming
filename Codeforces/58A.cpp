#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<string.h>
typedef long long ll;
using namespace std;
int main(){
    char s[]={"hello"};
    char n[101];
    int ss=0;
    cin>>n;
    for(int i=0;i<strlen(n);i++){
        if(n[i]==s[ss])
            ss++;
    }
    if(ss==5)
        cout<<"YES";
    else cout<<"NO";
    return 0;
}
