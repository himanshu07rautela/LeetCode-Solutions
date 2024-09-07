class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we can use the upper bound;
        int count=0;
        
        int i=0;
        int j=0;
        int med1=0;
        int med2=0;
        for(int count=0;count<=(nums1.size()+nums2.size())/2;count++){
            med2=med1;
            if(i<nums1.size() && j<nums2.size()){
                if(nums1[i]<nums2[j]){
                    
                    med1=nums1[i];
                    i++;
                }else{
                    
                    med1=nums2[j];
                    j++;
                }

            }else if(i<nums1.size()){
               
                med1=nums1[i];
                 i++;
            }else{
               
                med1=nums2[j];
                 j++;
            }

        }
        if((nums1.size()+nums2.size())%2==0){
            return (static_cast<double>(med2)+static_cast<double>(med1))/2.0;
        }else{
            return static_cast<double>(med1);
        }
    }
};