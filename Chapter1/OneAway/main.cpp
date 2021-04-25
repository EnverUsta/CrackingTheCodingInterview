#include <bits/stdc++.h>

using namespace std;

/*
    Q. There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character.
       Given two strings, write a function to check if they are one edit(or zero edits) away.

    Example:
        pale, ple => true,
        pales, pale => true,
        pale, bale => true,
        pale, bake => false,
*/

bool oneAway(string& str1, string& str2)
{
    if(abs(str1.size() - str2.size()) > 1)
        return false;
    
    int err{0};
    if(abs(str1.size() - str2.size()) == 0)
    {
        for(int i = 0; i < str1.size(); i++)
        {
            if(str1[i] != str2[i])
                err++;
        }
    }
    else    // remove or insert operation
    {
        int smallest = min(str1.size(), str2.size());
        for(int i = 0; i < smallest; i++)
        {
            if(str1[i] != str2[i])
            {
                if(str1.size() < str2.size())
                    str2.erase(str2.begin() + 1);
                else
                    str1.erase(str1.begin() + 1);
                err++;
            }
        }
    }

    if(err > 1)
        return false;
    else
        return true;
}

int main()
{
    cout << "Testing" << '\n';
    string str1, str2;
    while(cin >> str1 >> str2)
        cout << oneAway(str1, str2) << '\n';
}