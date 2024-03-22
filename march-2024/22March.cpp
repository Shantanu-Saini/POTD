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
public:
    bool isPalindrome(ListNode *head)
    {
        if (head->next == NULL || head->next == NULL)
        {
            return true;
        }

        stack<int> stk;
        ListNode *temp = head;
        while (temp)
        {
            stk.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp)
        {
            if (temp->val != stk.top())
            {
                return false;
            }
            stk.pop();
            temp = temp->next;
        }

        return true;
    }
};

// Function to create a linked list from an array
ListNode *createListFromArray(int arr[], int n)
{
    ListNode *head = nullptr;
    ListNode *current = nullptr;
    for (int i = 0; i < n; ++i)
    {
        ListNode *newNode = new ListNode(arr[i]);
        if (head == nullptr)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }
    return head;
}

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
    // Create a sample linked list: 1 -> 2 -> 2 -> 1 (palindrome)
    int arr1[] = {1, 2, 2, 1};
    ListNode *list1 = createListFromArray(arr1, sizeof(arr1) / sizeof(arr1[0]));

    // Create a sample linked list: 1 -> 2 -> 3 -> 4 (not a palindrome)
    int arr2[] = {1, 2, 3, 4};
    ListNode *list2 = createListFromArray(arr2, sizeof(arr2) / sizeof(arr2[0]));

    // Creating a solution object
    Solution sol;

    cout << "List 1: ";
    printList(list1);
    cout << "Is Palindrome: " << (sol.isPalindrome(list1) ? "true" : "false") << endl;

    cout << "List 2: ";
    printList(list2);
    cout << "Is Palindrome: " << (sol.isPalindrome(list2) ? "true" : "false") << endl;

    return 0;
}
