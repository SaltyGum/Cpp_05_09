#include <iostream>
#include "iter.hpp"

int main() {
	char a1[6] = { 'C', 'u', 'e', 'l', 'h', 'o' };
	int a2[6] = {9, 8, 7, 4, 2, 0};
	float a3[3] = {111.32f , 1.2f, 3.14f};
	double a4[3] = {19999.32 , 466666.4, 666.666};
	std::cout << "chars " <<std::endl;
	::iter(a1, 6, &printer);
	std::cout << "\nintegers " <<std::endl;
	::iter(a2, 2, &printer);
	std::cout << "\nfloats " <<std::endl;
	::iter(a3, 3, &printer);
	std::cout << "\ndoubles " <<std::endl;
	::iter(a4, 3, &printer);
}