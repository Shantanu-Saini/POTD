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

void append(struct Node **headRef, struct Node **tailRef, int newData)
{
    struct Node *new_node = new Node(newData);

    if (*headRef == NULL)
    {
        *headRef = new_node;
    }

    else
    {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
}

// } Driver Code Ends

class Solution
{
public:
    // your task is to complete this function
    int countPairs(struct Node *head1, struct Node *head2, int x)
    {
        // Code here
        int ans = 0;

        // O(n) solution
        vector<int> arr1;
        vector<int> arr2;
        while (head1)
        {
            arr1.push_back(head1->data);
            head1 = head1->next;
        }
        while (head2)
        {
            arr2.push_back(head2->data);
            head2 = head2->next;
        }

        sort(arr1.begin(), arr1.end(), greater<int>()); // descending order sorting
        sort(arr2.begin(), arr2.end());

        int i = 0, j = 0, n1 = arr1.size(), n2 = arr2.size();

        while (i < n1 && j < n2)
        {
            if (arr1[i] + arr2[j] == x)
            {
                ans++;
                j++;
            }
            else if (arr1[i] + arr2[j] > x)
                i++;
            else
                j++;
        }

        // O(n^2) solution
        // while(head1){
        //     Node *temp = head2;
        //     while(temp){
        //         int sum = head1->data + temp->data;
        //         if(sum == x){
        //             ans++;
        //         }
        //         temp = temp->next;
        //     }
        //     head1 = head1->next;
        // }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        struct Node *head1 = NULL;
        struct Node *tail1 = NULL;
        struct Node *tail2 = NULL;
        struct Node *head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--)
        {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--)
        {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}
// } Driver Code Ends