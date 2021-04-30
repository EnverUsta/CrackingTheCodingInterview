#include <bits/stdc++.h>

using namespace std;

/*
    Q. Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word
       or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters.
       The palindrome does not need to be limited to just dictionary words.

    examples:
        Input: 'Tact Coa'
        number of occurrences the characters: {t: 2, a: 2, c: 2, o: 1} 
        Output: True -> 'taco cat', 'acto tca'

    extra dataStructures: HashTable, int array[].

    T, t = These Ts are equal.

    Ascii character table: 
        a: 65 z: 91
        A: 92 Z: 118
        if(int(ch) > 'z') // our letter is capital
            ch = ch = diff;
            A - a
            B - b
            C - c == All these are equal

            int diff = int('A') - int('a');
*/



// time-complexity: O(n)
// space-complexity: O(n)
bool palindromePermutation(string& input)
{
    // if my string is empty
    if(input.size() == 0)
        return false;

    unordered_map<char, int> uMap;

    int diff = int('a') - int('A');

    for(auto ch : input)
    {
        if(ch == ' ')
            continue;
        // Our letter is capital
        if(int(ch) > 'Z') 
            ch = ch - diff;
        
        uMap[ch]++;
    }

    // defects means the number of defected character
    // what is defected? val not multiply of 2
    int defects = 0;
    for(auto pair : uMap)
    {
        if(pair.second % 2 != 0)
            defects++;
    }

    if(defects > 1)
        return false;
    return true;
}

int main()
{
    string input;
    while(getline(cin, input))
        cout << palindromePermutation(input) << '\n';
}