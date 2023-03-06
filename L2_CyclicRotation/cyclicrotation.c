/**
 * An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

class Solution { public int[] solution(int[] A, int K); }
that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
For another example, given

    A = [0, 0, 0]
    K = 1
the function should return [0, 0, 0]

Given

    A = [1, 2, 3, 4]
    K = 4
the function should return [1, 2, 3, 4]

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/
#include <stdio.h>

struct Results {
  int * A;
  int N; // Length of the array
};

struct Results solution(int A[], int N, int K)
{
    // Create a new array to store the shifted values
    int newArray[N];

    // Go through each value and shift it
    int x;
    for(x = 0; x < N; x++)
    {
        // Check if the value is wrapping
        if(x <= ((N-K)-1))
        {
            // No wrap so just assign
            newArray[x+K] = A[x];
        }
        else
        {
            // Get the wrap index
            // This will determine the number of positions it will
            // consume before the wrap (N - (x+1)).
            // Then determine the number of positions it will consume
            // after the wrap starting at 0.  And subtract 1 for 0-based index.
            int index = (K - (N - (x+1))) - 1;
            newArray[index] = A[x];
        }
    }

    // Store the results
    struct Results result;
    result.A = newArray;
    result.N = N;

    return result;
}

int main()
{
    
    int N = 5;
    int testCase1[] = {3, 8, 9, 7, 6};
    int K = 3;
    struct Results result1 = solution(testCase1, N, K);

    for(int x = 0; x < result1.N; x++)
    {
        printf("%i", result1.A[x]);
    }
    printf("\n");
    

    int N_2 = 3;
    int testCase2[] = {0, 0, 0};
    int K_2 = 1;
    struct Results result2 = solution(testCase2, N_2, K_2);

    for(int x = 0; x < result2.N; x++)
    {
        printf("%i", result2.A[x]);
    }
    printf("\n");

    
    N = 4;
    int testCase3[] = {1,2,3,4};
    K = 4;
    struct Results result3 = solution(testCase3, N, K);

    for(int x = 0; x < result3.N; x++)
    {
        printf("%i", result3.A[x]);
    }
    printf("\n");
    
}