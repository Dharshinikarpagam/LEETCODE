class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        string s="";
        for(int i=0;i<n;i++)
        {
           if((num[i]-'0')%2!=0)
           {
                s=num.substr(0,i+1);
           }
        }
        return s;

//optimal soln
        int n=num.size();
        for(int i=n-1;i>=0;i--)
        {
            if((num[i]-'0')%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
