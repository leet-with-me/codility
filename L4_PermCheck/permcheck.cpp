#include <vector>
#include <iostream>
#include <map>
#include <numeric>
using namespace std;

// https://app.codility.com/demo/results/trainingHJ566N-ZZ6/

// Again you have to notice the little details.
// The question slightly implies this.  The range must start with
// 1.  So the numbers will be 1 through N.  And it must always
// start at 1.  So verify that you find all numbers between 1
// and N.  If there are any duplicates, or if the value given
// is greater than N, then it is a bad number.
// Dupicates are obvious why it is not a permutation.  But to make
// sure you have all the values needed for a permutation, you can only 
// have N values.  And if any value is greater than N, then you do not
// have enough values to go 1 - N.


int solution(vector<int> &A)
{
    // Get the size
    // This will be the maximum number we can find
    // in the list.  If any number is larger than this,
    // then we do not have enough numbers to make a permutation
    int size = (int)A.size();

    // Hold the numbers found
    map<int, bool> numsFound;

    for(auto num : A)
    {
        // If the number is greater than the size,
        // then there will not be enough numbers to complete 
        // the permuation.
        // If the number is a duplicate, then there will not
        // be enough numbers to complete the permuation.
        if(num > size || numsFound[num])
        {
            return 0;
        }

        // Set that this number has been found
        numsFound[num] = true;
    }

    return 1;
}

int main()
{
    int arr[] = {1, 3, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> t1(arr, arr + n);
    int result1 = solution(t1);
    cout << result1 << endl;
    assert(result1 == 1);

    int arr2[] = {4, 1, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> t2(arr2, arr2 + n2);
    int result2 = solution(t2);
    cout << result2 << endl;
    assert(result2 == 0);

    int arr3[] = {4};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<int> t3(arr3, arr3 + n3);
    int result3 = solution(t3);
    cout << result3 << endl;
    assert(result3 == 0);

    int arr4[] = {1, 2, 3, 4, 4, 5};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    vector<int> t4(arr4, arr4 + n4);
    int result4 = solution(t4);
    cout << result4 << endl;
    assert(result4 == 0);

    int arr5[] = {1};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    vector<int> t5(arr5, arr5 + n5);
    int result5 = solution(t5);
    cout << result5 << endl;
    assert(result5 == 1);

    int arr6[] = {1000000000};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    vector<int> t6(arr6, arr6 + n6);
    int result6 = solution(t6);
    cout << result6 << endl;
    assert(result6 == 0);

    int arr7[] = {3, 2};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    vector<int> t7(arr7, arr7 + n7);
    int result7 = solution(t7);
    cout << result7 << endl;
    assert(result7 == 0);
}
