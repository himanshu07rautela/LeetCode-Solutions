class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // what uis the idea here boys and girls 
        // we can use maps but it will be rigrous
        int n=INT_MAX;
        for(int i=0;i<strs.size();i++){
            int n1=strs[i].size();
            n=min(n,n1);
        }
        
        int k=1;
        int l=0;
        for(int i=0;i<n;i++){
            
            char c=strs[0][i];
            
            for(int j=1;j<strs.size();j++){
                if(c!=strs[j][i]){
                    k=-1;
                    break;
                }
            }
            if(k==-1){
                break;
            }else{
                l++;
            }
            
        }
        string ans=strs[0].substr(0,l);
        return ans;
    }
};