#include "lib1865.h"
int main(){
    short n = GetN();
    for(short i = 0; i < n-1 ; i++){
        for(short j=i;j>=0;j--) Magic_Operate(j);
    }
    End();
    return 0;
}
