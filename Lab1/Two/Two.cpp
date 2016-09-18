// Two.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	//using float
	float x = 10, y = 15, first, second, chisl1, chisl2, znam1, znam2, result;
	chisl1 = x + y;
	znam1 = y + 1;
	first = chisl1 / znam1;
	chisl2 = (x*y) - 12;
	znam2 = 34 + x;
	second = chisl2 / znam2;
	result = first - second;
	printf("Result usint float: %f", result);

	//using int
	int x_ = 10, y_ = 15, first_, second_, chisl1_, chisl2_, znam1_, znam2_, result_;
	chisl1_ = x_ + y_;
	znam1_ = y_ + 1;
	first_ = chisl1_ / znam1_;
	chisl2_ = (x_*y_) - 12;
	znam2_ = 34 + x_;
	second_ = chisl2_ / znam2_;
	result_ = first_ - second_;
	printf("\nResult usint float: %i", result_);
	printf("\nPress ENTER to continue...");
	getchar();
	return 0;
}

