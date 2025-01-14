#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
//2
using namespace std;

template <typename T>
T RandomItemFromVector(const vector<T>& vec)
{
	if (vec.empty())
	{
		throw runtime_error("Vector is empty.");
	}
	size_t index = rand() % vec.size();
	return vec[index];
}

int randomInRange(int start, int end);

float randomInRange(int start, float end);

float randomInRange(float start, int end);

float randomInRange(float start, float end);


bool ProbabilityCheck(int probability);
