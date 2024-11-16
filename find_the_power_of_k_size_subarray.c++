class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        bool prev;
        bool isgood=true;
        for(int i=0;i<k-1;i++){
            if(nums[i+1]-nums[i]!=1){
                isgood=false;
                break;
            }

        }
        if(isgood){
            ans.push_back(nums[k-1]);
        }else{
            ans.push_back(-1);
        }
        int l=1;
        int r=k;
        while(r<nums.size()){
            if(isgood){
                if(nums[r]-nums[l]==k-1){
                    ans.push_back(nums[r]);

                }else{
                    ans.push_back(-1);
                    isgood=false;
                }
                l++;
                r++;
            }else{
                bool check=true;
                for(int i=l;i<=r-1;i++){
                    if(nums[i+1]-nums[i]!=1){
                        check=false;
                        break;
                    }

                }
                if(check){
                    isgood=true;
                    ans.push_back(nums[r]);
                }else{
                    ans.push_back(-1);
                }
                l++;
                r++;
            }
        }
        return ans;

    }
};