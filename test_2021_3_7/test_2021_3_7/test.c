#define _CRT_SECURE_NO_WARNINGS   1

//#include<stdio.h>
//int main()
//{
//	int n = 1234;
//	int arr1[10];
//	int arr2[10];
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	while(n)
//	{
//		arr1[i] = n % 8;
//		n = n / 8;
//		i++;
//	}
//	printf("0");
//	for (k = i-1; k >= 0; k--)
//	{
//	
//		printf("%d", arr1[k]);
//	}
//	 n = 1234;
//	 printf(" ");
//	 printf("0X");
//	while (n)
//	{
//		arr2[j] = n % 16;
//		n = n / 16;
//		j++;
//	}	
//	for (k = j - 1; k >= 0; k--)
//	{
// 		if (arr2[k]>9)
//		{
//			printf("%c", arr2[k] + 55);
//		}
//		else
//		{
//			printf("%d", arr2[k]);
//		}
//	}
//
//	return 0;
//
//}
//k = j - 1;
//while (k + 1)
//{
//	if (arr2[k]>9)
//	{
//		printf("%c", arr2[k] + 55);
//	}
//	else
//	{
//		printf("%d", arr2[k]);
//	}
//	k--;
//}	
//#include<stdio.h>
//int main()
//{
//	int a = 0XABCDEF;
//	printf("%15d", a);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	//printf("Hello world!\n");
//	printf("%d\n", printf("Hello world!\n"));
//	return 0;
//}
#include<stdio.h>
int main()
{
	int a = printf("Hello world!");
	printf("\n");
	printf("%d\n", a);
	return 0;
}