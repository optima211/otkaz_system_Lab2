#include<omp.h>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<conio.h>

const int dimention = 1000; //����������� ������������ ��������

int main()
{
	using namespace std;
	printf("Exercise 1:\n");
	printf("Master-thread: init parallel execution\n");
#pragma omp parallel num_threads(2)

	{
		//������� ���� ����������� �����
		for (int i = 1; i < 100; i++)

		//����� ������������ �����
		//����� ������������ ������������ �����
#pragma omp single
		{
			printf("Thread %i: scalar production = %d\n", omp_get_thread_num(), i);
		}
	}

	printf("Master-thread: end parallel execution\n\n\n");
	system("pause");

	long double x[dimention], y[dimention];
	//�������������� �������� �������� x � y
	for (int i = 0; i < dimention; i++) 
	{
		x[i] = (float)rand() / 32536.0 * 3.0;
		y[i] = (float)rand() / 32536.0 * 3.0;
	}

	printf("Exercise 4:\n");
	printf("Master-thread: init parallel execution\n");
	#pragma omp parallel num_threads(2)
	
	{
		//������ �����
		long double sum = 0;
		//���������� ���������� ������������
		for (int i = 0; i < dimention; i++) sum += x[i] * y[i];

		//����� ���������� ������������
		printf("Thread %i: scalar production is %LF\n", omp_get_thread_num(), sum);
	}

	printf("Master-thread: end parallel execution\n\n\n");
	system("pause");



	printf("Exercise 5.1:\n");
	printf("Master-thread: init parallel execution\n");
	#pragma omp parallel num_threads(4)
	{
		//������ �����
		long double sum = 0;
		//���������� ���������� ������������
		for (int i = 0; i < dimention; i++) sum += x[i] * y[i];
		//����� ���������� ������������
		#pragma omp master
		{
			printf("Master-thread: scalar production = %LF\n", sum);
		}

	}

	printf("Master-thread: end parallel execution\n\n\n");
	system("pause");



	printf("Exercise 5.2:\n");
	printf("Master-thread: init parallel execution\n");
	#pragma omp parallel num_threads(4)
	{
		//������ �����
		long double sum = 0;
		//���������� ���������� ������������
		for (int i = 0; i < dimention; i++) sum += x[i] * y[i];

		//����� ���������� ������������
		//����� ������������ ������������ �����
		#pragma omp single
		{
			printf("Thread %i: scalar production = %LF\n", omp_get_thread_num(), sum);
		}

	}

	printf("Master-thread: end parallel execution\n");
	system("pause");
}