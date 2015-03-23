#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef std::vector<char> bignum;

void Double(bignum & num){
    int carry = 0;
    for (bignum::iterator p = num.begin();  p != num.end();  ++p){
        *p *= 2;
        *p += carry;
        carry = (*p >= 10);
        *p -= carry * 10;
    }
    if (carry != 0 && num.size() < 5)
        num.push_back(carry);
}

void Subtract(bignum & num){
    for (bignum::iterator p = num.begin();  p != num.end();  ++p){
        if(*p == 0){
            *p = 9;
        }else{
            *p -= 1;
            break;
        }
    }
}

int main() {
    int numTestCases;
    cin >> numTestCases;
    
    for(int i = 0; i < numTestCases; i++){
        double numLights;
        bignum num;
        num.push_back(1);
        cin >> numLights;
        
        for(int j = 0; j < numLights; j++){
            Double(num);
        }
        Subtract(num);
        reverse(num.begin(), num.end());
        int number = 0, placeHolder = 10000;
        
        for (bignum::iterator p = num.begin(); p != num.end(); p++){
            number += static_cast<int>(*p)*placeHolder;
            placeHolder /= 10;
        }
        cout << number % 100000 << endl;

        
    }
    return 0;
}

