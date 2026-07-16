class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int l=0,r=m-1;
        int t=0,b=n-1;
        while(t<=b && l<=r)
        {
            for(int i=l;i<=r;i++)
            {
                ans.push_back(matrix[t][i]);
            }
            t++;
            for(int i=t;i<=b;i++)
            {
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(t<=b)
            {
                for(int i=r;i>=l;i--)
                {
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }
            if(l<=r)
            {
                for(int i=b;i>=t;i--)
                {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};
##TC: O(n*m)
#SC: O(1)
