class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        if(old==color){
            return image;
        }
        int r=image.size();
        int c=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int r1=cur.first;
            int c1=cur.second;
            for(int i=0;i<4;i++)
            {
                int nr=r1+dr[i];
                int nc=c1+dc[i];
                if(nr>=0 && nr<r && nc>=0&& nc<c && image[nr][nc]==old)
                {
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};
