/*
사용자로 부터 5 명의 학생의 수학, 국어, 영어 점수를 입력 받아서 평균이 가장 높은 사람 부터 평균이 가장 낮은 사람까지 정렬되어 출력하도록 하세요. 특히, 평균을 기준으로 평균 이상인 사람옆에는 '합격', 아닌 사람은 '불합격' 을 출력하게 해보세요.
 */
#include <stdio.h>

void Bubble_sort(int (*pscore)[3], int student);
void swap(int* pele);

int main()
{
	int score[5][3];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(j == 0)
			{
				printf("%d번째 학생의 수학점수 : ", i + 1);
			}
			else if(j == 1)
			{
				printf("%d번째 학생의 국어점수 : ", i + 1);
			}
			else if(j == 2)
			{
				printf("%d번째 학생의 영어점수 : ", i + 1);
			}
			scanf("%d", &score[i][j]);
		}
	}
	printf("\n");

	Bubble_sort(score, 5);

	return 0;
}


void Bubble_sort(int (*pscore)[3], int student)
{
	int avg[5] = { 0, 0, 0, 0, 0 };
	int avg_entire = 0;

	for (int i = 0; i < student; i++)	//각 학생의 평균점수를 구하는 반복문.
	{
		for (int j = 0; j < 3; j++)
		{
			avg[i] += pscore[i][j];
		}
		avg[i] /= 3;
	}

	for (int i = 0; i < 5; i++)	// 과목당 평균성적의 전체학생 평균을 구하는 반복문.
	{
		avg_entire += avg[i];
	}

	avg_entire /= 5;

	swap(avg);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", avg[i]);
		if (avg[i] >= avg_entire)
			printf("(합격)\n");
		else
			printf("(불합격)\n");
	}
}

void swap(int* pele)
{
	for (int j = 0; j < 4; j++)	// avg[5](학생들의 전과목 평균성적)을 내림차순으로 정렬.
	{
		for (int i = 0; i < 4; i++)
		{
			if (pele[i] < pele[i + 1])
			{
				int temp = pele[i];
				pele[i] = pele[i + 1];
				pele[i + 1] = temp;
			}
		}
	}
}
