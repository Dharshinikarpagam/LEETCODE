//same lis code such that the change is checkstr function to see if the arr[i] is the predecessor of the arr[j]
class Solution {
public:
    static bool comp(string &a,string &b)
    {
        return a.size()<b.size();
    }
    bool checkstr(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1) return false;
        int fir=0;
        int sec=0;
        while(fir<s1.size())
        {
            if(sec<s2.size() && s1[fir]==s2[sec])
            {
                fir++,sec++;
            }
            else{
                fir++;
            }
        }
        if(fir==s1.size() && sec==s2.size())
        {
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(checkstr(words[i],words[j]) && 1+dp[j]>dp[i] )
                {
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
            }
        }
        return maxi;
    
    }
};
