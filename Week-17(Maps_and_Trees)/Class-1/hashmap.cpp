#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("Scorpio", 9);
    m.insert(p);

    pair<string, int> p2("alto", 5);
    m.insert(p2);

    m["Fortuner"] = 10;

    // access
    cout << m.at("alto") << endl;
    cout << m["Fortuner"] << endl;

    // search
    cout << m.count("Innova") << endl;

    if (m.find("Fortuner") != m.end())
    {
        cout << "Fortuner found" << endl;
    }
    else
    {
        cout << "Fortuner not found" << endl;
    }

    cout << m.size() << endl;
    cout << m["hummer"] << endl;
    cout << m.size() << endl;

    cout << "Printing all entries" << endl;

    for (auto i : m)
    {
        cout << i.first << "=" << i.second << endl;
    }

    return 0;
}