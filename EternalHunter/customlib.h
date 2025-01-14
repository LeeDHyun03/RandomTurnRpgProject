#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
T RandomItemFromVector(const std::vector<T>& vec);


inline int randomInRange(int start, int end);

inline float randomInRange(int start, float end);

inline float randomInRange(float start, int end);

inline float randomInRange(float start, float end);


inline bool ProbabilityCheck(int probability);
