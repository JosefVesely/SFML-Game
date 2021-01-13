#pragma once
#include <cmath>
#include <iostream>

namespace math 
{
	// Constants
	constexpr float PI = 3.1415926535f;
	constexpr float TWO_PI = 2 * PI;

	// Functions
	float toDegrees(float degrees)
	{
		return degrees * PI / 180.f;
	}

	float toRadians(float radians)
	{
		return radians * 180.f / PI;
	}

	// Trigonometric functions
	float sin(float angle)
	{
		return ::sin(angle);
	}

	float cos(float angle)
	{
		return ::cos(angle);
	}

	float atan2(int y, int x)
	{
		return ::atan2(y, x);
	}
}