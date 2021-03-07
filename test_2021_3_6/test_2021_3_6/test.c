#define _CRT_SECURE_NO_WARNINGS   1

//#include<stdio.h>
//main()
//{
//	printf("Hello world");
//}
//#include<stdio.h>
//#define N 5
//int main()
//{
//	int i = 0;
//	int a[N];
//	for (i = 0; i <= N; i++)
//
//	{
//		a[i] = 0;
//		printf("%d\n", a[i]);
//	}
//	return 0;
//
//}
//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = a++ + ++b;
//	printf("%d\n", c);
//	return 0;
//
//}
//#include<stdio.h>
//int main()
//{ 
//	int a = 0215;
//	printf("%d\n", a);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 9;
//	int b = 7;
//	int c = 0;
//	c = a << 4 | b;
//	printf("%d\n", c);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	/*int a = 5;
//	int* p = &a;
//	printf("%d\n", ++(*p));
//	return 0;*/
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int* p = arr;
//	printf("%d\n", *(p++));
//	printf("%d\n", *p);
//	return 0;
//}
//#include<stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 2;
//	int b = 4;
//	int c = Add(a, b);
//	printf("%d\n", c);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char arr[5] = "aa b\n";
//	int i = 0;
//	int count1 = 0;
//	int count2 = 0;
//	int count3 = 0;
//	for (i = 0; i < 5; i++)
//	{
//		switch (arr[i])
//		{
//		case 'b':
//			count1++;
//			break;
//		case 'a':
//			count1++;
//			break;
//		case '\n':
//			count2++;
//			break;
//		case ' ':
//			count3++;
//			break;
//		}
//	}
//	printf("%d %d %d", count1, count2, count3);
//	return 0;
//}
//
//#include<stdio.h>
//#define IF {if(
//#define THEN ){
//#define ELSE }else{
//#define FI }}
//int main()
//{
//	int x = 0;
//	int y = 1;
//	IF x == 0
//	THEN IF y == 0
//		THEN printf("dajia\n");
//	FI
//		ELSE printf("dagu\n");
//	FI
//		return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[3][2] = { 1, 2, 3, 4, 5, 6 };
//	printf("%d\n", *arr[1]);
//	return 0;
//}
#include<stdio.h>
int main()
{
	int n = 4423894;
	//int arr1[10];
	int arr2[10];
	int i = 0;
	int j = 0;
	int k = 0;
	//while(n)
	//{
	//	arr1[i] = n % 8;
	//	n = n / 8;
	//	i++;
	//}
	//for (k = i-1; k >= 0; k--)
	//{
	//	//printf("0");
	//	printf("%d", arr1[k]);
	//}
	// n = 1234;
	while (n)
	{
		arr2[j] = n % 16;
		n = n / 16;
		j++;
	}
	/*k = j - 1;
	while (k+1)
	{
		if (arr2[k]>9)
				{
					printf("%c", arr2[k] + 55);
				}
				else
				{
					printf("%d", arr2[k]);
				}
		k--;
	}*/
	for (k = j - 1; k >= 0; k--);
	{
		if (arr2[k]>9)
		{
			printf("%c", arr2[k] + 55);
		}
		else
		{
			printf("%d", arr2[k]);
		}
	}
	return 0;

}
//#include<stdio.h>
//int main()
//{
//	int n = 1234;
//	printf("0");
//	printf("%o ", n);
//	printf("0X");
//	printf("%x", n);
//	
//	return 0;
//}
//for (j = 0; j < 10; j++)
//{
//	switch (arr2[j])
//	{
//	case 10:
//		arr2[j] = 'A';
//		break;
//	case 11:
//		arr2[j] = 'B';
//		break;
//	case 12:
//		arr2[j] = 'C';
//		break;
//	case 13:
//		arr2[j] = 'D';
//		break;
//	case 14:
//		arr2[j] = 'E';
//		break;
//	case 15:
//		arr2[j] = 'F';
//		break;
//	default :
//		arr2[j] = arr2[j];
//		break;
//	}
//}

//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	printf("%c\n", a + 55);
//	return 0;
//}
