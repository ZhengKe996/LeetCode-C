#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LinkNode {
    ElementType data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *top;
} LinkStack;

/**
 * 初始化栈
 * @param stack
 */
void InitStack(LinkStack &stack) {
    stack.top = (LinkNode *) malloc(sizeof(LinkStack));
    stack.top->next = NULL;
}

/**
 * 栈是否为空
 * @param stack
 * @return
 */
bool IsEmpty(LinkStack stack) {
    return stack.top->next == NULL;
}

/**
 * 入栈
 * @param stack
 * @param x
 */
void Push(LinkStack &stack, ElementType x) {
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = x;
    newNode->next = stack.top;
    stack.top = newNode;
}

/**
 * 出栈
 * @param stack
 * @param x
 * @return
 */
bool Pop(LinkStack &stack, ElementType &x) {
    if (stack.top == NULL)return false;

    LinkNode *p = stack.top;
    x = p->data;
    if (stack.top->next == NULL)return false;
    stack.top = stack.top->next;
    free(p);
    return true;
}

/**
 * 取栈顶
 * @param stack
 * @param x
 * @return
 */
bool GetTop(LinkStack &stack, ElementType &x) {
    if (stack.top == NULL)return false;
    x = stack.top->data;
    return true;
}

int main() {
    LinkStack stack;
    InitStack(stack);
    bool flag;
    flag = IsEmpty(stack);
    if (flag) {
        printf("stack is empty\n");
    }

    Push(stack, 3);//入栈元素3
    Push(stack, 4);//入栈元素4
    Push(stack, 5);
    ElementType m;
    flag = GetTop(stack, m);//获取栈顶元素
    if (flag) {
        printf("get top %d\n", m);
    }
    flag = Pop(stack, m);//弹出栈顶元素
    if (flag) {
        printf("pop element %d\n", m);
    }
    return 0;
    return 0;
}
