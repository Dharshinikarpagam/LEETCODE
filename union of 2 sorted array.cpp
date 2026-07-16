1) APPROACH 
using map ds:

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        map<int,int> mpp;
        vector<int> arr;
        int n=a.size();
        int m=b.size();
        for(int i=0;i<n;i++)
        {
            mpp[a[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            mpp[b[i]]++;
        }
        for(auto it :mpp)
        {
            arr.push_back(it.first);
        }
        return arr;
    }
};

2) using set ds :
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> st;
        int n=a.size();
        int m=b.size();
        for(int i=0;i<n;i++)
        {
            st.insert(a[i]);
        }
        for(int i=0;i<m;i++)
        {
            st.insert(b[i]);
        }
        vector<int> arr(st.begin(),st.end());
        return arr;
    }
};
3) optimal approach
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> arr;
        int n=a.size();
        int m=b.size();
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(a[i]<b[j])
            {
                if(arr.empty()||arr.back()!=a[i])
                {
                    arr.push_back(a[i]);
                }
                i++;
            }
            else if(b[j]<a[i])
            {
                if(arr.empty()|| arr.back()!=b[j])
                {
                    arr.push_back(b[j]);
                }
                j++;
            }
            else{
                if(arr.empty() || arr.back()!=a[i])
                {
                    arr.push_back(a[i]);
                }
                i++,j++;
            }
        }
        while(i<n)
        {
            if(arr.empty() || arr.back()!=a[i])
            {
                arr.push_back(a[i]);
            }
            i++;
        }
        while(j<m)
        {
            if(arr.empty() || arr.back()!=b[j])
            {
                arr.push_back(b[j]);
            }
            j++;
        }
        return arr;
    }
};
