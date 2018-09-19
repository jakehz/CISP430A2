#include<iostream>
#include<cstdlib>
#include<cassert>	//Allows for assert function.
#include"sequence2.h"//Includes sequence2 header file

using namespace CISP430_A2;	//From sequence2.h

sequence::sequence(size_type entry = CAPACITY) {
	data = new value_type[entry];
}

void sequence::start() {

	//assert(size() < CAPACITY);

	if (used == 0) {
		std::cout << "There is no current item.\n";
	}
	else {
		current_index = 0;
		std::cout << "Current index is: " 
			<< data[current_index] << "\n";
		used++;
	}
}

void sequence::advance() {
	assert(current_index >= used);
	current_index++;
	std::cout << "Current index is: " 
		<< data[current_index] << "\n";

}

void sequence::insert(const value_type& entry) {
	assert(size() < CAPACITY);
	data[used] = entry;
	++used;
}

void sequence::attach(const value_type& entry) {
	if (current_index == used) 
	{
		current_index = used;
		data[current_index] = entry;
		used++;
	}
	else{
		for (int i = used; i > (current_index + 1); i--) 
			{
				data[i] = data[i - 1];
				data[current_index + 1] = entry;
			}
		used++;
		current_index++;
		}
}

void sequence::remove_current() {
	for (int i = current_index; i < used - 1; i++) {
		data[i] = data[i + 1];
	}
	used--;
}