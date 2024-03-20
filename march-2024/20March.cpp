#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *temp = list1;
        int index = 0;
        while (index < a - 1)
        {
            temp = temp->next;
            index++;
        }
        ListNode *startPoint = temp;
        while (index < b + 1)
        {
            temp = temp->next;
            index++;
        }
        ListNode *endPoint = temp;

        ListNode *current = list2;
        startPoint->next = list2;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = endPoint;
        return list1;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int n, m;
    cout << "Enter the number of elements in list1: ";
    cin >> n;

    cout << "Enter the elements of list1: ";
    ListNode *list1 = nullptr;
    ListNode *tail1 = nullptr;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        if (!list1)
        {
            list1 = new ListNode(val);
            tail1 = list1;
        }
        else
        {
            tail1->next = new ListNode(val);
            tail1 = tail1->next;
        }
    }

    cout << "Enter the number of elements in list2: ";
    cin >> m;

    cout << "Enter the elements of list2: ";
    ListNode *list2 = nullptr;
    ListNode *tail2 = nullptr;
    for (int i = 0; i < m; ++i)
    {
        int val;
        cin >> val;
        if (!list2)
        {
            list2 = new ListNode(val);
            tail2 = list2;
        }
        else
        {
            tail2->next = new ListNode(val);
            tail2 = tail2->next;
        }
    }

    int a, b;
    cout << "Enter the values of 'a' and 'b': ";
    cin >> a >> b;

    Solution sol;
    list1 = sol.mergeInBetween(list1, a, b, list2);
    cout << "Merged list: ";
    printList(list1);

    return 0;
}
