#include<bits/stdc++.h>
using namespace std;

long long arr[100001],mx,price,n;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    sort(arr, arr+n);
    for(int i=0; i<n; ++i){
        long long x = arr[i] * (n-i);
        if(x > mx){
            mx = x;
            price = arr[i];
        }
    }
    cout << mx << ' ' << price << '\n';
}
