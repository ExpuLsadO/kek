#define _CRT_SECURE_NO_WARNINGS


#include <Windows.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>

int* add_elem(int set_num, int* set, int* num)
{
	printf("\nEnter new element of set number %d: ", set_num);
	
	set = (int*)realloc(set, sizeof(int) * (++ *num + 1));
	scanf("%d", &set[*num]);

	printf("\nNew set number %d: {", set_num);




	for (int i = 0; i <= *num; i++)
	{
		if (i == *num)
			printf("%d}\n", set[i]);
		else
			printf("%d,", set[i]);
	}
	return set;
}

int* delete_elem(int set_num, int* set, int* num)
{
	printf("\nWhich element of the set  number %d to remove ? ", set_num);
	int del_num;
	int* new_set = (int*)malloc(sizeof(int) * *num);
	scanf("%d", &del_num);

	for (int i = 0; i < del_num - 1; ++i)
	{
		new_set[i] = set[i];
	}

	for (int i = del_num ; i <= *num; ++i)
	{
		new_set[i - 1] = set[i];
	}

	printf("\nNew set  number %d: {", set_num);


	--* num;

	for (int i = 0; i <= *num; i++)
	{
		if (i == *num)
			printf("%d}\n", new_set[i]);
		else
			printf("%d,", new_set[i]);
	}
	return new_set;
}

int* get_set(int set_num, int* num)
{
	printf("Enter set  number %d(example {1,2,3}): {", set_num);
	int* set = (int*)malloc(sizeof(int));
	
	


	scanf("%d", &set[*num]);
	
	while (getchar() != '}')
	{

		set = (int*)realloc(set, sizeof(int) * (*num + 2)); 
		++* num;
		scanf("%d", &set[*num]);

		
	}

	for (int i = 0; i <= *num; ++i)
	{
		for (int j = i; j < *num; ++j)
		{
			
			if (set[i] == set[j + 1])
			{
				printf("\nThe set does not meet the requirements: items  number %d and  number %d are the same\n\nTry again\n\n", i + 1, j + 2);
				*num = 0;
				system("pause");
				system("cls");
				set = get_set(set_num, num);
			}

		}
	}

	return set;
}

void print_set(int set_num, int* set, int num)
{
	printf("\nSet  number %d: {", set_num);

	

	
	for (int i = 0; i <= num; i++)
	{
		if (i == num )
			printf("%d}\n", set[i]);
		else
			printf("%d,", set[i]);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num1 = 0;
	int* set1 = get_set(1, &num1);

	int num2 = 0;
	int* set2 = get_set(2, &num2);

	int answ;
	printf("0 - Exit\n\n1 - Add element\n\n2 - Delete element\n\n3 - Set output\n\nEnter the command: ");
	scanf("%d", &answ);
	while (answ)
	{
		if (answ == 1)
		{
			int set_num;
			system("pause");
			system("cls");
			printf("Which set should you add an element to? ");
			scanf("%d", &set_num);
			if (set_num == 1)
			{
				set1 = add_elem(set_num, set1, &num1);
			}
			else if (set_num == 2)
			{
				set2 = add_elem(set_num, set2, &num2);
			}
			else
			{
				printf("\n\nThere is no such set");
			}
		}
		else if (answ == 2)
		{
			int set_num;
			system("pause");
			system("cls");
			printf("From which set to remove an element? ");
			scanf("%d", &set_num);
			if (set_num == 1)
			{
				set1 = delete_elem(set_num, set1, &num1);
			}
			else if (set_num == 2)
			{
				set2 = delete_elem(set_num, set2, &num2);
			}
			else
			{
				printf("\n\nThere is no such set");
			}
		}
		else if (answ == 3)
		{
			print_set(1, set1, num1);
			print_set(2, set2, num2);
		}
		else
		{
			printf("\n\nThere is no such command");
		}

		system("pause");
		system("cls");
		printf("0 - Exit\n\n1 - Add element\n\n2 - Delete element\n\n3 - Set output\n\nEnter the command: ");
		scanf("%d", &answ);
	}

	
	return 0;
}
