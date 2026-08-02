#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Process only land cells
                if (grid[r][c] == 1) {
                    perimeter += 4; // Assume 4 open sides initially

                    // If there is an adjacent land cell above, subtract 2 shared edges
                    if (r > 0 && grid[r - 1][c] == 1) {
                        perimeter -= 2;
                    }
                    // If there is an adjacent land cell to the left, subtract 2 shared edges
                    if (c > 0 && grid[r][c - 1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }

        return perimeter;
    }
};