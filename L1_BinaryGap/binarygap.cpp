#include <iostream>
using namespace std;

/**
 * 
 * A binary gap within a positive integer N is any maximal 
 * sequence of consecutive zeros that is surrounded by 
 * ones at both ends in the binary representation of N.
 * 
 * For example, number 9 has binary representation 1001 
 * and contains a binary gap of length 2. The number 529 
 * has binary representation 1000010001 and contains two 
 * binary gaps: one of length 4 and one of length 3. The 
 * number 20 has binary representation 10100 and contains 
 * one binary gap of length 1. The number 15 has binary 
 * representation 1111 and has no binary gaps. The number 
 * 32 has binary representation 100000 and has no binary gaps.
 * 
 * Write a function:
 * 
 * int solution(int N);
 * 
 * that, given a positive integer N, returns the length of 
 * its longest binary gap. The function should return 0 if 
 * N doesn't contain a binary gap.
 * 
 * For example, given N = 1041 the function should return 
 * 5, because N has binary representation 10000010001 and 
 * so its longest binary gap is of length 5. Given N = 32 
 * the function should return 0, because N has binary 
 * representation '100000' and thus no binary gaps.
 * 
 * Write an efficient algorithm for the following assumptions:
 * 
 * N is an integer within the range [1..2,147,483,647].
 * 
 * @desc: Convert N to binary. Go there each digit and find 
 * the first 1 Then look for the next 1.  Keep track of 
 * number of moves after next 1, look for the next 1 again 
 * until the end.  
 * 
 * The order of the binary digits in this method is backwards, 
 * but it does not matter to calculate this solution.
 * 
 * @param: N: Integer input [1..2,147,483,647]
 * @return: Largest binary gap.
*/
int solution(int N)
{
    // Check for 0 or less than 0
    // Cannot divide by zero and range is only positive integers
    if(N <= 0)
    {
        return 0;
    }

    // Init values
    int count = 0;
    bool first1Found = false;
    int maxCount = 0;

    while(N > 0) 
    {
        // Convert to binary
        int temp = N % 2;

        // DEBUG OUTPUT
        //cout << temp;
        if(temp == 1 && first1Found == false)
        {
            // First 1 found
            // Start counting zeros
            first1Found = true;
            count = 0;
        }
        else if(temp == 1 && first1Found == true)
        {
            // Find a 1, so check if this is the largest count
            // Set the new max value
            if(count > maxCount)
            {
                maxCount = count;
            }
            // Reset the count
            count = 0;
        }
        else
        {
            // Zero found, so count
            count++;
        }

        // Move to the next value
        N /= 2;
    }

    // DEBUG OUTPUT
    //cout << endl;

    // Return largest count
    return maxCount;
}

int main() 
{
    int result = solution(1041);
    cout << result << endl;
    assert(result == 5);

    result = solution(32);
    cout << result << endl;
    assert(result == 0);

    result = solution(0);
    cout << result << endl;
    assert(result == 0);

    result = solution(529);
    cout << result << endl;
    assert(result == 4);

    result = solution(20);
    cout << result << endl;
    assert(result == 1);

    result = solution(15);
    cout << result << endl;
    assert(result == 0);

    result = solution(2147483647);
    cout << result << endl;
    assert(result == 0);

    result = solution(1);
    cout << result << endl;
    assert(result == 0);

    result = solution(-1);
    cout << result << endl;
    assert(result == 0);
}