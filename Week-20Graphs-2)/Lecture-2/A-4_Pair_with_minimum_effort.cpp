class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // mini heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> distance(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        pq.push({0, {0, 0}});
        distance[0][0];

        while (!pq.empty())
        {
            auto frontnode = pq.top();
            pq.pop();

            int frontnodeDifference = frontnode.first;
            int x = frontnode.second.first;
            int y = frontnode.second.second;

            // check ans tak toh nhiii pahuch gyee
            if (x == heights.size() - 1 && y == heights[0].size() - 1)
            {
                return distance[x][y];
            }

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < heights.size() && newY < heights[0].size())
                {
                    int currentNodeDifference = abs(heights[x][y] - heights[newX][newY]);
                    int newMax = max(currentNodeDifference, frontnodeDifference);
                    if (newMax < distance[newX][newY])
                    {
                        distance[newX][newY] = newMax;
                        pq.push({newMax, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};