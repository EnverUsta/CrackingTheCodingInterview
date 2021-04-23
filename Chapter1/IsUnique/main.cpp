#include <bits/stdc++.h>

using namespace std;

/*
Q.  Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
*/

// time-complexity: O(N)
// space-complexity: O(N)
bool isAllUniqueCharacters(const string& str)
{
    unordered_set<char> mySet;
    for(auto ch : str)
    {
        // element found
        if(mySet.find(ch) != mySet.end())
            return false;
        else
            mySet.insert(ch);
    }
    return true;
}


// Without additional data structures
// time-complexity : O(nlogn)
// space-complexity : O(1)
bool isAllUniqueCharacters2(string& input)
{
    sort(input.begin(), input.end()); 

    for(int i = 1; i < input.length(); i++)
    {
        if(input[i] == input[i-1])
            return false;
    }
    return true;
}



int main()
{
    string input = "";
    while(cin >> input)
    {
        cout << isAllUniqueCharacters(input) << '\n';
        cout << isAllUniqueCharacters2(input) << '\n';
    }
}
