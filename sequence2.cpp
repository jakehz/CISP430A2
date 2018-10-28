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

void sequence::remove_current()
{
	value_type* data_replace = new value_type[capacity];
	// the slot one past the current index, this will be the new current index.
	size_t past_current = current_index + 1;
	// add each datum from the old array into the new array
	// until we get to the current index.
	if(!is_item()){
		// if we are currently at nothing, there is nothing to remove.
		return;
	}
	for(size_t i = 0; i < current_index; i++) {
		data_replace[i] = data[i];
	}
	// start copying from one past the current_index.
	// this effectively makes a copy of the previous data set without the value originally
	// pointed to by the current pointer.
	for(size_t j = past_current; j < used; j++){
		// since the new array is one less, the array indexes are
		// one minus that on the old array.
		data_replace[j-1] = data[j];
	}
	// delete the data pointed to by the class pointer.
	delete [] data;
	// reassign the class pointer to the new array with less items in it.
	data = data_replace;
	// decrement the total used by 1, since we removed an item.
	used--;
}
