class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
       if(n==0) return 0;
       if(n==1) return 1;
       map<char,int> mp;
       int left=0;
       int right=0;
       int maxlength=0;
       while(right<n)
       {
        if(mp[s[right]]==0)
        {
            mp[s[right]]++;
            right++;
        }
        else{
            maxlength=max(maxlength,right-left);
            if(mp[s[right]]==1){
                mp.erase(s[left]);
                left++;
            }
        }
       }
       maxlength=max(maxlength,right-left);
       return maxlength;

    }
};
