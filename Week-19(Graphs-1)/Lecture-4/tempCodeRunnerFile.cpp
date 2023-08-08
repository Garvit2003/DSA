    void shortestDisDijkstra(int src, int n)
    {
        vector<int> dis(n, INT_MAX);
        set<pair<int, int>> st;
        // initial steps
        dis[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            // set ko iterator se access krte hai, index se ni
            // st.begin= iterator
            // actual value= *(st.begin()) , *=rereference operator
            // fetch the smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop the element from set
            st.erase(st.begin());

            // neighbour traverse

            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < dis[nbr.first])
                {
                    // mujhe distance update krna hai set mein bhi aur distance wale array mein bhi. usse liye mujhe pehle ye check krna padega ki set mein wo distance hai ya nhii or simply search krna padega set mein.
                    // basicall muje wo distance chahiye hogi update krne ke liye toh main us distance ko pehle dudhunga.
                    // finding entry in set
                    // purani entry ko search kra set mein
                    auto result = st.find(make_pair(dis[nbr.first], nbr.first));

                    // if found then remove
                    // purani entry ko remove kra set se
                    if (result != st.end())
                    {
                        st.erase(result);
                    }

                    // Updating distance in distance array
                    dis[nbr.first] = nodeDistance + nbr.second;

                    // nyii entry ko insert kr diya
                    st.insert(make_pair(dis[nbr.first], nbr.first));
                }
            }
        }

        cout << "Printing ans: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << dis[i] << ",";
        }
        cout << endl;
    }