#include "ArraysSort.h"

std::vector<std::vector<int>> arraysGenAndSort(int n) {
	// initialization for random numbers generation
	srand(time(NULL));

	std::vector<std::vector<int>> arrays(n);

	for (int i = 0; i < n; i++) {
		
		int newArraySize;
		// if the new array size is equal to the existing array size, equalSizes = true
		bool isequalSizes;

		// the loop continues while the new array size is equal to the existing arrays size
		do {
			newArraySize = positiveIntGeneration();
			isequalSizes = false;
			for (int k = 0; k < i && !isequalSizes; k++) {
				if (newArraySize == arrays[k].size())
					isequalSizes = true;
			}
		} while (isequalSizes);

		arrays[i].resize(newArraySize);
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