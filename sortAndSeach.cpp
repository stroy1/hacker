#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int numTestCases;
    cin >> numTestCases;
    for(int i = 0; i < numTestCases; i++){
        long long int counter = 0, v_size;
        vector<long long int> v;
        cin >> v_size;
        
        for(int j = 0; j < v_size; j++){
            long long int number;
            cin >> number;
            v.push_back(number);
        }
        
        sort(v.begin(), v.end());
        
        vector<long long int>::iterator it;
        for(it = v.begin(); it != v.end()-1; it++){
            for(int k = 1; k < v_size; k++){
                if(*it == *(it+k)){
                    counter = counter + 2;
                }else{
                    break;
                }
            }
        }
        cout << counter << endl;
        
    }
    return 0;
}

