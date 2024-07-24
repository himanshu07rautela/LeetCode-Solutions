class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        // if they are equal then they should remain in same relative order
        return a.second<b.second;//ascending values and > left then descending value
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>ans;
        // we already have a mapping and now we will juts traverse it one by one
         for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            int mappedNumber = 0;
            int place = 1;  // To handle digit positions correctly
            
            if(n == 0) {
                mappedNumber = mapping[0];
            } else {
                while(n != 0) {
                    int digit = n % 10;
                    mappedNumber += mapping[digit] * place;
                    place *= 10;
                    n /= 10;
                }
            }
            
            ans.push_back(make_pair(nums[i], mappedNumber));
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int>gans;
        for(int i=0;i<ans.size();i++){
            gans.push_back(ans[i].first);
        }
        return gans;
    }
};