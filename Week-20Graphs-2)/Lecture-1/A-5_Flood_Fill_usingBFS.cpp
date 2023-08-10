class Solution
{
private:
    void bfs(vector<vector<int>> &image, int sr, int sc, int newColor, map<pair<int, int>, bool> &visited, int oldColor, vector<vector<int>> &arr)
    {

        if (oldColor == newColor)
        {
            return;
        }
        queue<pair<int, int>> q;
        q.push({sr, sc});

        // visited[{sr,sc}]=true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int n = arr.size();

        while (!q.empty())
        {
            auto fnode = q.front();
            q.pop();

            int x = fnode.first;
            int y = fnode.second;

            arr[x][y] = newColor;

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() && !visited[{newX, newY}] && arr[newX][newY] == oldColor)
                {
                    q.push({newX, newY});

                    // visited[{newX,newY}]=true;
                    // arr[newX][newY]=newColor;
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        map<pair<int, int>, bool> visited;

        vector<vector<int>> arr = image;

        int oldColor = image[sr][sc];

        bfs(image, sr, sc, color, visited, oldColor, arr);
        return arr;
    }
};