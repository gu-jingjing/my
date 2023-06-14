#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//20. ��Ч������
// ֧�ֶ�̬������ջ
typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// ջ��
	int capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}


// ��ջ 
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


// ��ջ 
void StackPop(Stack* ps)
{
	if (ps->top == 0)
	{
		return;
	}
	ps->top--;
}


// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return ps->top == 0;
}


// ��ȡջ��Ԫ�� 
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