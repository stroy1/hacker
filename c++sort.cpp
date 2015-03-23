#include <cstdio>
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main (){

	std::vector<long> numbers = {256, 8, 15, 89, 3000, -3005, 1345987, 792, 20};

	std::sort(numbers.begin(), numbers.end(), std::greater<long>());
	for(long num : numbers){
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;

}

