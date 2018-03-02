/*=====================================
Include headers
=====================================*/
#include "U16LinkList.h"

/*=====================================
Variables definition
=====================================*/

/*=====================================
Functions definition
=====================================*/
/*public*/
uint16_t getNodeData(U16LKNode *node);
uint16_t getNodeID(U16LKNode *node);
int getListLength(U16LinkList *list);
bool LinkListCreate_us( U16LinkList *list,int size);
bool LinkListDestruct_us( U16LinkList *list);
bool LinkListInsertByIndex_us( U16LinkList *list,int index,int id,uint16_t elem);
bool LinkListInsertToHead_us(  U16LinkList *list,int id,uint16_t elem);
bool LinkListInsertToTail_us(  U16LinkList *list,int id,uint16_t elem);
bool LinkListRemoveByIndex_us(  U16LinkList *list,int index);
bool LinkListRemoveByID_us( U16LinkList *list,int id);
U16LKNode *LinkListGetNodeByIndex( U16LinkList *list,int index );
U16LKNode *LinkListGetNodeByData( U16LinkList *list ,uint16_t data );
bool LinkListGetIDByData( U16LinkList *list,uint16_t data,int *ID);
int LinkListGetIndexByData( U16LinkList *list,uint16_t data);

uint8_t IsLinkListEmpty_us(U16LinkList *list);
uint8_t IsLinkListFull_us(U16LinkList *list);
/*private*/

/*=====================================
 Implementation of functions
 =====================================*/
uint16_t getNodeData(U16LKNode *node)
{
    return node->usData;
}
uint16_t getNodeID(U16LKNode *node)
{
    return node->iID;
}
int getListLength(U16LinkList *list)
{
    return list->iLength;
}
/****************************************************************************************/ 
//name:       bool LinkListCreate_us( U16LinkList *list,int size)
//describ:    Create link list
//called:     
//input:      list: link list pointer   size:maximum size of the list
//return:     succeed of failed(true or false)
/****************************************************************************************/
bool LinkListCreate_us( U16LinkList *list,int size)
{
    if(size<=0)
    {
        return false;
    }

    list->stHead = ( U16LKNode *)malloc(sizeof(U16LKNode)); 
    if(NULL == list->stHead)//malloc failed
    {
        return false;
    }
    //List head hasn't datas,and set list length = 0
    list->stHead->usData=0;//head Node haven't data
    list->stHead->iID=-1;//head ID =-1
    list->stHead->stNext=NULL;
    list->iLength = 0;
    list->iMaxSize = size;
    return true;
}
/****************************************************************************************/ 
//name:       bool LinkListDestruct_us( U16LinkList *list)
//describ:    destruct the link list
//called:     
//input:      list :link list pointer
//return:     succeed of failed(true or false)
/****************************************************************************************/
bool LinkListDestruct_us( U16LinkList *list)
{
    U16LKNode *deleteNode ;
    U16LKNode *nextNode ;
    int i;
    if(IsLinkListEmpty_us(list))
    {
        return false;
    }

    deleteNode = list->stHead;
    nextNode = deleteNode->stNext;


    for(i=0;i<list->iLength;i++)
    {
        nextNode = deleteNode->stNext;
        free(deleteNode);
        deleteNode = nextNode;
    }
    //deleteNode = NULL;
    //nextNode =NULL;
    list->iLength = 0;
    return true;
}


uint8_t IsLinkListEmpty_us(U16LinkList *list)
{
    if(list->iLength == 0)
    {
        return 1;
    }
    return 0;
}
uint8_t IsLinkListFull_us(U16LinkList *list)
{
    if(list->iLength >= list->iMaxSize)
    {
        return 1;
    }
    return 0;
}
/****************************************************************************************/ 
//name:       bool LinkListInsertByIndex_us( U16LinkList *list)
//describ:    Insert an new node(id,elem) to a link list.
//called:     
//input:      list :link list pointer,index:index of the link list, id: node id, elem :node dates
//return:     succeed of failed(true or false)
/****************************************************************************************/
bool LinkListInsertByIndex_us( U16LinkList *list,int index,int id,uint16_t elem)
{
    U16LKNode *preNode = list->stHead;
    U16LKNode *newNode;
    U16LKNode *nextNode;
    int i;
    
    if(index<0 || index>list->iLength)
    {
        return false;
    }
    if(IsLinkListFull_us(list))
    {
        return false;
    }

    newNode = (U16LKNode *)malloc(sizeof( U16LKNode));
    if( NULL == newNode )//malloc failed
    {
        return false;
    }
    
    for(i=0;i<index;i++)
    {
        preNode = preNode->stNext;
    }
    nextNode = preNode->stNext;
    preNode->stNext = newNode;
    newNode->iID = id;
    newNode->usData = elem;
    newNode->stNext = nextNode;

    list->iLength++;
    return true;
}

