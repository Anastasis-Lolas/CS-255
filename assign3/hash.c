#include "symtable.h"
#define SIZE 509
#define HASH_MULTIPLIER 65599

struct SymTable {
    unsigned int length;
    Node table[SIZE];
};

struct Table{
    void * value;
    const char * keyValue;
    struct List *  next;
};


static unsigned int symtable_hash(const char * pcKey){
    size_t ui=0U;
    unsigned int uiHash = 0U;

	for (ui = 0U; pcKey[ui] != '\0'; ui++)
        uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];

	return uiHash % SIZE;
}

SymTable_T  SymTable_new(){
    SymTable_T oSymTable=(SymTable_T *)malloc(sizeof(SymTable_T));
    if(oSymTable==NULL) assert(0);
    
    oSymTable->length=0U;
    oSymTable->table=(SymTable_T *)malloc(sizeof(SymTable_T)*SIZE);
    if(oSymTable->table==NULL) assert(0);
    
    size_t i;
    
    for(i=0;i<SIZE;i++){
        oSymTable->head[i]=NULL;
    }
    
    return oSymTable;
}


void SymTable_free(SymTable_T oSymTable){
    size_t i=0U;
    SymTable_T current=oSymTable,next;
    if(oSymTable==NULL) assert(0);
    
    for(i=0U;i<SIZE;i++){
        if(current->table[i]!=NULL){
            free(current->table[i]->key);
            free(current->table[i]);
        }
    }
    free(current);
}

unsigned int SymTable_getLength(SymTable_T oSymTable){
    assert(oSymTable);
    return oSymTable->length;
    
}

int SymTable_contains(SymTable_T oSymTable, const char *pcKey){
    unsigned int index=0U;
    Node find_node;

    index=symtable_hash(pcKey);
    find_node=oSymTable->table[index];

    while(current!=NULL){
        if(strcmp(current->keyValue,pcKey)==0){
            return 1;
        }
        current=current->next;
    }

    return 0;
}

int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue){
    size_t index=0U;
    assert(oSymTable && pcKey);

    if(SymTable_contains(oSymTable,pcKey)==1) return 0;

    oSymTable->length++;

    Node newNode=(Node)malloc(sizeof(Node));
    assert(newNode);
    newNode->keyValue = malloc((strlen(pcKey)+1)*sizeof(char));
    assert(newNode->keyValue);
    strcpy(newNode->key, pcKey);
    newNode->value=(void *)pvValue;

    index=symtable_hash(pcKey);
    if(oSymTable->table[index]==NULL){
        oSymTable->table[index]=newNode;
        return 1;
    }

    return 0;

}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey){
    size_t ui=0U;
    Node current,prev;
    assert(oSymTable && pcKey);

    if(SymTable_contains(oSymTable,pcKey)==0) return 0;

    index=symtable_hash(pcKey);
    current=oSymTable->table[index];

    while(current!=NULL){
        if(strcmp(current->keyValue, pcKey)==0) break;
        prev=current;
        current=current->next;
    }

    if(prev==current){
        current=prev->next;
        free(current->keyValue);
        free(current);
        oSymTable->length--;
        return 1;
    }else{
        prev->next=current->next;
        free(current->keyValue);
        free(current);
        oSymTable->length--;
        return 1;
    }

    return 0;
}

void *SymTable_get(SymTable_T oSymTable, const char *pcKey){
    size_t index=symtable_hash(oSymTable,pcKey);
    Node current=SymTable->table[index];
    assert(oSymTable && pcKey);
    assert(current);

    while(current !=NULL){
        if(strcmp(current->keyValue,pcKey)==0)
            return (void *) current->value;
        current=current->next;
    }

    return NULL;
}


void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),const void *pvExtra){
    size_t index=symtable_hash(oSymTable,pcKey);
    Node current=SymTable->table[index];
    assert(oSymTable && pcKey);
    assert(current);

    while(current!=NULL){
        pfApply(current->keyValue,(void *)current->value,(void *)pvExtra);
        current=current->next;
    }

    return ;
}

void Print(SymTable_T oSymTable){
	Node * current;
	current = oSymTable->head;
	while(current){
	  printf("(%s , %d)\n",current->key,(int *)current->value);
	  current= current->next;
	}
}