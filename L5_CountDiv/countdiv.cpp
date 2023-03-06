#include <vector>
#include <iostream>
#include <map>
#include <numeric>
using namespace std;

int solution(int A, int B, int K) {
    
    //int result = 0;
    
    // Implement your solution here
    //for(int x = A; x <= B; x++)
    //{
    //    if((x % K) == 0)
    //    {
    //        result++;
    //    }
    //}

    //return result;

    // This is a mathmatical formula you either know or do not know
    return B / K - (A - 1) / K;
}