#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using std::queue;
using std::pair;

typedef pair<int, pair<int, int> > pi;

int minPathSum(vector<vector<int>>& grid)
{
    int value;
    int rowSize = grid.size(), colSize = grid.begin()->size();
    priority_queue<pi, vector<pi>, greater<pi>> queue;
    queue.push(std::make_pair(grid[0][0], std::make_pair(0, 0)));
    while (queue.empty() == false) {
        value = queue.top().first;
        int row = queue.top().second.first;
        int col = queue.top().second.second;
        queue.pop();

        if (row + 1 == rowSize - 1 && col == colSize - 1) {
            return (value + grid[row + 1][col]);
        }
        if (col + 1 == colSize - 1 && row == rowSize - 1) {
            return (value + grid[row][col + 1]);
        }

        if (row + 1 < rowSize) {
            queue.push(std::make_pair(value + grid[row + 1][col], std::make_pair(row + 1, col)));
        }
        if (col + 1 < colSize) {
            queue.push(std::make_pair(value + grid[row][col + 1], std::make_pair(row, col + 1)));
        }
    }

    return value;
}

int minPathSum2(vector<vector<int>>& grid)
{
    if (grid.size() == 0)
        return 0;

    for (int i = 1; i < grid.size(); i++) {
        grid[i][0] += grid[i-1][0];
    }

    for (int i = 1; i < grid[0].size(); i++) {
        grid[0][i] += grid[0][i-1];
    }

    for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[i].size(); j++){
            grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }

    return grid[grid.size() - 1][grid[0].size() - 1];
}

int main()
{
    vector<vector<int> > grid = {
//        {1, 3, 1},
//        {1, 5, 1},
//        {4, 2, 1}
        {1, 2, 5},
        {3, 2, 1}
    };

    cout << minPathSum(grid) << endl;

    return 0;
}













