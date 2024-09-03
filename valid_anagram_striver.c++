class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            int a=s[i]-'a';
            freq[a]++;
        }
        for(int i=0;i<t.size();i++){
            int a=t[i]-'a';
            freq[a]--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};