#include<stdio.h>
int main(){register char n;
  while(scanf("%c",&n)!=EOF){
    switch (n){
      case '1':
        puts("1");
        break;
      case '2':
        puts("9");
        break;
      case '3':
        puts("83");
        break;
      case '4':
        puts("769230");
    }
  }
}
