//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
/* Function to print linked list */

void append(struct Node **headRef, struct Node **tailRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;
    if (*headRef == NULL)
    {
        *headRef = new_node;
        *tailRef = *headRef;
        return;
    }

    (*tailRef)->next = new_node;
    *tailRef = (*tailRef)->next;
}

// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// } Driver Code Ends

class Solution
{
public:
    // your task is to complete this function
    void sort(Node **head)
    {
        // Check if the list is empty or has only one element
        if (*head == nullptr || (*head)->next == nullptr)
            return;

        vector<int> temp;

        // Extract values from the linked list and store them in a vector
        Node *tempNode = *head;
        while (tempNode != NULL)
        {
            temp.push_back(tempNode->data);
            tempNode = tempNode->next;
        }

        // Sort the vector using bubble sort algorithm
        int n = temp.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (temp[j] > temp[j + 1])
                {
                    // Swap temp[j] and temp[j + 1]
                    int tempValue = temp[j];
                    temp[j] = temp[j + 1];
                    temp[j + 1] = tempValue;
                }
            }
        }

        // Reconstruct the linked list with sorted values
        tempNode = *head;
        for (int i = 0; i < n; i++)
        {
            tempNode->data = temp[i];
            tempNode = tempNode->next;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        struct Node *head = NULL;
        struct Node *tail = NULL;
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            append(&head, &tail, k);
        }
        Solution ob;
        ob.sort(&head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends