class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int l=0;
        int r=0;
        int cnt=0;
        int minlen=INT_MAX;
        int sin=-1;
        int hash[256]={0};
        for(int i=0;i<m;i++)
        {
            hash[t[i]]++;
        }
        while(r<n)
        {
            if(hash[s[r]]>0)
            {
                cnt=cnt+1;
            }
            hash[s[r]]--;
            while(cnt==m)
            {
                if((r-l+1)<minlen)
                {
                    minlen=r-l+1;
                    sin=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)
                {
                    cnt=cnt-1;
                }
                l++;
            }
            r=r+1;
        }
    return sin==-1? "" : s.substr(sin,minlen);
    }
};
