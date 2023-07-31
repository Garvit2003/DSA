class Solution
{
private:
    void dfs(int x, int y, int oldColor, int newColor, vector<vector<int>> &image)
    {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != oldColor)
        {
            // Base case or boundary condition
            return;
        }

        image[x][y] = newColor; // Change the color of the current cell

        // Recursively call DFS on neighboring cells
        dfs(x + 1, y, oldColor, newColor, image);
        dfs(x - 1, y, oldColor, newColor, image);
        dfs(x, y + 1, oldColor, newColor, image);
        dfs(x, y - 1, oldColor, newColor, image);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        if (oldColor != newColor)
        {
            dfs(sr, sc, oldColor, newColor, image);
        }
        return image;
    }
};
