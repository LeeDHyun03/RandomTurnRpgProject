#include "CustomLib.h"


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

inline int randomInRange(int start, int end)
{
	return rand() % (end - start + 1) + start;
}
inline float randomInRange(int start, float end)
{
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}

inline float randomInRange(float start, int end)
{
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}

inline float randomInRange(float start, float end)
{
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}

inline bool ProbabilityCheck(int probability) //È®·ü °Ë»ç
{
	if (rand() % 100 <= probability)
	{
		return true;
	}
	else
	{
		return false;
	}
}
