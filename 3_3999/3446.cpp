#include "../cvn.hpp"

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<int> top_left;
        vector<int> bottom_right;
        int m = grid.size();
        int n = grid[0].size();
		P2D(grid);

        for (int i = n-1; i > 0; --i)
        {
            for (int k = 0; i+k < n; ++k)
            {
                top_left.push_back(grid[k][k+i]);
            }
        }

        int limit = std::min(m,n);
        for (int i = 0; i < m; ++i)
        {
            for (int k = 0; k + i < limit; ++k)
            {
                bottom_right.push_back(grid[i+k][k]);
            }
        }
        
        ranges::sort(top_left);
        ranges::sort(bottom_right, greater{});
		P1D(top_left);
		P1D(bottom_right);

        int counter = 0;
        for (int i = n-1; i > 0; --i)
        {
            for (int k = 0; i+k < n; ++k)
            {
                grid[k][i+k] = top_left[counter++];
            }
        }
        counter = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int k = 0; k + i < limit; ++k)
            {
                grid[i+k][k] = bottom_right[counter++];
            }
        }
		P2D(grid);

        return grid;
    }
};

int main()
{
	Ss;
	VV list {{1,7,3}, {9,8,2}, {4,5,6}};
	s.sortMatrix(list);
}
