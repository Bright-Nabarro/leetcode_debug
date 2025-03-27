#include "../cvn.hpp"
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector left_top = vector(m, vector(n, 0));
        vector right_btm = vector(m, vector(n, 0));

        if (n > 1)
        {
            for (int i = 1; i < m; ++i)
            {
                left_top[i][1] = 1;
            }
			for (int i = 0; i < m-1; ++i)
			{
				right_btm[i][n-2] = 1;
			}
        }
        if (m > 1)
        {
            for (int i = 1; i < n; ++i)
            {
                left_top[1][i] = 1;
            }

			for (int i = 0; i < n-1; ++i)
			{
				right_btm[m-2][i] = 1;
			}
        }
        
        for (int i = 2; i < m; ++i)
        {
            for (int j = 2; j < n; ++j)
            {
                left_top[i][j] = left_top[i-1][j-1];
                if (grid[i-1][j-1] != grid[i-2][j-2])
                    left_top[i][j] += 1;
            }
        }
		P2D(left_top);
		for (int i = m-3; i >= 0; --i)
		{
			for (int j = n-3; j >= 0; --j)
			{
				right_btm[i][j] = right_btm[i+1][j+1];
				if (grid[i+1][j+1] != grid[i+2][j+2])
					right_btm[i][j] += 1;
			}
		}
		P2D(right_btm);

        for (int i = 0; i < m; ++i)       
        {
            for (int j = 0; j < n; ++j)
            {
                grid[i][j] = abs(left_top[i][j] - right_btm[i][j]);
            }
        }
		P2D(grid);
        return grid;
    }
};

int main()
{
	Ss;
	VV list {{1,2,3},{5,6,7}};
	s.differenceOfDistinctValues(list);
}
