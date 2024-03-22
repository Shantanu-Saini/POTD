#include <iostream>
#include <stack>

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
    stack<int> stk;

    void traverseList(ListNode *head)
    {
        if (head == NULL)
            return;
        ListNode *temp = head;
        while (temp != NULL)
        {
            stk.push(temp->val);
            temp = temp->next;
        }
    }

    ListNode *buildList(stack<int> &stk)
    {
        if (stk.empty())
        {
            return nullptr;
        }
        ListNode *newList = new ListNode(stk.top());
        stk.pop();
        ListNode *current = newList;
        while (!stk.empty())
        {
            current->next = new ListNode(stk.top());
            stk.pop();
            current = current->next;
        }
        return newList;
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        traverseList(head);
        head = buildList(stk);
        return head;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Creating a solution object
    Solution sol;

    cout << "Original List: ";
    printList(head);

    // Reversing the list using the reverseList function
    head = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
