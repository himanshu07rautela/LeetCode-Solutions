class Solution {
public:
    int myAtoi(string s) {
        // queue ka usage hai simple sa
        // steps to the game
        // the first step is to remove spaces in first
        // and then remove the part where we encounter the first non
        // digit
        int ans=0;
        queue<char>q;
        int sa=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && sa==0){
                continue;
            }else{
                sa=1;
                q.push(s[i]);
            }
        }
        // we removed white spaces from the front
       
        int k=1;
        while(!q.empty()){
            char c=q.front();
            
            if( c=='+'||c=='-'){
                if(c=='+'){
                    k=1;
                }else{
                    k=-1;
                }
                q.pop();
                break;
            }else if((c>='0' && c<='9')){
                break;
            }else{
                break;

            }
           
        }
        // we find sign;
        
        while(!q.empty()){
            char c=q.front();
            q.pop();
            if((c>='0' && c<='9')){
                int a=c-'0';
                if (ans > (INT_MAX - a) / 10) {
                    return (k == 1) ? INT_MAX : INT_MIN;
                }
                ans=ans*10+a;
            }else{
                break;
            }
        }
        return ans*k;
    }
};