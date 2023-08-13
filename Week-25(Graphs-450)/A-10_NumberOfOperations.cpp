class Solution
{
private:
    void dfs(int src, map<int, bool> &visited, int n, vector<vector<int>> &connections, map<int, list<int>> &adjList)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                dfs(nbr, visited, n, connections, adjList);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {

        if (connections.size() < n - 1)
        {
            return -1;
        }
        map<int, bool> visited;

        map<int, list<int>> adjList;
        for (auto task : connections)
        {
            int u = task[0];
            int v = task[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, n, connections, adjList);
                count++;
            }
        }

        int operations = count - 1;
        return operations;
    }
};