// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
public:
    Node *copyList(Node *head)
    {
        Node *cur = head;
        Node *temp;

        while (cur)
        {
            temp = cur->next;
            cur->next = new Node(cur->data);
            cur->next->next = temp;
            cur = temp;
        }

        cur = head;
        while (cur != NULL)
        {
            if (cur->arb != NULL)
            {
                cur->next->arb = cur->arb->next;
            }
            else if (cur->arb == NULL)
            {
                cur->next->arb = NULL; // or we can return cur->arb  which is same;
            }

            cur = cur->next->next;
        }

        Node *original = head;
        Node *copy = head->next;
        Node *copyHead = copy;

        while (original and copy)
        {
            original->next = original->next->next;
            if (copy->next != NULL)
            {
                copy->next = copy->next->next;
            }
            else if (copy->next == NULL)
            {
                copy->next = NULL;
            }

            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};