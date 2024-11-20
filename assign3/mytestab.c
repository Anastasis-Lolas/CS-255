#include "symtable.h"

void pfApply(const char *pcKey, void *pvValue, void *pvExtra)
{
	    printf("key = %s extra = %d \n",pcKey,(int)pvExtra);
}


int main(){
    SymTable_T symtab;
	  const char keys[] = "abcdefghijklmnopqrstvwxyz";
        char key[2];

	int x[]  = {1,2,3,4,5,6,7,8,9,106,8,9,9,7,5,4,345,3,2,4,56,7,98,98,65,43,21};
	void (*pointer)(const char*,void *,void*);
	int i,nvalue;

	pointer = &pfApply;
	symtab = SymTable_new();
	key[1] = '\0';
	for(i = 0; i < sizeof(keys)/sizeof(keys[0])-1; i++)
	{
		    key[0] = keys[i];
		    printf("(put) = %d - (%s , %d)\n" ,SymTable_put(symtab, key, (int*)x[i]),key,x[i]);
	}
	
	
	printf("(remove) = %d\n ",SymTable_remove(symtab, "a"));
	printf("(remove) = %d\n ",SymTable_remove(symtab, "h"));
	printf("(remove) = %d\n ",SymTable_remove(symtab, "d"));
	
	
	for(i = 0; i < 10; i++)
	{
		key[0] = keys[i];
		printf("(contains) = %d key -> %s\n",(int)SymTable_contains(symtab,key),key);
	}
	
	
	for(i = 0; i < 10; i++)
	{
		key[0] = keys[i];
		    if(SymTable_get(symtab,key) != NULL){
			printf("(get) = %d\n",(int)SymTable_get(symtab,key));
		    }
	}
	
	nvalue = 1;
	printf("length = %d \n" , SymTable_getLength(symtab));
	
	Print(symtab);
	SymTable_map(symtab, pointer, (int*)nvalue);
	
	SymTable_free(symtab);

    return 0;
}