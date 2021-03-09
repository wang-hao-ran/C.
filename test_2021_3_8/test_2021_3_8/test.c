#define _CRT_SECURE_NO_WARNINGS   1

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[100];
//	int k = 0;
//	int j = 0;
//	gets(arr);
//	int i = strlen(arr);
//	int m = i - 1;
//	for (k = i-1; k>=0; k--)
//	{
//		if (arr[k] == ' ')
//		{
//			for (j = k + 1; j <= m; j++)
//
//			{
//				printf("%c", arr[j]);
//				if (j == (i - 1))
//				{
//					printf(" ");
//				}
//			}
//			m = k ;
//		}
//		if (k == 0)
//		{
//			for (j = 0; j < m; j++)
//			{
//				printf("%c", arr[j]);
//			}
//			
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char arr[3] = ". .";
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 0; 
//	int b = 0;
//	printf("请输入a,b的值：\n");
//	scanf("%d%d", &a, &b);
//	int i = 1;
//	while ((a*i) % b != 0)
//	{
//		i++;
//	}
//	printf("%d\n", a*i);
//	return 0;
//}

#include<stdio.h>
void reverse(char* left, char* right)
{
	char tmp;
	while (left < right)//不能用*left<*right进行比较，因为这样比较的是
		//字母的阿斯克码值,有不确定性,要用地址比较
	{                    
		tmp = *left;
		*left = *right;
		*right = tmp;
		right--;
		left++;
	}
}
int main()
{
	char arr[100];
	gets(arr);
	int len = strlen(arr);
	reverse(arr, arr + len - 1);
	char* start = arr;
	char* end = arr;
	while (*start)
	{
		end = start;
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		reverse(start, end - 1);
		if (*end == ' ')
		{
			start = end + 1;
		}

		else
		{
			start = end;
		}
	}
	printf("%s\n", arr);
	return 0;
}