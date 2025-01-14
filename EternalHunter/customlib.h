#pragma once

inline int randomInRange(int start, int end)
{
	srand(time(NULL));
	return rand() % (end - start + 1) + start;
}
inline float randomInRange(int start, float end)
{
	srand(time(NULL));
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}
inline float randomInRange(float start, int end)
{
	srand(time(NULL));
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}
inline float randomInRange(float start, float end)
{
	srand(time(NULL));
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}

inline bool ProbabilityCheck(int probability)
{
	srand(time(NULL));
	if (rand() % 100 <= probability)
	{
		return true;
	}
	else
	{
		return false;
	}
}