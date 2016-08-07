//
//  main.cpp
//  ReverseLinkedList_Stack
//
//  Created by chenyufeng on 8/7/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

/**
 *  输入一个链表的头结点，从尾到头打印链表的每一个节点
 */
#include <iostream>

using namespace std;

typedef struct ListNode{

    int element;
    struct ListNode *next;
}Node;

void CreateLinkedList(Node **head);
void PrintList(Node *pNode);


int main(int argc, const char * argv[])
{
    Node *pList;
    CreateLinkedList(&pList);
    PrintList(pList);


    return 0;
}

/**
 *  指针是指向一个变量在内存中的地址；
 *  指针的指针是指向一个指针在内存中的地址；
 */
void CreateLinkedList(Node **head)
{
    cout<<"依次输入数字创建链表，输入<=0创建结束"<<endl;
    *head = (Node *)malloc(sizeof(Node));
    memset(*head, 0, sizeof(int));
    (*head)->next = NULL;

    Node *pInsert;
    Node *pMove;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = *head;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node)); 
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }
}

void PrintList(Node *pNode)
{
    /**
     *  注意这里，如果单链表为空（只有一个头结点），我也让它打印（打印成功）。只是里面没有元素，打出来是空的而已,所以在控制台上就是一行空的；
     */
    Node *pMove;
    pMove = pNode->next;
    while (pMove != NULL) {
        printf("%d ",pMove->element);
        pMove = pMove->next;
    }

    printf("\n%s函数执行，打印带头结点的单链表成功\n",__FUNCTION__);
}








