#include <stdio.h>
#include <float.h>

int main()
{
	float max = -FLT_MAX;
	float min = FLT_MAX;
	float sum = 0.0f;
	float input;
	int n = 0;

	while (scanf("%f", &input) == 1)
	{
		if(input < 0.0f || input > 100.0f)	//input이 0보다 작거나 100보다 크면 입력값을 무시하는 코드 추가
			continue;

		max = (input > max) ? input : max; // max
		min = (input < min) ? input : min;// min
		/*
		다른방법
		if(input < min)
			min = input;
		*/

		sum += input;

		n++; // Count number of inputs
	}

	if (n > 0)
		printf("min = %f, max = %f, ave = %f", min, max, sum / n);
	else
		printf("No input\n");

	return 0;
}
