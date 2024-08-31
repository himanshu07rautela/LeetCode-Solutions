class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1){
            return s;
        }

        int start=0;
        int end=0;
        int maxlen=1;
        for(int i=0;i<s.size();i++){
            int low=i;
            int high=i+1;
            // lets check even
            
            while(low>=0 && high<s.size() && s[low]==s[high]){
                if(high-low+1>maxlen){
                    start=low;
                    end=high;
                    maxlen=high-low+1;
                }
                low--;
                high++;
            }

            low=i;
            high=i;
            while(low>=0 && high<s.size() && s[low]==s[high]){
                if(high-low+1>maxlen){
                    start=low;
                    end=high;
                      maxlen=high-low+1;
                }
                low--;
                high++;
            }
        }
        string ans=s.substr(start,end-start+1);
        return ans;

    }
};