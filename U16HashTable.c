#include "U16HashTable.h"

int U16HashFunction(U16HashTable *table,uint16_t data);
bool U16HashTableInit(U16HashTable *table,int ColumnSize,int RowSize);
bool U16HashTableDesturct( U16HashTable *table );
bool U16HashTableSearch(U16HashTable *table ,uint16_t data,U16LKNode *node);
bool U16HashTableSearchColumnsAndRows( U16HashTable *table ,uint16_t data ,int *column ,int *row );
bool U16HashTableInsert(U16HashTable *table , uint16_t data);
bool U16HashTableDelete(U16HashTable *table , uint16_t data);
void U16HashTablePrintf( U16HashTable *table );
/****************************************************************************************/ 
//name:       U16HashFunction(U16HashTable *table,uint16_t data)
//describ:    hash key funciton
//called:     
//input:      data
//return:     result:hash table column.
/****************************************************************************************/
int U16HashFunction(U16HashTable *table,uint16_t data)
{
	int result;
	int i;
	//取余法
	//result = data%(table ->iRowSize);
	//JDK1.8方法
	for()
	return result;
}
/****************************************************************************************/ 
//name:       bool U16HashTableInit(U16HashTable *table ,int ColumnSize ,int RowSize)
//describ:    redistribute memory for hash table.
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool U16ReHash( U16HashTable *table )
{
	int rowSizeNew = table->iRowSize<<1;

	//malloc

	//寻找翻倍后的第一个素数
	while( !isPrimeNumber( ++rowSizeNew ) )
	{
		
	}

	//table->iRowSize = rowSizeNew;
	//table->iHashSize = 0;

	//Get all datas in hash table and rebuild it.
	return false;

}

/****************************************************************************************/ 
//name:       bool U16HashEquals(U16HashTable *table,uint16_t data)
//describ:    To fine there is a same data in table or not. 
//called:     
//input:      data
//return:     succeed/failed.
/****************************************************************************************/
bool U16HashEquals(U16HashTable *table,uint16_t data)
{
	//do not use this function
	return false;
}

/****************************************************************************************/ 
//name:       bool U16HashEquals(U16HashTable *table,uint16_t data)
//describ:    To fine there is a same data in table or not. 
//called:     
//input:      data
//return:     succeed/failed.
/****************************************************************************************/
bool U16HashTableExpansionModeInit( U16HashTable *table )
{
	int RowSize = 13;	
	int ColumnSize = 10;
	int i;
	//construct ,malloc for pList,and init each row. 
	table->pList = (U16LinkList**)malloc(sizeof(U16LinkList*));
	if( NULL == table->pList )
		return false;

	*(table->pList) = (U16LinkList*)malloc(RowSize*sizeof(U16LinkList));
	if( NULL == table->pList )
		return false;

	for(i=0;i<RowSize;i++)
	{
		LinkListCreate_us( *(table->pList)+i,ColumnSize );
	}

	table->iColumnSize = ColumnSize;
	table->iRowSize = RowSize;
	table->eExpansionType = HASHTYPE_AUTOEXPANSION;
	table->iHashSize = 0; 

	return true;	
}

/****************************************************************************************/ 
//name:       bool U16HashTableInit(U16HashTable *table ,int ColumnSize ,int RowSize)
//describ:    construct
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool U16HashTableInit(U16HashTable *table ,int ColumnSize ,int RowSize)
{
	int i;
	//construct ,malloc for pList,and init each row. 
	table->pList = (U16LinkList**)malloc(sizeof(U16LinkList*));
	//printf("pList=%d\r\n",table->pList);
	//printf("sizeof(U16LinkList*)=%d\r\n",sizeof(U16LinkList*));
	//printf("sizeof(U16LinkList)=%d\r\n",sizeof(U16LinkList));
	*(table->pList) = (U16LinkList*)malloc(RowSize*sizeof(U16LinkList));
	for(i=0;i<RowSize;i++)
	{
		LinkListCreate_us( *(table->pList)+i,ColumnSize);
		//printf("*(table->pList)+%d=%d\r\n",i,*(table->pList)+i);
		//printf("*(table->pList+%d)=%d\r\n",i,*(table->pList+i));
		//printf("pList[%d]=%d\r\n",i,table->pList[i]);
	}

	table->iColumnSize = ColumnSize;
	table->iRowSize = RowSize;
	table->bAutoRehash = HASHTYPE_NORMAL;
	table->iHashSize = 0;

	return true;
}

