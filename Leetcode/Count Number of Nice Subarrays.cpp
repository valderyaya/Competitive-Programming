class Solution {
public:
    int l[50001],r[50001];
    long long ans=0;
    int numberOfSubarrays(vector<int>& v, int k) {
        for(int i=0,j=0;i<v.size();++i)
            if(v[i]%2) l[i]=1+j,j=0;
            else ++j;
        for(int i=v.size()-1,j=0;i>=0;--i)
            if(v[i]%2) r[i]=1+j, j=0;
            else ++j;
        for(int i=0,j=0,cnt=0;j<v.size();++j){
            if(v[j]%2) ++cnt;
            else continue;
            while(cnt>k){
                if(v[i++]%2) --cnt; 
            }
            while(cnt==k&&v[i]%2==0) ++i;
            //cout<<i<<' '<<j<<endl;
            if(cnt==k) ans+=l[i]*r[j];
        }
        return ans;
    }
};
