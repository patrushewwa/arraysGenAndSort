#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <set>

// creates an array of n random size arrays, fills it with random numbers and sorts
// n - arrays amount
std::vector<std::vector<int>> arraysGenAndSort(int n);

// generates new array size that is not equal to exisiting arrays size
int uniqueArraySizeGeneration(std::set<int> &existingSizes);

// generates random integer number > 0
int positiveIntGeneration();

// fills an array with random numbers
void arrayFilling(std::vector<int> &array);

// sorts an array in ascending order
void arrayAscSort(std::vector<int> &array);

// sorts an array in descending order
void arrayDescSort(std::vector<int> &array);