/****************************************************************************************/ 
//name:       bool U16HashTalbeSpaceOut(U16HashTable *table ,int ColumnSize ,int RowSize)
//describ:    hash table space is enough or not.
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool isU16HashTalbeSpaceEnough( U16HashTable *table )
{
	if( table->iHashSize < HASHTABLE_LOADINGFACTOR*table->iRowSize )
	{
		return true;
	}

	return false;
}

/****************************************************************************************/ 
//name:       bool isU16HashTableModeExpansion( U16HashTable *table )
//describ:    is hash table need to expansion or not
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool isU16HashTableModeExpansion( U16HashTable *table )
{
	//扩展模式和树化模式都需要自动扩展
	if( HASHTYPE_AUTOEXPANSION == table->eExpansionType || HASHTYPE_AUTOTREEIFY == table->eExpansionType )
	{
		return true;
	}
	return false;
}

/****************************************************************************************/ 
//name:       bool isPrimeNumber( int data )
//describ:    redistribute memory for hash table.
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool isPrimeNumber( int data )
{

	return false;
}


/****************************************************************************************/ 
//name:       bool U16HashTableDesturct( U16HashTable *table )
//describ:    destruct
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool U16HashTableDesturct( U16HashTable *table )
{
	int i;

	//delete each rows linklist
	for(i=0;i<table->iRowSize;i++)
	{
		LinkListDestruct_us( *(table->pList)+i );
	}
	free( *(table->pList) );

	//delete table pointer
	free(table->pList);

	return true;
}
/****************************************************************************************/ 
//name:       bool U16HashTableSearch( U16HashTable *table )
//describ:    destruct
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool U16HashTableSearch(U16HashTable *table ,uint16_t data,U16LKNode *node)
{
	int row = U16HashFunction(table,data);
	if(row > table->iRowSize)
	{
		return false;
	}
	
	node = LinkListGetNodeByData( *(table->pList) + row ,data );

	return true;
}

/****************************************************************************************/ 
//name:       bool U16HashTableSearch( U16HashTable *table )
//describ:    destruct
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool U16HashTableSearchColumnsAndRows( U16HashTable *table ,uint16_t data ,int *column ,int *row )
{
	int tempRow = U16HashFunction(table,data);
	int tempColumn = 0;

	//get row
	if( tempRow > table->iRowSize )
	{
		return false;
	}
	
	//get column
	tempColumn = LinkListGetIndexByData( *(table->pList) + tempRow ,data );
	if( -1 == tempColumn )
	{
		return false;
	}

	*column = tempColumn;
	*row = tempRow;
	return true;
}


/****************************************************************************************/ 
//name:       bool U16HashTableInsert(U16HashTable *table , uint16_t data)
//describ:    insert
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool U16HashTableInsert(U16HashTable *table , uint16_t data)
{
	int row = U16HashFunction(table,data);
	int column = getListLength( *(table->pList) + row )+1;


	//A same data have been inserted in this table.
	if( U16HashEquals(table,data) )
	{
		return false;
	}

	if( column > table->iColumnSize )
	{
		return false;
	}

	if( LinkListInsertToTail_us(  *(table->pList) + row,column ,data) )
	{
		table->iHashSize++;
		return true;
	}

	
	//自动扩展模式 && 空间快用完
	if( isU16HashTableModeExpansion()  && !isU16HashTalbeSpaceEnough( table ) )
	{
		U16ReHash( table );
	}

	return false;
}
/****************************************************************************************/ 
//name:       bool U16HashTableDelete(U16HashTable *table , uint16_t data)
//describ:    delete
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
bool U16HashTableDelete(U16HashTable *table , uint16_t data)
{
	int row=0;
	int column=0;
	if( U16HashTableSearchColumnsAndRows( table ,data ,&column ,&row) )
	{
		if( LinkListRemoveByIndex_us( *(table->pList) + row ,column) )
		{
			table->iHashSize--;
			return true;
		}
	}
	return false;
}


/****************************************************************************************/ 
//name:       void U16HashTablePrintf( U16HashTable *table )
//describ:    delete
//called:     
//input:      data
//return:     succeed/fail
/****************************************************************************************/
void U16HashTablePrintf( U16HashTable *table )
{
	U16LKNode *node;
	int i,j;
	printf("\r\nHashTable:\r\n");
	for( i=0;i<table->iRowSize;i++ )
	{
		printf("i%d:" ,i);
		for( j=0;j<table->iColumnSize;j++)
		{
			node = LinkListGetNodeByIndex( *(table->pList)+i,j);
			if(NULL != node)
				printf("%d,",node->usData);
		}
		printf("\r\n");
	} 
}
