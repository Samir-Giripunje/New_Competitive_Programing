#include <bits/stdc++.h>
using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
// };

struct Node
{
    int data;
    struct Node *next;
};
int main()
{

    Node *head;
    Node *first = new Node();
    Node *sec = new Node();
    Node *th = new Node();

    first->data = 1;
    sec->data = 2;
    th->data = 3;

    first->next = sec;
    sec->next = th;
    th->next = NULL;
    head = first;

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
