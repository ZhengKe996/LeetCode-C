#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node {
    ElementType data;
    struct Node *next;
} Node, *LinkedList;

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

void PrintList(LinkedList Node) {
    Node = Node->next; // 头结点不打印

    while (Node != NULL) {
        printf("%3d", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

LinkedList GetElement(LinkedList Node, int index) {
    int i = 0;

    if (index < 0) return NULL;
    while (Node && i < index) {
        Node = Node->next;
        i++;
    }
    return Node;
}

LinkedList LocateElement(LinkedList Node, ElementType value) {
    while (Node) {
        if (Node->data == value)return Node;
        Node = Node->next;
    }
    return NULL;
}

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

    return 0;
}
