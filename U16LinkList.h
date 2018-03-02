#ifndef __AIROB_LINKLIST_H
#define __AIROB_LINKLIST_H
/*=====================================
Include headers
=====================================*/
#include <stdio.h>
#include <stdlib.h>
#include "MyTypeTool.h"
/*=====================================
Global Constants
=====================================*/
/*=====================================
Global Macro
=====================================*/
typedef struct u16linknode
{
    uint16_t usData;
    int iID;
    struct u16linknode *stNext; 
}U16LKNode;

typedef struct u16linklist
{
    U16LKNode *stHead;
    int iLength;
    int iMaxSize;
}U16LinkList;

/*=====================================
Extern Variables
=====================================*/

/*=====================================
Extern Functions
=====================================*/
uint16_t getNodeData(U16LKNode *node);
uint16_t getNodeID(U16LKNode *node);
int getListLength(U16LinkList *list);
//constructre and destructre
bool LinkListCreate_us( U16LinkList *list,int size);
bool LinkListDestruct_us( U16LinkList *list);
//insert 
bool LinkListInsertByIndex_us( U16LinkList *list,int index,int id,uint16_t elem);
bool LinkListInsertToHead_us(  U16LinkList *list,int id,uint16_t elem);
bool LinkListInsertToTail_us(  U16LinkList *list,int id,uint16_t elem);
//remove
bool LinkListRemoveByIndex_us(  U16LinkList *list,int index);
bool LinkListRemoveByID_us( U16LinkList *list,int id);
//get node
U16LKNode *LinkListGetNodeByIndex( U16LinkList *list,int index );
U16LKNode *LinkListGetNodeByData( U16LinkList *list ,uint16_t data );
//get id
bool LinkListGetIDByData( U16LinkList *list,uint16_t data,int *ID);
//get index
int LinkListGetIndexByData( U16LinkList *list,uint16_t data);
uint8_t IsLinkListEmpty_us(U16LinkList *list);
uint8_t IsLinkListFull_us(U16LinkList *list);


#endif