bool LinkListInsertToHead_us(  U16LinkList *list,int id,uint16_t elem)
{
    return LinkListInsertByIndex_us(list,0,id,elem);
}
bool LinkListInsertToTail_us(  U16LinkList *list,int id,uint16_t elem)
{
    return LinkListInsertByIndex_us(list,list->iLength,id,elem);
}
/****************************************************************************************/ 
//name:       bool LinkListRemoveByIndex_us( U16LinkList *list)
//describ:    Insert an new node(id,elem) to a link list.
//called:     
//input:      list :link list pointer,index:index of the link list, id: node id, elem :node dates
//return:     succeed of failed(true or false)
/****************************************************************************************/
bool LinkListRemoveByIndex_us(  U16LinkList *list,int index)
{
    U16LKNode *preNode = list->stHead;//target node pre node
    U16LKNode *nextNode;              //target node next node
    int i;
    if(index<0 || index >= list->iLength)
    {
        return false;
    }

    for(i=0;i<index;i++)
    {
        preNode = preNode->stNext;
    }
    nextNode = preNode->stNext->stNext;
    free(preNode->stNext);    //delete node of index
    preNode->stNext = nextNode;
    
    list->iLength--;
    return true;
}

bool LinkListRemoveByID_us( U16LinkList *list,int id)
{
    U16LKNode *preNode = list->stHead;
    U16LKNode *nextNode;
    while( NULL != preNode->stNext)
    {
        if(id == preNode->stNext->iID)
        {
            nextNode = preNode->stNext->stNext;
            free(preNode->stNext);
            preNode->stNext = nextNode;
            list->iLength--;
            return true;
        }
        else
            preNode = preNode->stNext;
    }
    return false;
}
/****************************************************************************************/ 
//name:       U16LKNode *LinkListGetNodeByIndex( U16LinkList *list,int index)
//describ:    Insert an new node(id,elem) to a link list.
//called:     
//input:      list :link list pointer,index:index of the link list, id: node id, elem :node dates
//return:     succeed of failed(true or false)
/****************************************************************************************/
U16LKNode *LinkListGetNodeByIndex( U16LinkList *list,int index)
{
    U16LKNode *tempNode = list->stHead->stNext;
    int i;
    if(index<0 || index >= list->iLength)
    {
        return NULL;
    }
    
    for(i=0;i<index;i++)
    {
        tempNode = tempNode->stNext;
    }
    return tempNode;
}
/****************************************************************************************/ 
//name:       U16LKNode *LinkListGetNodeByData( U16LinkList *list ,uint16_t data )
//describ:    Get node in linklist pointer by it data .
//called:     
//input:      list :link list pointer,data: link node data, id: node id, elem :node dates
//return:     succeed of failed(true or false)
/****************************************************************************************/
U16LKNode *LinkListGetNodeByData( U16LinkList *list ,uint16_t data )
{
    U16LKNode *tempNode = list->stHead;
    int i;
    
    for( i=0;i<list->iLength;i++ )
    {
		tempNode = tempNode->stNext;
		if( tempNode->usData == data )
		{
			return tempNode;
		}
    }

    return NULL;	
}
/****************************************************************************************/ 
//name:       bool LinkListGetIDByData( U16LinkList *list,uint16_t data,int *ID)
//describ:    Get node ID in linklist by it data .
//called:     
//input:      list :link list pointer,data: link node data, id: node id, elem :node dates
//return:     succeed of failed(true or false)
/****************************************************************************************/
bool LinkListGetIDByData( U16LinkList *list,uint16_t data,int *ID)
{
    U16LKNode *tempNode = list->stHead;
    int i;
    
    for( i=0;i<list->iLength;i++ )
    {
		tempNode = tempNode->stNext;
		if( tempNode->usData == data )
		{
			*ID = tempNode->iID;
			return true;
		}
    }

    return false;
}
/****************************************************************************************/ 
//name:       int LinkListGetIndexByData( U16LinkList *list,uint16_t data)
//describ:    Get node ID in linklist by it data .
//called:     
//input:      list :link list pointer,data: link node data, id: node id, elem :node dates
//return:     succeed of failed(true or false)
/****************************************************************************************/
int LinkListGetIndexByData( U16LinkList *list,uint16_t data)
{
    U16LKNode *tempNode = list->stHead;
    int i;
    
    for( i=0;i<list->iLength;i++ )
    {
		tempNode = tempNode->stNext;
		if( tempNode->usData == data )
		{
			return i;
		}
    }

    return -1;	
}