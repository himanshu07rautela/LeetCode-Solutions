class Solution {
public:
    string reverseWords(string s) {
        // we're just gonna use stack
        stack<string>st;
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
            }else{
                vector<char>v;
                while(i < s.size() && s[i] != ' '){
                    v.push_back(s[i]);
                    i++;
                }
                string s1(v.begin(),v.end());
                st.push(s1);
            }
        }
        string ans = ""; // Initialize the string `ans`
        if (!st.empty()) { // Check if stack is not empty to avoid accessing empty stack
            ans += st.top();
            st.pop();
        }
        
        while(!st.empty()){
            string s1=st.top();
            st.pop();
            
            ans+=' ';
            ans+=s1;
            
        }
        return ans;
    }
};