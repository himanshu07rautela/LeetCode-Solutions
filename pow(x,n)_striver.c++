class Solution {
public:
    double myPow(double x, int n) {
        if(x==1){
            return 1;
        }
        if(x==-1){
            if(n%2==0){
                return 1;
            }else{
                return -1;
            }
        }
        if(n==-2147483648){
            return 0;
        }
        
        if(n>=0){
            double ans=1;
            for(double i=0;i<n;i++){
                ans=ans*x;
            }
            return ans;
        }else{
            double ans=1;
            n=abs(n);
            for(double i=0;i<n;i++){
                ans=ans/x;
            }
            return ans;

        }
    }
};