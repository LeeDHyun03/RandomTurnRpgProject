#include "CustomLib.h"




int randomInRange(int start, int end)
{
	return rand() % (end - start + 1) + start;
}
float randomInRange(int start, float end)
{
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}

float randomInRange(float start, int end)
{
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}

float randomInRange(float start, float end)
{
	float startN = start * 10.0f;
	float endN = end * 10.0f;
	return (rand() % static_cast<int>(endN - startN + 1)) / 10.0f + start;
}

bool ProbabilityCheck(int probability) //È®·ü °Ë»ç
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
