    bool checkCyclicDirectedGraphUsingDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool aageKaAns = checkCyclicDirectedGraphUsingDFS(nbr, visited, dfsVisited);
                if (aageKaAns == true)
                {
                    return true;
                }
            }
            if (visited[nbr] == true && dfsVisited[nbr] == true)
            {
                return true;
            }
        }
        // YHII PR GLTI HOGI

        dfsVisited[src] = false;
        return false;
    }