#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//牛客网BC105
//#include <stdio.h>
//
//int main() {
//    int n = 0, m = 0;
//    scanf("%d %d", &n, &m);
//
//    int arr1[100] = { 0 };
//    int arr2[100] = { 0 };
//
//    int i = 0;
//    for (i = 0; i < n * m; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (i = 0; i < n * m; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//
//    int flag = 1;
//
//    for (i = 0; i < n * m; i++)
//    {
//        if (arr1[i] != arr2[i])
//        {
//            flag = 0;
//        }
//    }
//
//    if (flag)
//    {
//        printf("Yes\n");
//    }
//    else
//    {
//        printf("No\n");
//    }
//
//
//    return 0;
//}


//BC98 序列中删除指定数字
//#include <stdio.h>
//
//int main() {
//	int N = 0;
//	scanf("%d", &N);
//
//	int arr[50] = { 0 };
//
//	int i = 0;
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int pop = 0;
//	scanf("%d", &pop);
//
//	int num = 0;
//
//	int* next = arr;
//	int* tmp = arr;
//	int count = 0;
//	while (next < (arr + N))
//	{
//		while (*next == pop && next < (arr + N))
//		{
//			count++;
//			next++;
//		}
//
//		while (*next != pop && next < (arr + N))
//		{
//			*tmp = *next;
//			next++;
//			tmp++;
//		}
//		num = N - count;
//	}
//
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//BC54 获得月份天数
//#include <stdio.h>
//
//int main() {
//    int year = 0, month = 0;
//    while (scanf("%d %d", &year, &month) != EOF)
//    {
//
//        int day[12] = { 31,28,31,30,31,30,
//        31,31,30,31,30,31 };
//
//        if ((year % 4 == 0 && year && 100 != 0) || year % 400 == 0)
//        {
//            day[1] = 29;
//        }
//
//        printf("%d\n", day[month - 1]);
//    }
//    return 0;
//}

//BC37 网购
#include <stdio.h>

int main() {
    float price = 0.0;
    int  month = 0, day = 0, isdiscount = 0;
    scanf("%f %d %d %d", &price, &month, &day, &isdiscount);

    if (month == day && day == 11)
    {
        price *= 0.7;
        if (isdiscount)
        {
            price -= 50.0;
        }
    }

    if (month == day && day == 12)
    {
        price *= 0.8;
        if (isdiscount)
        {
            price -= 50.0;
        }
    }

    if (price < 0.0)
    {
        printf("%.2f", 0.00);
    }
    else
    {
        printf("%.2f", price);
    }

    return 0;
}