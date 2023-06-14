#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>


//232. 用栈实现队列
typedef struct
{
    int* a;
    int size;
}Stack;

typedef struct {
    Stack pushstack;
    Stack popstack;

} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->pushstack.a = (int*)malloc(sizeof(int) * 100);
    obj->popstack.a = (int*)malloc(sizeof(int) * 100);

    obj->pushstack.size = 0;
    obj->popstack.size = 0;

    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->pushstack.a[obj->pushstack.size] = x;
    obj->pushstack.size++;

}

int myQueuePop(MyQueue* obj) {
    assert(obj->pushstack.size || obj->popstack.size);
    if (obj->popstack.size == 0)
    {
        //popstack为空
        int i = obj->pushstack.size;
        int k = 0;
        while (i)
        {
            obj->popstack.a[k] = obj->pushstack.a[i - 1];
            k++;
            i--;
        }
        obj->pushstack.size = 0;
        obj->popstack.size = k;
    }

    int ret = obj->popstack.a[obj->popstack.size - 1];
    obj->popstack.size--;
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    assert(obj->pushstack.size || obj->popstack.size);
    if (obj->popstack.size == 0)
    {
        //popstack为空
        int i = obj->pushstack.size;
        int k = 0;
        while (i)
        {
            obj->popstack.a[k] = obj->pushstack.a[i - 1];
            k++;
            i--;
        }
        obj->pushstack.size = 0;
        obj->popstack.size = k;
    }
    return obj->popstack.a[obj->popstack.size - 1];

}

bool myQueueEmpty(MyQueue* obj) {
    return !(obj->pushstack.size || obj->popstack.size);

}

void myQueueFree(MyQueue* obj) {
    free(obj->pushstack.a);
    obj->pushstack.a == NULL;
    free(obj->popstack.a);
    obj->popstack.a == NULL;

    free(obj);

}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

//622. 设计循环队列
typedef struct {
    int* a;
    int front;
    int rear;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = obj->rear = 0;
    obj->k = k;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % (obj->k + 1) == obj->front;

}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->a[obj->rear] = value;
    ++obj->rear;
    obj->rear %= (obj->k + 1);

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    ++obj->front;
    obj->front %= (obj->k + 1);

    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        return obj->a[obj->front];
    }

}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        return obj->a[(obj->rear + obj->k) % (obj->k + 1)];
    }

}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    obj->a = NULL;
    free(obj);

}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/

//225. 用队列实现栈
typedef struct QNode
{
    struct QNode* next;
    int data;
}QNode;
typedef struct
{
    QNode* head;
    QNode* tail;
}Queue;
typedef struct {
    Queue queue1;
    Queue queue2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->queue1.head = obj->queue1.tail = NULL;
    obj->queue2.head = obj->queue2.tail = NULL;

    return obj;
}

QNode* BuyQNode()
{
    QNode* tmp = (QNode*)malloc(sizeof(QNode));
    if (tmp == NULL)
    {
        printf("malloc failed");
    }
    return tmp;
}
void QueuePush(Queue* pq, int x)
{
    QNode* newnode = BuyQNode();
    newnode->data = x;
    newnode->next = NULL;
    if (pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
        return;
    }

    pq->tail->next = newnode;
    pq->tail = newnode;
}

int QueuePop(Queue* pq)
{
    if (pq->head == NULL)
    {
        return -1;
    }
    int tmp = pq->head->data;
    QNode* del = pq->head;
    pq->head = pq->head->next;
    free(del);
    del = NULL;

    return tmp;
}

bool myStackEmpty(MyStack* obj) {
    if (obj->queue1.head == NULL
        && obj->queue2.head == NULL)
    {
        return true;
    }
    return false;
}

void myStackPush(MyStack* obj, int x) {
    QueuePush(&(obj->queue1), x);


}

int myStackPop(MyStack* obj) {
    if (myStackEmpty(obj))
    {
        return;
    }

    QNode* tmp = obj->queue1.head;
    while (tmp->next != NULL)
    {
        QueuePush(&(obj->queue2), QueuePop(&(obj->queue1)));
        tmp = obj->queue1.head;
    }
    int ret = QueuePop(&(obj->queue1));

    QNode* cur = obj->queue2.head;
    while (cur)
    {
        QueuePush(&(obj->queue1), QueuePop(&(obj->queue2)));
        cur = obj->queue2.head;
    }

    return ret;
}

int myStackTop(MyStack* obj) {
    return obj->queue1.tail->data;

}

void QueueFree(Queue* pq)
{
    QNode* cur = pq->head;
    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
}

void myStackFree(MyStack* obj) {
    QueueFree(&(obj->queue1));
    QueueFree(&(obj->queue2));

    free(obj);


}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/