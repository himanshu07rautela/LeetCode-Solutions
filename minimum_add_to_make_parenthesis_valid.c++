class Solution {
public:
    int minAddToMakeValid(string s) {
        // we can just add  some parenthesis 
        int count=0;
        stack<int>st;
        if(s.size()==0){
            return 0;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    count++;
                }else{
                    st.pop();
                }
            }

        }
        if(st.empty()){
            return count;
        }else{
            return st.size()+count;
        }
    }
};