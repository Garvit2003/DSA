class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty())
        {
            auto fnode = q.front();
            q.pop();

            string currString = fnode.first;
            int currCount = fnode.second;

            if (currString == endWord)
            {
                return currCount;
            }

            for (int index = 0; index < currString.length(); index++)
            {
                int originalChar = currString[index];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[index] = ch;

                    if (st.find(currString) != st.end())
                    {
                        q.push({currString, currCount + 1});
                        st.erase(currString);
                    }
                }
                currString[index] = originalChar;
            }
        }
        return 0;
    }
};