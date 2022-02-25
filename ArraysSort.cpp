#include "ArraysSort.h"

std::vector<std::vector<int>> arraysGenAndSort(int n) {
	std::vector<std::vector<int>> arrays(n);

	// ordered set of existing arrays sizes; needed to speed up the generation of the unique array size
	std::set<int> existingSizes;

	// initialization for random numbers generation
	srand(time(NULL));

	for (int i = 0; i < n; i++) {

		// new array size generation and memory allocation
		arrays[i].resize(uniqueArraySizeGeneration(existingSizes));

		arrayFilling(arrays[i]);

		// if the array number is even, sort in ascending order, otherwise in descending order
		if ((i + 1) % 2 == 0) {
			arrayAscSort(arrays[i]);
		}
		else {
			arrayDescSort(arrays[i]);
		}
	}

	return arrays;
}

int positiveIntGeneration() {
	return rand() + 1;
}

void arrayFilling(std::vector<int> &array) {
	for (auto& elem : array) {
		elem = rand();
	}
}

void arrayAscSort(std::vector<int> &array) {
	std::sort(array.begin(), array.end());
}

void arrayDescSort(std::vector<int> &array) {
	std::sort(array.begin(), array.end(), std::greater<int>());
}

int uniqueArraySizeGeneration(std::set<int> &existingSizes) {
	int newSize;

	// the loop continues while the new array size is equal to the existing arrays size
	do {
		newSize = positiveIntGeneration();
	} while (existingSizes.find(newSize) != existingSizes.end());

	// add new size to the set of existing sizes
	existingSizes.insert(newSize);

	return newSize;
}