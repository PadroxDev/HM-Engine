#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace Mathf {
	static double PI = M_PI;
	static double Rad2Deg = 360 / (PI * 2);
	static double Deg2Rad = (PI * 2) / 360;
	static double PixelsPerUnit = 100;

	void Test();
}