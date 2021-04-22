#include<bits/stdc++.h>
using namespace std;
const int maxn=4000+10 ;
int a[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        if(n==2) { printf("0\n") ; continue ; }
        sort(a+1,a+n+1) ;
        int x=lower_bound(a+1,a+n+1,(a[1]+a[n]+1)/2)-a ;
        int ans=-1 ;
        if(x!=n+1) ans=max(ans,a[n]-a[x]) ;
        if(x!=1) ans=max(ans,a[x-1]-a[1]) ;
        printf("%d\n",ans) ;
    }
}
