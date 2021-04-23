#include "lib1926.h"
#include<bits/stdc++.h>
#define ll long long 
#define int ll
int n,m,l,r,y;
int check(int x){
    int res=0;
    for(int i=1;i<n;++i)
        if(Oshietekudasai(i,x,res,x)) res=i;
    return res;
}
signed main(){
    Init(&n,&m);
    for(l=0,r=m-1;l<r;){
        int mid=l+r>>1;
        y=check(mid);
        if(mid==0){
            if(Oshietekudasai(y,mid,y,mid+1)) Report(y,mid);
            else l=mid+1;
        }else{
            if(Oshietekudasai(y,mid,y,mid-1)&&Oshietekudasai(y,mid,y,mid+1)) Report(y,mid);
            if(Oshietekudasai(y,mid,y,mid+1)) r=mid;
            else l=mid+1;
        }
    }
    y=check(l);
    Report(y,l);
}
