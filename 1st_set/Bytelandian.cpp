/*
In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. 
A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. 
But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?
*/
   
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//long long int calculate(long long int n);
long long int helper(long long int n, map<long long int, long long int> &memo);
//map<long long int, long long int> memo;
int main() {
   
    int n;  // = 1000000000;
    map<long long int, long long int> memo;
    //vector <long long int> memo(n, 0);
    while(scanf("%d",&n)==1) printf("%lld\n",helper(n, memo));
    return 0;
}

/*long long int calculate(long long int n) {
    //int s = 0;
    long long int max;
    if(n == 0)
        return n;
    else 
    {
        vector<long long int> memo();
        max = helper(n, memo);
        return (max >= n) ? max: n;
        //return q;
    }
        
}
*/
long long int helper(long long int n, map<long long int, long long int> &memo) {
    //long long int q;
    if(n == 0)
        return n;
    if(memo[n] != 0)
        return memo[n]; 
    else{
        long long int max = helper(n/2, memo) + helper(n/3, memo) + helper(n/4, memo);
        memo[n] = (max>n)?max:n;
    }
    return memo[n];
}


