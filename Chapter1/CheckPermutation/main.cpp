#include <bits/stdc++.h>

using namespace std;

/*
    Q. Given two strings, write a method to decide if one is a permutation of the other.


    str1 = "abc" => "abc"
    str2 = "bca" => "abc"
*/


// time-complexity : O(nlogn)
// space-complexity: O(1)
bool isPermOfTheOther(string& str1, string& str2)
{
    if(str1.size() != str2.size())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if(str1 == str2)
        return true;
    else
        return false;
}

// time-complexity: O(n)
// space complexity: O(n)
bool isPermOfTheOther2(const string& str1, const string& str2)
{
    if(str1.size() != str2.size())
        return false;

    unordered_map<char, int> m1;
    unordered_map<char, int> m2;

    for(int i = 0; i < str1.size(); i++)
    {
        m1[str1[i]]++;
        m2[str2[i]]++;
    }

    if(m1 == m2)
        return true;
    else
        return false;
}



int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {
        cout << isPermOfTheOther(str1, str2) << endl;
        cout << isPermOfTheOther2(str1, str2) << endl;
    }
}