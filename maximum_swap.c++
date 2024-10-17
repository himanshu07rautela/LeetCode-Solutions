    class Solution {
    public:
        int maximumSwap(int num) {
            // kind of reminds me where we had to keep all 1's in on left and all the 
            
            vector<int>nums;
            stack<int>st;
            while(num!=0){
                int a=num%10;
                num=num/10;
                st.push(a);
            }
            while(!st.empty()){
                int a=st.top();
                st.pop();
                nums.push_back(a);
            }
            vector<int>maxi(nums.size());
            maxi[nums.size()-1]=nums.size()-1;
            int maxind=nums.size()-1;
            int maxnum=nums[nums.size()-1];
            for(int i=nums.size()-2;i>=0;i--){
                if(nums[i]>maxnum){
                    maxnum=nums[i];
                    maxi[i]=i;
                    maxind=i;
                }else{
                    maxi[i]=maxind;
                }
            }
            for(int i=0;i<nums.size();i++){
                if(i!=maxi[i] && nums[i]!=nums[maxi[i]]){
                    swap(nums[i],nums[maxi[i]]);
                    break;
                }
            }
            int ans=0;
            for(int i=0;i<nums.size();i++){
                ans=ans*10+nums[i];
            }
            return ans;


        }
    };