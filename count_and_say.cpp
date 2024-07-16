class Solution {
public:
    // recursive solution;
    
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string ans="";
        string ans1=countAndSay(n-1);
        char st=ans1[0];
        int count=0;
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]==st){
                count++;
            }else{
                ans+='0'+count;
                ans+=st;
                st=ans1[i];
                count=1;
            }
        }
        ans+='0'+count;
        ans+=st;
        // we were not kind of appending the last count and last character
        return ans;
        
    }
};