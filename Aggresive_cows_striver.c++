class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int n=pos.size();

        int s=1;
        int e=(pos[n-1]-pos[0])/(m-1);
        int ans=1;
        while(s<=e){
            int mid=(s+(e-s)/2);
            if(ispossible(pos,m,mid)){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
    bool ispossible(vector<int>&pos,int m , int mid){
        int count=1;
        int last=pos[0];
        int n=pos.size();
        for(int i=1;i<pos.size();i++){
            if(pos[i]-last>=mid){
                last=pos[i];
                count++;
            }
            if(count==m){
                return true;
            }
        }
        return false;
    }
};