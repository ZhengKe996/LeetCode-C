#include <stdio.h>

#define MaxSize 5
typedef int ElementType;
typedef struct SqQueue {
    ElementType data[MaxSize]; // 存储MaxSize-1个元素
    int front, rear;// 队头下标、队尾下标
} SqQueue;

/**
 * 初始化队列
 * @param queue
 */
void InitQueue(SqQueue &queue) {
    queue.rear = queue.front = 0;
}

/**
 * 当尾==头时，循环队列为空
 * @param queue
 * @return
 */
bool IsEmpty(SqQueue &queue) {
    if (queue.front == queue.rear) return true;
    else return false;
}

/**
 * 循环队列入队操作
 * @param queue 队列地址
 * @param X 需要入队的元素
 * @return
 */
bool EnQueue(SqQueue &queue, ElementType X) {
    if ((queue.rear + 1) % MaxSize == queue.front) return false; // 队列满了 插入不成功
    queue.data[queue.rear] = X; // 队尾入队
    queue.rear = (queue.rear + 1) % MaxSize;
    return true;
}

/**
 * 循环队列出队操作
 * @param queue 队列地址
 * @param X 需要出队元素的地址
 * @return
 */
bool DeQueue(SqQueue &queue, ElementType &X) {
    if (queue.rear == queue.front) return false;
    X = queue.data[queue.front]; // 队头出队
    queue.front = (queue.front + 1) % MaxSize;
    return true;
}


int main() {
    SqQueue queue;
    InitQueue(queue);
    bool ret;
    ret = IsEmpty(queue);
    if (ret) {
        printf("SqQueue is Empty\n");
    } else {
        printf("SqQueue is not Empty\n");
    }
    EnQueue(queue, 3);
    EnQueue(queue, 4);
    EnQueue(queue, 5);
    ret = EnQueue(queue, 6);
    ret = EnQueue(queue, 7);
    if (ret) {
        printf("EnQueue success\n");
    } else {
        printf("EnQueue failed\n");
    }
    ElementType element;//存储出队元素
    ret = DeQueue(queue, element);
    if (ret) {
        printf("DeQueue success\n");
    } else {
        printf("DeQueue failed\n");
    }
    ret = EnQueue(queue, 8);
    if (ret) {
        printf("EnQueue success\n");
    } else {
        printf("EnQueue failed\n");
    }
    return 0;
}
