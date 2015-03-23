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

        while((++l) <= fifteenLimit){
            summation += l;
        }
        sumFifteen = summation * 15;
        summation += l;

        while((++l) <= fiveLimit){
            summation += l;
        }
        sumFive = summation * 5;
        summation += l;
        
        while((++l) <= threeLimit){
            summation += l;
        }
        sumThree = summation * 3;
        
        accumulator = sumThree + sumFive - sumFifteen;
        std::cout << accumulator << std::endl;
    }
    return 0;
}

