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

2)
    class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLen=0,n=s.length();
        if(n==0) return 0;
        if(n==1) return 1;
        unordered_map<char,int> mpp;
        while(r<n){
            if(mpp[s[r]]==0){
                mpp[s[r]]=1;
                r++;
                maxLen = max(maxLen, r-l);
            }
            else{
                maxLen=max(maxLen,r-l);
                mpp[s[l]]=0;
                l++;
            }
        }
        return maxLen;

    }
};
