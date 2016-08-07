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
#include <stdlib.h>
#include <stack>

using namespace std;

typedef struct ListNode{
    int element;
    struct ListNode *next;
}Node;

void CreateLinkedList(Node **head);
void ReverseLinkedList(Node *pNode);

int main(int argc, const char * argv[])
{
    Node *pList;
    CreateLinkedList(&pList);
    ReverseLinkedList(pList);

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

    cin>>pInsert->element;
    pMove = *head;
    while (pInsert->element > 0)
    {
        pMove->next = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;

        cin>>pInsert->element;
    }
}

void ReverseLinkedList(Node *pNode)
{
    stack<Node *> nodes;

    // 要入栈的节点是真正链表的第一个结点，而不是头结点
    pNode = pNode->next;
    while (pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }

    while (!nodes.empty())
    {
        Node *top = nodes.top();
        cout<<top->element<<" ";
        nodes.pop();
    }
}
