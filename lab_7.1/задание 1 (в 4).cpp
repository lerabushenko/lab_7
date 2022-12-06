#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

int menu()
{
	int ch;
	do
	{
		printf("menu\n");
		printf("1 - exercise 1\n");
		printf("2 - exercise 2\n");
		printf("3 - exercise 3\n");
		printf("4 - exercise 4\n");
		printf("5 - exercise 5\n");
		printf("6 - exercise 6\n");
		printf("7 - exercise 7\n");
		printf("8 - exercise 8\n");
		printf("9 - exercise 9\n");
		printf("10 - exit\n");
		printf("vvedite nomer\n");
		scanf_s("%d", &ch);
	} while (ch > 10);
	return ch;
}

int ex1_vvod(int** a, int n, int m)
{
	srand(time(0));
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			a[i][j] = -10 + rand() % 70;
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void ex1_sum(int** a, int n, int m)
{
	int k(0), sum(0);
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m && k<m; j++)
		{
			if (a[i][j] > 0)
			{
				k++;
				sum += a[i][j];
			}
			else
			{
				sum = 0;
				k = m;
			}
		}
		if (k == m && sum != 0)
		{
			for (int i(0); i < n; i++)
			{
				for (int j(0); j < m; j++)
				{
					a[i][j] -= sum;
				}
			}
			k = m + 1;
		}
		else
			k = 0;
	}
}

void ex1_vivod(int** a, int n, int m)
{
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void ex1()
{
	int n(0), m(0), sum(0);
	printf("vvedite kolvo strok\n");
	scanf_s("%d", &n);
	printf_s("vvedite kolvo stolbcov\n");
	scanf_s("%d", &m);
	int** a;
	a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		*(a + i) = new int[m];
	}
	printf("massiv\n");
	ex1_vvod(a, n, m);
	ex1_sum(a, n, m);
	printf("new massiv\n");
	ex1_vivod(a, n, m);
	for (int i(0); i < n; i++)
	{
		delete[]a[i];
	}
}

void ex2()
{
	char str[100];
	printf("vvedite stroky\n");
	getchar();
	fgets(str, 100, stdin);
	int sum(0), k(0);
	for (int i(0); i < strlen(str); i++)
	{
		if (isalpha(str[i]))
		{
			sum += (int)(str[i]);
		}
		else
		{
			k++;
			printf("summa slova %d = %d\n", k, sum);
			sum = 0;
		}
	}
}

void ex3()
{
	char str[100], * nachalo, * konez;
	int kolvo(0), dlina(0), k(0);
	printf("vvedite stroky\n");
	getchar();
	fgets(str, 100, stdin);
	for (int i(0); i < strlen(str); i++)
	{
		if (isalpha(str[i]))
		{
			dlina++;
		}
		else
		{
			konez = &str[i - 1];
			nachalo = konez - dlina + 1;
			for (konez, nachalo, k=0; nachalo < konez+1; nachalo++, konez--)
			{
				if (*konez != *nachalo)
				{
					k++;
				}
			}
			if (k == 0)  
			{
				kolvo++;
			}
			dlina = 0;
		}
	}
	printf("kol-vo palindromov: %d\n", kolvo);
}

void ex4()
{
	char str[100], * nachalo, * konez;
	int dlina(0);
	printf("vvedite stroky\n");
	getchar();
	fgets(str, 100, stdin);
	for (int i(0); i < strlen(str); i++)
	{
		if (isalpha(str[i]))
		{
			dlina++;
		}
		else
		{
			konez = &str[i - 1];
			nachalo = konez - dlina + 1;
			if (*konez == 'e')
			{
				for (nachalo; nachalo < konez + 1; nachalo++)
				{
					*nachalo = ' ';
				}
			}
			dlina = 0;
		}
	}
	do {
		char* ptr = strstr(str, "  ");    
		if (!ptr) break;
		strcpy(ptr, ptr + 1);
	} while (1);
	printf("new stroka\n");
	puts(str);
}

