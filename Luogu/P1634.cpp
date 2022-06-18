
#include <iostream>
using namespace std;
uint64_t k,x;
uint64_t pow(uint64_t a,uint64_t n){
    uint64_t res=1;
    for(;n;n>>=1,a*=a) if(n&1) res*=a;
    return res;
}
int main() {
    cin>>k>>x;
    cout<<pow(k+1,x)<<"\n";
}
