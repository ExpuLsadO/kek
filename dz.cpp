#define _CRT_SECURE_NO_WARNINGS


#include <Windows.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>

char* get_strng(char z = -1)
{
	char* strng = (char*)malloc(sizeof(char));

	if (z == -1)
	{
		char c = getchar();

		while (c == ' ' || c == '\t' || c == '\n')
		{

			c = getchar();

		}
		strng[0] = c;
	}
	else
		strng[0] = z;

	int i;
	for (i = 0; strng[i] != '\n'; ++i)
	{

		strng = (char*)realloc(strng, sizeof(char) * (i + 2));
		strng[i + 1] = getchar();

	}
	strng[i] = '\0';
	return strng;
}


int str_cmp(char* a, char* b)
{
	int k = 1;
	for (int i = 0; a[i] >= 0 || b[i] >= 0; ++i)
	{
		if (a[i] != b[i])
		{
			k = 0;
			break;
		}
	}
	return k;
}

void print_set(int set_num, char** set, int num)
{
	
	printf("Set  number %d: {", set_num);

	for (int i = 0; i <= num; i++)
	{
		if (i == num)
			printf("%s}\n", set[i]);
		else
			printf("%s, ", set[i]);
	}

	
	
}


char** add_elem(int set_num, char** set, int* num)
{
	printf("\nEnter new element of set number %d: ", set_num);
	
	set = (char**)realloc(set, sizeof(char*) * (++ *num + 1));
	set[*num] = get_strng();
	
	

	
	print_set(set_num, set, *num);



	
	return set;
}

char** delete_elem(int set_num, char** set, int* num)
{
	printf("\nWhich element of the set number %d to remove ? ", set_num);

	int del_num;
	scanf("%d", &del_num);

	char** new_set = (char**)malloc(sizeof(char*) * *num);
	

	for (int i = 0; i < del_num - 1; ++i)
	{
		new_set[i] = set[i];
	}

	for (int i = del_num ; i <= *num; ++i)
	{
		new_set[i - 1] = set[i];
	}

	--* num;
	
	print_set(set_num, new_set, *num);




	
	return new_set;
}

char** get_set(int set_num, int* num)
{
	printf("Enter set number %d(example {1,2,3}): {", set_num);
	char** set = (char**)malloc(sizeof(char*) * 2);
	
	


	
	char c = getchar();
	
	set[*num] = (char*)malloc(sizeof(char));
	while (c != '}')
	{
		int k = 0;
		while (c != ',' && c != '}')
		{
			
			set[*num][k] = c;
		
			set[*num] = (char*)realloc(set[*num], sizeof(char) * (++k + 1));
			
			
			c = getchar();
			
		}
		set[*num][k] = '\0';

		if (c == '}') 
			break;

		set = (char**)realloc(set, sizeof(char*) * (++*num + 1));
		set[*num] = (char*)malloc(sizeof(char));
		c = getchar();
	}

	for (int i = 0; i <= *num; ++i)
	{
		for (int j = i; j < *num; ++j)
		{
			
			if (  str_cmp(set[i], set[j + 1]))
			{
				printf("\nThe set does not meet the requirements: items  number %d and  number %d are the same\n\nTry again\n\n", i + 1, j + 2);
				*num = 0;
				while (getchar() != '\n');
				system("pause");
				system("cls");
				set = get_set(set_num, num);
			}

		}
	}

	return set;
}


int set_cmp(char** set1, int num1, char** set2, int num2)
{
	int z = -1;
	if (num1 == num2)
	{
		for (int i = 0; i <= num1; ++i)
		{
			for (int j = 0; j <= num1; ++j)
			{
				if (str_cmp(set1[i], set2[j])) z++;//1 - равны
			}
		}

		if (z == num1)
			return 1;
		else
			return 0;
	}
	else
	{
		return 0; // 0 - множества не одинаковы
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num1 = 0;
	char** set1 = get_set(1, &num1);

	while (getchar() != '\n');

	int num2 = 0;
	char** set2 = get_set(2, &num2);
	while (set_cmp(set1, num1, set2, num2)) 
	{
		printf("\nSets are the same!\n\nTry one more time!\n\n");
		num2 = 0;
		set2 = get_set(2, &num2);
		set_cmp(set1, num1, set2, num2);
	}

	
	int answ;
	printf("\n0 - Exit\n\n1 - Add element\n\n2 - Delete element\n\n3 - Set output\n\nEnter the command: ");
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
			system("pause");
			system("cls");
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
