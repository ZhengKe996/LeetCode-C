#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node {
    ElementType data;
    struct Node *next;
} Node, *LinkedList;

/**
 * 链表头插法
 * @param Node
 */
void LinkedHeadInsert(LinkedList &Node) {
    Node = (LinkedList) malloc(sizeof(Node));
    Node->next = NULL;
    ElementType x;
    scanf("%d", &x);
    LinkedList s;
    while (x != 9999) {
        s = (LinkedList) malloc(sizeof(Node));
        s->data = x;
        s->next = Node->next;
        Node->next = s;
        scanf("%d", &x);
    }
}

/**
 * 链表尾插法
 * @param Node
 */
void LinkedTailInsert(LinkedList &Node) {
    Node = (LinkedList) malloc(sizeof(Node));
    Node->next = NULL;
    ElementType x;
    scanf("%d", &x);
    LinkedList s, r = Node;
    while (x != 9999) {
        s = (LinkedList) malloc(sizeof(Node));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL; // 最后一个节点的Next为NULL
}

/**
 * 打印链表
 * @param Node
 */
void PrintList(LinkedList Node) {
    Node = Node->next; // 头结点不打印
    while (Node != NULL) {
        printf("%3d", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/**
 * 获取Index位置结点地址
 * @param Node
 * @param index
 * @return
 */
LinkedList GetElement(LinkedList Node, int index) {
    int i = 0;
    if (index < 0) return NULL;
    while (Node && i < index) {
        Node = Node->next;
        i++;
    }
    return Node;
}

/**
 * 根据Value查结点地址
 * @param Node
 * @param value
 * @return
 */
LinkedList LocateElement(LinkedList Node, ElementType value) {
    while (Node) {
        if (Node->data == value)return Node;
        Node = Node->next;
    }
    return NULL;
}

/**
 * 在指定位置插入结点
 * @param Node
 * @param index
 * @param value
 * @return
 */
bool LinkedFrontInsert(LinkedList &Node, int index, ElementType value) {
    LinkedList p = GetElement(Node, index - 1);
    if (NULL == p)return false;

    LinkedList newNode;
    newNode = (LinkedList) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

/**
 * 删除Index结点位置元素
 * @param Node
 * @param index
 * @return
 */
bool LinkedRemoveByIndex(LinkedList &Node, int index) {
    LinkedList p = GetElement(Node, index - 1);
    if (NULL == p)return false;
    LinkedList temp;
    if (NULL == p->next) return false;
    temp = p->next;
    p->next = temp->next;
    free(temp);
    temp = NULL;
    return true;
}


int main() {
    LinkedList node;
    LinkedTailInsert(node);
    LinkedList res = GetElement(node, 2);
    printf("%d\n", res->data);
    LinkedFrontInsert(node, 2, 99);
    PrintList(node);
    LinkedRemoveByIndex(node, 4);
    PrintList(node);
    return 0;
}
