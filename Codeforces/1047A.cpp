#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(!(a%3))
        cout<<"1 1 "<<a-2;
    else
        cout<<"1 2 "<<a-3;
    return 0;
}
