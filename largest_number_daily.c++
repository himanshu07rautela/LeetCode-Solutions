class Solution {
public:
    // define a custom sort
    static bool cmp(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);

    // Compare concatenated results
    return s1 + s2 > s2 + s1;  // We want s1 + s2 to be greater for descending order
}
   bool check(string ans){
     for(int i=0;i<ans.size();i++){
        if(ans[i]!='0'){
            return false;
        }
     }
     return true;
   }
   
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        
        string ans;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            ans+=s;
        }
        if(check(ans)){
            return "0";
        }
        return ans;
    }
};