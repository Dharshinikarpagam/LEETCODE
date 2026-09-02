class Solution {
public:
    int findmax(vector<int> &piles)
    {
        int n=piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long func(vector<int> &piles,int mid)
    {
        int n=piles.size();
        long long  total=0;
        for(int i=0;i<n;i++)
        {
            total+=(long long)ceil((double)piles[i]/(double)mid);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=-1;
        int n=piles.size();
        int low=1;
        int high=findmax(piles);
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long totalhrs=func(piles,mid);
            if(totalhrs<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
