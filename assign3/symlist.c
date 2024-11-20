#include "symtable.h"

struct Table {
    void * value;
    const char * keyValue;
    struct Table *next;
};

struct SymTable{
    unsigned int length;
    Node head;
}



SymTable_T SymTable_new(void){
    SymTable_T table=(SymTable_T)malloc(sizeof(SymTable_T));
    assert(node);

    table->length=0U; 
    table->head=NULL;

    return node;
}

void SymTable_free(SymTable_T oSymTable){
    Node current=oSymTable->head;
    Node next;

    assert(oSymTable);

    while(current!= NULL){
        next=current->next;
        free(current->keyValue);
        free(current);
        current=next;
    }
    
    free(oSymTable);
}


unsigned int SymTable_getLength(SymTable_T oSymTable){
    assert(oSymTable);

    return oSymTable->length;
}


int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue){
    assert(oSymTable && pcKey);

   if(SymTable_contains(oSymTable, pcKey)==1) return 0;

    Node newNode =(Node)malloc(sizeof(Node));


    assert(newNode);
    newNode->keyValue = malloc((strlen(pcKey)+1)*sizeof(char));
    assert(newNode->keyValue);
    strcpy(newNode->key, pcKey);
    newNode->value=(void *)pvValue;

    while(oSymTable->head->next!=NULL){
        oSymTable->head=oSymTable->head->next;
    }

    oSymTable->head->next=newNode;
    newNode->next=NULL;
    oSymTable->length++;

    return 1;
}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey){
    Node current=oSymTable->head,prev;
    assert(oSymTable && pcKey);
    assert(current);

    if(SymTable_contains(oSymTable,pcKey)==0) return 0;
    
    while(current!=NULL ){
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

int SymTable_contains(SymTable_T oSymTable, const char *pcKey){
    Node current=SymTable->head;
    assert(oSymTable && pcKey);

    while(current !=NULL ){
        if(strcmp(current->keyValue,pcKey)==0){
            return 1;
        }
        current=current->next;
    }

    return 0;
}

void *SymTable_get(SymTable_T oSymTable, const char *pcKey){
    Node current=SymTable->head;
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
    Node current=SymTable->head;
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