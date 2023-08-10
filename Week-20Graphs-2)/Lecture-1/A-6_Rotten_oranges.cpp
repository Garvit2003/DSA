class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q;
        // first pair is of coordinates of oranges , second pair is of time
        vector<vector<int>> arr = grid;

        int ansTime = 0;

        // insert all rotten oranges in queue
        for (int row = 0; row < arr.size(); row++)
        {
            for (int col = 0; col < arr[row].size(); col++)
            {
                if (grid[row][col] == 2)
                {
                    pair<int, int> coordinate = make_pair(row, col);
                    q.push({coordinate, 0});
                }
            }
        }

        while (!q.empty())
        {
            auto frontnode = q.front();
            q.pop();
            int x = frontnode.first.first;
            int y = frontnode.first.second;
            int time = frontnode.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[x].size() && arr[newX][newY] == 1)
                {
                    pair<int, int> newCoordinates = make_pair(newX, newY);
                    ansTime = max(ansTime, time + 1);
                    q.push({newCoordinates, time + 1});
                    // mark rotten
                    arr[newX][newY] = 2;
                }
            }
        }
        // check for fresh oranges
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                if (arr[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ansTime;
    }
};