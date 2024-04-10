#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        deque<int> qu;

        // Sort the deck in ascending order
        sort(deck.begin(), deck.end());

        int n = deck.size();

        // Simulate the revealing process using a deque
        for (int i = n - 1; i >= 0; i--)
        {
            if (!qu.empty())
            {
                // Move the last element to the front
                qu.push_front(qu.back());
                qu.pop_back();
            }
            // Place the current card at the front
            qu.push_front(deck[i]);
        }

        // Transfer the revealed deck from deque to vector
        for (int i = 0; i < n; i++)
        {
            deck[i] = qu.front();
            qu.pop_front();
        }

        return deck;
    }
};

int main()
{
    int n;
    cout << "Enter the number of cards in the deck: ";
    cin >> n;

    // Input the values of cards in the deck
    vector<int> deck(n);
    cout << "Enter the values of cards in the deck: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> deck[i];
    }

    // Create an instance of the Solution class
    Solution sol;
    // Get the revealed deck
    vector<int> result = sol.deckRevealedIncreasing(deck);

    // Output the revealed deck in increasing order
    cout << "Revealed deck in increasing order: ";
    for (int card : result)
    {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}
