#include <iostream>
#include <unordered_map>
using namespace std;

bool checkCircularLinkedList(Node *head)
{
    unordred_map<node *, bool> vis;
    Node *temp = head;

    while (temp != NULL)
    {
        if (vis.find(temp) != vis.end())
        {
            vis[temp] = true;
        }
        else
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}