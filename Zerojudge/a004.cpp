#include<iostream>
using namespace std;
int main(){
int a;
while(cin>>a){
if(a % 4==0 && a%100!=0||a%400==0)
cout<<"閏年"<<endl;
else
cout<<"平年"<<endl;
}
}
