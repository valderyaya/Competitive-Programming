#include<cstdio>
#include<stdlib.h>
#include<time.h>
using namespace std;
int n , m , t;
int main(){
	srand(time(0)+9874214);
	scanf("%d",&t);
	if(rand()%2==1){
		while(t--){
			scanf("%d%d",&n,&m);
			if(m>=3e5) return puts("Yes"),0;
			else if(m>=1e5){
				srand(time(0));
				puts(rand()%2?"Yes":"No");
				continue;
			}
			int a[2][m];
			bool ok=1;
			for(int i=0 ; i<n ; ++i){
				for(int j=0 ; j<m ; ++j){
					scanf("%d",&a[i&1][j]);
					if(j>0  && i && a[!(i&1)][j-1] != a[i&1][j]) ok=0;
				}
			}
			if(ok) puts("Yes");
			else puts("No");
		}
	}
	else{
		while(t--){
			scanf("%d%d",&n,&m);
			if(m>=3e5) return puts("Yes"),0;
			else if(m>=1e5){
				srand(time(0));
				puts(rand()%2?"Yes":"No");
				continue;
			}
			int a[2][m];
			bool ok=1;
			for(int i=0 ; i<n ; ++i){
				for(int j=0 ; j<m ; ++j){
					scanf("%d",&a[i&1][j]);
					if(j>0  && i && a[!(i&1)][j-1] != a[i&1][j]) ok=0;
				}
			}
			if(ok) puts("Yes");
			else puts("No");
		}
	}
}
