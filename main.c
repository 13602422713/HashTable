#include "U16HashTable.h"


int main()
{
	//construct
	U16HashTable hashTable = {0};
	//insert
	U16HashTableInit( &hashTable ,20 ,13);
	U16HashTableInsert( &hashTable , 14);
	U16HashTableInsert( &hashTable , 1);
	U16HashTableInsert( &hashTable , 24);
	U16HashTableInsert( &hashTable , 18);
	U16HashTableInsert( &hashTable , 13);
	U16HashTableInsert( &hashTable , 27);
	U16HashTableInsert( &hashTable , 28);
	U16HashTableInsert( &hashTable , 7);
	U16HashTableInsert( &hashTable , 21);
	U16HashTableInsert( &hashTable , 8);
	U16HashTableInsert( &hashTable , 10);

	//delete
	U16HashTableDelete( &hashTable , 27);
	U16HashTableDelete( &hashTable , 27);
	U16HashTableDelete( &hashTable , 10);

	U16HashTablePrintf( &hashTable );
	U16HashTableDesturct( &hashTable);
	system("pause");
	return 0;
}

