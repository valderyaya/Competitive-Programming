class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0,j=s.size();i<j;++i){
            if(s[i]==')'){
                if(!st.empty()){
                    s[st.top()]='-';
                    s[i]='-';
                    st.pop();
                }
            }else st.push(i);
        }
        int mx=0;
        for(int i=0,j=s.size();i<j;++i){
            if(s[i]=='-'){
                int c=0;
                for(;i<j&&s[i]=='-';++i,++c);
                mx=max(mx,c);
            }
        }
        return mx;
    }
};
