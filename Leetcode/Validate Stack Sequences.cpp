class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> st;
        int j=0,n=popped.size();
        for(int &i:pushed){
            st.push_back(i);
            if(i==popped[j])
                while(!st.empty()&&st.back()==popped[j]) ++j, st.pop_back();
        }
        return st.empty()&&j==n;
    }
};