void ex5()
{
	char str[100], slovo[50];
	printf("vvedite stroky\n");
	getchar();
	fgets(str, 100, stdin);
	printf("vvedite slovo\n");
	fgets(slovo, 50, stdin);
	int k(0);
	for (int i(0); i < strlen(str); i++)
	{
		if (str[i] == slovo[0])
		{
			for (int j(0); j < strlen(slovo); j++)
			{
				if (str[i + j] == slovo[j])
					k++;
			}
			if (k == strlen(slovo) - 1)
			{
				for (int q(0); q <= k; q++)
				{
					*(str + i + q) = ' ';
				}
			}
			k = 0;
		}
	}
	do {
		char* ptr = strstr(str, "  ");
		if (!ptr) break;
		strcpy(ptr, ptr + 1);
	} while (1);
	printf("new stroka\n");
	puts(str);
}

void ex6()
{
	char str[100];
	int dlina(0), k(0);
	printf("vvedite stroky\n");
	getchar();
	fgets(str, 100, stdin);
	for (int i(0); i < strlen(str); i++)
	{
		if (str[i] == 'm' && str[i + 1] == 'i' && str[i + 2] == 's' && str[i + 3] == 'h' || str[i] == 'r' && str[i + 1] == 'o' && str[i + 2] == 'z' && str[i + 3] == 'h' || str[i] == 'd' && str[i + 1] == 'o' && str[i + 2] == 'c' && str[i + 3] == 'h')
		{
			for (int k = strlen(str) + 1; k > i + 3; k--)
			{
				str[k] = str[k - 1];
			}
			str[i + 4] = '*';
		}
	}
	printf("new stroka\n");
	puts(str);
}

void ex7()
{
	char str[100], * nachalo, * konez;
	int kolvo(0), dlina(0), k(0);
	printf("vvedite stroky\n");
	getchar();
	fgets(str, 100, stdin);
	for (int i(0); i < strlen(str); i++)
	{
		if (isalpha(str[i]))
		{
			dlina++;
		}
		else
		{
			konez = &str[i - 1];
			nachalo = konez - dlina + 1;
			for (nachalo, k = 0; nachalo < konez + 1; nachalo++)
			{
				if (*nachalo == 'a')
				{
					k++;
				}
			}
			if (k > 1)
			{
				kolvo++;
			}
			dlina = 0;
		}
	}
	printf("kol-vo slov: %d\n", kolvo);
}

void ex8()
{
	char str[100], * nachalo, * konez, * vspom(0);
	int kolvo(0), dlina(0), k(0), max(0);
	printf("vvedite stroky\n");
	getchar();
	fgets(str, 100, stdin);
	for (int i(0); i < strlen(str); i++)
	{
		if (isalpha(str[i]))
		{
			dlina++;
		}
		else
		{
			konez = &str[i - 1];
			nachalo = konez - dlina + 1;
			if (max < dlina)
			{
				max = dlina;
				vspom = nachalo;
			}
			dlina = 0;
		}
	}
	int j = 0;
	while (j<dlina)
	{
		putchar(*vspom);
		*vspom++;
		j++;
	}
	printf("\n");
}

void ex9()
{
	char str[100], * nachalo, * konez;
	int kolvo(0), dlina(0), k(0);
	printf("vvedite stroky\n");
	getchar();
	fgets(str, 100, stdin);
	for (int i(0); i < strlen(str); i++)
	{
		if (isalpha(str[i]))
		{
			dlina++;
		}
		else
		{
			konez = &str[i - 1];
			nachalo = konez - dlina + 1;
			if (*konez != *nachalo)
			{
				k++;
			}
			if (k == 0)
			{
				kolvo++;
				int j = 0;
				while (j<dlina)
				{
					putchar(*nachalo++);
					j++;
			    }
				printf("\n");
			}
			dlina = 0;
			k = 0;
		}
	}
	printf("kol-vo slov: %d\n", kolvo);
}

void main()
{
	while (1)
	{
		switch (menu())
		{
		case 1:
			ex1();
			break;
		case 2:
			ex2();
			break;
		case 3:
			ex3();
			break;
		case 4:
			ex4();
			break;
		case 5:
			ex5();
			break;
		case 6:
			ex6();
			break;
		case 7:
			ex7();
			break;
		case 8:
			ex8();
			break;
		case 9:
			ex9();
			break;
		case 10:
			return;
			break;
		}
	}
}