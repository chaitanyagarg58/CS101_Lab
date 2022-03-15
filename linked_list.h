#include <iostream>
using namespace std;

struct Node
{
    int a;
    Node *next_node;
};

class LinkedList
{
private:
    Node N[n];

public:
    LinkedList(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            N[i].a = arr[i];
            N[i].next_node = &N[i + 1];
        }
        N[n - 1].next_node = NULL;
    }

    Node *getHead()
    {
        return N;
    }

    void print()
    {
        for (int i = 0; N[i - 1].next_node != NULL; i++)
        {
            cout << N[i].a << " ";
        }
        cout << endl;
    }

    int length()
    {
        return n;
    }

    bool find(int val)
    {
        for (int i = 0; N[i - 1].next_node != NULL; i++)
        {
            if (N[i] == val)
                return 1;
        }
        return 0;
    }

    void insert(int val)
    {
    }
};