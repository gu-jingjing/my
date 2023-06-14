#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//20. 有效的括号
// 支持动态增长的栈
typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// 栈顶
	int capacity;  // 容量 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}


// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);


		if (tmp == NULL)
		{
			printf("realloc failed");
			return;
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}


	ps->a[ps->top] = data;
	ps->top++;
}


// 出栈 
void StackPop(Stack* ps)
{
	if (ps->top == 0)
	{
		return;
	}
	ps->top--;
}


// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->top == 0;
}


// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	if (ps->top == 0)
	{
		return -1;
	}


	return ps->a[ps->top - 1];
}

#include<string.h>

bool isValid(char* s) {
	Stack st;
	StackInit(&st);
	int len = strlen(s);
	while (len)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}
		if (*s == ')' || *s == ']' || *s == '}')
		{
			if (StackEmpty(&st))
			{
				return false;
			}

			char tmp = StackTop(&st);
			StackPop(&st);

			if ((tmp == '(' && *s == ')')
				|| (tmp == '[' && *s == ']')
				|| (tmp == '{' && *s == '}'))
			{
				;
			}
			else
			{
				return false;
			}
		}
		s++;
		len--;
	}

	if (!StackEmpty(&st))
	{
		return false;
	}
	return true;

}