class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we can use array to store frequencies
        vector<int>freq(128,0);
        int ans=0;
        int i=0;
        int j=0;
        while(i<=j && i<s.size() && j<s.size()){
            int num=s[j];
            
           if(freq[num]==0){
                int len=j-i+1;
                ans=max(ans,len);
                freq[num]++;
                j++;
            }else{
                freq[s[i]]--;
                i++;
            }
        }
        return ans;
        
    }
};