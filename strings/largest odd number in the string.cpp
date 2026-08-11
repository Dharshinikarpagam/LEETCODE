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
    }
};
