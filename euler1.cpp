#include <cmath>
#include <iostream>
#include <algorithm>

int main() {
    int numTestCases;
    std::cin >> numTestCases;

    for(int i = 0; i < numTestCases; i++){ // for each test case
        unsigned long long int maxLimit, accumulator = 0;
        std::cin >> maxLimit;
        maxLimit -= 1;
        
        int j = 0, k = 0, l = 0;
        unsigned long long int summation = 0, sumFifteen, sumFive, sumThree;
        unsigned long long int threeLimit = maxLimit/3, fiveLimit = maxLimit/5, fifteenLimit = maxLimit/15;

        summation = (fifteenLimit*(fifteenLimit+1))/2;
        sumFifteen = summation * 15;

        summation = (fiveLimit*(fiveLimit+1))/2;
        sumFive = summation * 5;
        
        summation = (threeLimit*(threeLimit+1))/2;
        sumThree = summation * 3;
        
        accumulator = sumThree + sumFive - sumFifteen;
        std::cout << accumulator << std::endl;
    }
    return 0;
}

