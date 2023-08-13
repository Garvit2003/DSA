class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int end_found = false;
        for (string &str : wordList)
        {
            if (str == endWord)
            {
                end_found = true;
            }
            for (int i = 0; i < str.size(); ++i)
            {
                string new_word = str.substr(0, i) + '*' + str.substr(i + 1);
                mp[new_word].push_back(str);
            }
        }
        if (!end_found)
        {
            return 0;
        }
        unordered_set<string> begin_visited;
        unordered_set<string> end_visited;
        queue<string> begin_q;
        queue<string> end_q;
        begin_q.push(beginWord);
        begin_visited.insert(beginWord);
        end_q.push(endWord);
        end_visited.insert(endWord);
        int res = 0;
        while (!begin_q.empty() && !end_q.empty())
        {
            ++res;
            if (visitedSameLevel(begin_q, begin_visited, end_visited))
            {
                return 2 * res; // we increment res for this round, and the res increment for end side can account for the new word.
            }
            if (visitedSameLevel(end_q, end_visited, begin_visited))
            {
                return 2 * res + 1; // the end node has not been count so we need the 1
            }
        }
        return 0;
    }

private:
    unordered_map<string, vector<string>> mp;
    bool visitedSameLevel(queue<string> &q, unordered_set<string> &visited,
                          unordered_set<string> &otherVisited)
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            auto str = q.front();
            q.pop();
            for (int i = 0; i < str.size(); ++i)
            {
                string new_word = str.substr(0, i) + '*' + str.substr(i + 1);
                for (auto &s : mp[new_word])
                {
                    if (otherVisited.find(s) != otherVisited.end())
                    {
                        return true;
                    }
                    if (visited.find(s) == visited.end())
                    {
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
        }
        return false;
    }
};