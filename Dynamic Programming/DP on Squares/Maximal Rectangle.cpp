class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int maxArea = 0;
        int n = heights.size();
        for(int i = 0;i<=n;i++){
            while(!stk.empty() && (i==n || heights[stk.top()]>=heights[i])){
                int ht = heights[stk.top()];
                stk.pop();
                int width;
                if(stk.empty())width = i;
                else width = i- stk.top() -1;
                maxArea = max(maxArea, width*ht);
            }
            stk.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();

        int maxRectangle = 0;
        
        vector<int>rowarr(col,0);
        for(int i = 0; i<rows;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j]=='1')rowarr[j]++;
                else rowarr[j] = 0;
            }
            maxRectangle = max(maxRectangle,largestRectangleArea(rowarr));
        }
        return maxRectangle;
    }
};
