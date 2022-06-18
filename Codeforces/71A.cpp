#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    int n;
    string a;
    cin>>n;
    while(n--){
        cin>>a;
        if(a.length()>10)
            cout<<a[0]<<a.length()-2<<a[a.length()-1]<<endl;
        else
            cout<<a<<endl;
    }
    return 0;
}
