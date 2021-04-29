#include <bits/stdc++.h>

using namespace std;

/*
    Q. Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient
    space at the end to hold the additional characters, and that you are given the "true" length of the string.

    examples:
        "Mr John Smith    " => "Mr%20John%20Smith"
        "Mr%20J" => O(n^2)  it is not efficient === Brute Force Solution
        string temp = "Mr%20John%20Smith"
*/


// time-complexity : O(n)
// space-complexity : O(n)
void URLify(string& input)
{
    string temp;

    int count = 0;
    for(auto ch : input)
    {
        if(ch == ' ' &&  count != input.size()-1 && input[count+1] != ' ')
        {
            temp.push_back('%');
            temp.push_back('2');
            temp.push_back('0');

        }
        else if(ch == ' ')
            continue;
        else
            temp.push_back(ch);

        count++;
    }

    input = temp;
}

int main()
{
    cout << "Hello" << '\n';
    string input = "Mr John Smith    ";
    URLify(input);
    cout << input << '\n';
}