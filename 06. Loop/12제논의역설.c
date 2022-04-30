#include <stdio.h>

int main() //제논의 역설
{
	const double speed = 1.0;
	const int repeat_max = 50;

	double dt = 0.01; // 단위시간
	double time = 0.0; // 경과시간
	double dist = 0.0; //이동거리

	double dist_Archill = 0.0;
	double dist_Turtle = 1.0;
	double speed_Arch = 10.0;
	double speed_Turtle = 0.001;

	printf("Elapsed time = %.6fs, dt = %.6fs, Archilleus = %.6fm, Turtle = %.6fm\n", time, dt, dist_Archill, dist_Turtle);

	for(int i = 0; i < repeat_max; ++i)
	{
		dist_Archill += dt * speed_Arch;
		dist_Turtle += dt * speed_Turtle;
		time += dt;

		printf("Elapsed time = %.6fs, dt = %.6fs, Archilleus = %.6fm, Turtle = %.6fm\n", time, dt, dist_Archill, dist_Turtle);

		dt *= 0.5;
	}

	return 0;
}
