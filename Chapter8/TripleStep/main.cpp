#include <bits/stdc++.h>

using namespace std;

/*
    Q.  A child is running up a staircase with n steps and can hop either 1 step, 2 steps,
        or 3 steps at a time. Implement a method to count how many possible ways the child
        can run up the stairs.
    
    Example: 
        n = 3{
            1, 1, 1
            1, 2
            2, 1
            3
        } => 4 possible ways
        n = 4{
            1, 1, 1, 1
            1, 1, 2
            1, 2, 1
            1, 3
            3, 1
            2, 1, 1
        } => 6 possible ways


    * First question is how many different ways are there for arriving 1st staircase => 1 way
    * How many different ways are there for arriving 2nd staircase => 2 ways{1,1 ; 2}
    * How many different ways are there for arriving 3rd staircase => 
        Assume 2nd step => {1};             dp[2] = 2 {1,1 ; 2}
        Assume 1st step => {2; 1,1};        dp[1] = 1
        Assume 0th step => {3};             dp[0] = 0
        total => 1 + 2 + 1 = 4 different ways to reach 3rd step.  

*/

// dp approach
// time-complexity: O(n)
// space-complexity: O(n)
int tripleSteps(int n)
{
    vector<int> steps{1, 2, 3};
    vector<int> dp(n+1, 0);
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(auto step : steps)  // 1, 2, 3
        {
            if(i - step > 0)
                dp[i] += dp[i - step];
            else if(i - step == 0)
                dp[i]++;
        }
    }

    return dp[n];
}

int main()
{
    int n;
    while(cin >> n)
        cout << tripleSteps(n) << '\n';
}