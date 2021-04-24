#include <bits/stdc++.h>

using namespace std;

/*
Q.  Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?

examples:
    input = "abca"
    unordered_set<type>
*/


// time-complexity: O(n)
// space-complexity: O(n)
bool isUnique(const string& input)
{
    unordered_set<char> us;

    for(auto ch : input)
    {
        if(us.find(ch) != us.end()) // I found the same character in the set
            return false;
        else
            us.insert(ch);
    }
    return true;
}


// time-complexity: O(nlogn)
// space-complexity: O(1)

// "abca" => "aabc"
bool isUnique2(string& input)
{
    sort(input.begin(), input.end());

    for(int i = 1; i < input.size(); i++)
    {
        if(input[i] == input[i-1])
            return false;
    }

    return true;
}


int main()
{
    string input;
    while(cin >> input)
    {
        cout << isUnique(input) << endl;
        cout << isUnique2(input) << endl;
    }
}