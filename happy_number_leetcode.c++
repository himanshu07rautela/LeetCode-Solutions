class Solution {
public:
    bool isHappy(int n) {
        // what we do we do it with full focus
        unordered_map<int,bool>mp;
        //this will contain the info about all the numbers that we had encountered 
        // lets say we go round back to some number n1 , then it means its loop so , i guess its done
        while(mp[n]!=true){
            mp[n]=true;
            int k=0;
            while(n!=0){
                int num=n%10;
                k=k+(num*num);
                n=n/10;
            }
            n=k;
            if(n==1){
                return true;
            }
        }
        return false;
        
    }
};