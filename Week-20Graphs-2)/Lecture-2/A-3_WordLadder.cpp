class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        // jo bhi set mein push kr rhee honge usse set se nikal denge
        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty())
        {
            pair<string, int> frontnode = q.front();
            q.pop();
            string currString = frontnode.first;
            int currCount = frontnode.second;

            // check if currString is equal to destination
            if (currString == endWord)
            {
                return currCount;
            }

            for (int index = 0; index < currString.length(); index++)
            {
                char originalCharacter = currString[index];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[index] = ch;
                    if (st.find(currString) != st.end())
                    {
                        q.push({currString, currCount + 1});
                        st.erase(currString);
                    }
                }
                // bringing back the currstring to its original form
                currString[index] = originalCharacter;
            }
        }
        return 0;
    }
};
