#include <stdio.h>

#define MaxSize 50

typedef int ElementType;
typedef struct Stack {
    ElementType data[MaxSize];
    int top;// 栈顶
} SqStack;

/**
 * 初始化栈
 * @param Stack
 */
void InitStack(SqStack &stack) {
    stack.top = -1;
}

/**
 * 是否为空栈
 * @param stack
 * @return
 */
bool IsEmpty(SqStack &stack) {
    if (stack.top == -1)return true;
    else return false;
}

/**
 * 入栈
 * @param stack
 * @param x
 * @return
 */
bool Push(SqStack &stack, ElementType x) {
    if (stack.top == MaxSize - 1)return false; // 栈满了
    stack.data[++stack.top] = x;
    return true;
}

/**
 * 出栈
 * @param stack
 * @param x
 * @return
 */
bool Pop(SqStack &stack, ElementType &x) {
    if (-1 == stack.top)return false;
    x = stack.data[stack.top--];
    return true;
}

bool GetTop(SqStack &stack, ElementType &x) {
    if (-1 == stack.top)return false;
    x = stack.data[stack.top];
    return true;
}

int main() {
    SqStack S;
    InitStack(S);
    bool flag;
    flag = IsEmpty(S);
    if (flag) {
        printf("stack is empty\n");
    }
    Push(S, 3);//入栈元素3
    Push(S, 4);//入栈元素4
    Push(S, 5);
    ElementType m;
    flag = GetTop(S, m);//获取栈顶元素
    if (flag) {
        printf("get top %d\n", m);
    }
    flag = Pop(S, m);//弹出栈顶元素
    if (flag) {
        printf("pop element %d\n", m);
    }
    return 0;
    return 0;
}
