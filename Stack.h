//
//  Stack.h
//  stack
//
//  Created by Junroot on 2016. 8. 18..
//  Copyright © 2016년 ROOT. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *head;

int StackInit()
{
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return 0;
}

int StackPush(int value)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->value = value;
    newnode->next = head->next;
    head->next = newnode;
    return 0;
}

int StackPop()
{
    if (head->next == NULL) return -1;
    Node* pointnode = head->next;
    head->next = pointnode->next;
    free(pointnode);
    return 0;
}

int StackTop()
{
    if(head->next == NULL) return -1;
    return head->next->value;
}

int FreeStack()
{
    while(StackPop()!=-1);
    return 0;
}

#endif /* Stack_h */
