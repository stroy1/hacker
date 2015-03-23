#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() { 
    int firstSequenceSize, secondSequenceSize;
    std::cin >> firstSequenceSize >> secondSequenceSize;
    
    std::vector<int> firstSequence;
    firstSequence.push_back(0);
    for(int i = 0; i < firstSequenceSize; i++){
        int num;
        std::cin >> num;
        firstSequence.push_back(num);
    }
    firstSequenceSize++;
    
    std::vector<int> secondSequence;
    secondSequence.push_back(0);
    for(int i = 0; i < secondSequenceSize; i++){
        int num;
        std::cin >> num;
        secondSequence.push_back(num);
    }
    secondSequenceSize++;
    
    int table[secondSequenceSize][firstSequenceSize];
    for(int i = 0; i < secondSequenceSize; i++){
        for(int j = 0; j < firstSequenceSize; j++){
            table[i][j] = 0;
        }
    }


    for(int i = 1; i < firstSequenceSize; i++){
        for(int j = 1; j < secondSequenceSize; j++){
            if(firstSequence.at(i) == secondSequence.at(j)){
                table[j][i] = table[j-1][i-1]+1;
            }else{ // check up or over left
                if(table[j-1][i] >= table[j][i-1]){
                    table[j][i] = table[j-1][i];
                }else{
                    table[j][i] = table[j][i-1];
                }
            }
        }
    }

    int first = firstSequenceSize-1, second = secondSequenceSize-1;
    std::vector<int> shortestSequence;
    
    while(first > 0 && second > 0){
        if(table[second][first] == table[second][first-1]){ // check left
            first--;
        }else{
            if(table[second][first] == table[second-1][first]){ // check up
                second--;
            }else{
                shortestSequence.push_back(table[second][first]);
                std::cout << table[second][first];
                first--;
            }
        }
    }
    
    std::vector<int>::iterator it = shortestSequence.begin();
    for(; it != shortestSequence.end(); it++){
        std::cout << *it << " ";
    }
    
    
    return 0;
}

