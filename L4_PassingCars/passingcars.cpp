#include <vector>
#include <iostream>
#include <map>
#include <numeric>
using namespace std;

// https://app.codility.com/demo/results/trainingTR7QMT-DHR/

int solution(vector<int> &A) {
    // Instructions state:
    // passing when P is traveling to the east and Q is traveling to the west
    // So we only monitor when 0 passes
    int monitorDirection = 0;

    int result = 0;
    int carsMonitoring = 0;

    for(int x = 0; x < (int)A.size(); x++)
    {
        // We found a car moving in the same direction
        // as the first car, so now we are monitoring
        // mulitple cars pass
        if(A[x] == monitorDirection)
        {
            carsMonitoring++;
        }
        else {
            // If the cars is not the same direction, then
            // it is a pass.  All the cars we are monitoring moving
            // this direction are passing it
            result += carsMonitoring;
        }
    }

    // If passing exceeds 1,000,000,000 
    // return -1
    if(result > 1000000000 || result < 0)
    {
        return -1;
    }

    return result;
}