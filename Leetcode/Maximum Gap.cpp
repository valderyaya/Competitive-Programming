class Solution {
public:
    vector<int> a,b;
    int n;
    void counting_sort(int p){
        int cnt[10]={};
        b.resize(n+1);
        for(int i=0;i<n;++i) ++cnt[(a[i]/p)%10];
        for(int i=1;i<10;++i) cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;--i) b[cnt[(a[i]/p)%10]--]=a[i];
        for(int i=0;i<n;++i) a[i]=b[i+1];
    }
    void radix_sort(){
        for(int i=0,j=1;i<9;++i,j*=10)
            counting_sort(j);
    }
    int maximumGap(vector<int>& nums) {
        a=nums;
        n=a.size();
        radix_sort();
        int mx=0;
        for(int i=1;i<n;++i) mx=max(mx,a[i]-a[i-1]);
        return mx;
    }
};
