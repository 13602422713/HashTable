#ifndef _U16HASHTABLE_H
#include "MyTypeTool.h"
#include "U16LinkList.h"

#define HASHTABLE_LOADINGFACTOR 0.75

typedef enum hashtabletype
{
	HASHTYPE_NORMAL=0,				//����ģʽ
	HASHTYPE_AUTOEXPANSION=1,		//�Զ�����ģʽ
	HASHTYPE_AUTOTREEIFY=2,			//�Զ�����ģʽ
}HASHTABLETYPE;

typedef struct
{
	//������ϣ��ṹ
	U16LinkList **pList;
	int iRowSize;
	int iColumnSize;
	int iHashSize;
	//�������
	HASHTABLETYPE eExpansionType;	//ָʾ����ģʽ
	float fLoadingFactior;			//��������
	int iLoadingThreshold;			//������ֵ

}U16HashTable;

int U16HashFunction(U16HashTable *table,uint16_t data);
bool U16HashTableInit(U16HashTable *table,int ColumnSize,int RowSize);
bool U16HashTableDesturct( U16HashTable *table );
bool U16HashTableSearch(U16HashTable *table ,uint16_t data,U16LKNode *node);
bool U16HashTableSearchColumnsAndRows( U16HashTable *table ,uint16_t data ,int *column ,int *row );
bool U16HashTableInsert(U16HashTable *table , uint16_t data);
bool U16HashTableDelete(U16HashTable *table , uint16_t data);
void U16HashTablePrintf( U16HashTable *table );

#endif

