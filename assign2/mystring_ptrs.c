#include "mystring.h"

/*we use a for loop and until we find the end of the strign we just add 1*/
size_t ms_length(const char* str){
    size_t ui=0U;
    assert(str);
    while(*(str+ui)!='\0'){ 
        ui++;
    }
    return ui;
}

/*we check if we need memory allocation and than we have a while loop and we put 
source string index character to the destination one*/
char* ms_copy(char* st,const char* str){
    size_t ui=0U;
    if(st==NULL){
        st=malloc(sizeof(char)*(ms_length(str)+1));
        if(!st){
            printf("Error allocating memory\n");
            exit(1);
        }
    }
    assert(st && str);
    while(*(str+ui)){
       
        *(st+ui)=*(str+ui);
        ui++;
    }
    *(st+ui)='\0';
    return st;
}

/*same but for n characters*/
char* ms_ncopy(char* st,const char* str,size_t n){ 
    size_t  ui=0U;
    assert(st && str);
    while((*(str+ui)) && ui<n){
        *(st+ui)=*(str+ui);
        ui++;
    }
    *(st+ui)='\0';
    return st;
}

/*we use a for loop until we find the end of the string 
once we find we than put in it's place the first character 
of the source string.Than we use a for loop with 2 different indexes 1 for source 1 for dest
and we put the character from the source to the string dest*/
char * ms_concat(char *st,const char * str){
    size_t i,j,step=(ms_length(str)+ms_length(st));
    assert(st && str);
    for(i=0;i<=ms_length(st);i++){
        if(*(st+i)=='\0'){
            break;
        }
    }
    
    *(st+i)=*(str+0U);
    
    i=1;
    for(j=ms_length(st);j<step;j++){
        *(st+j)=*(str+i);
        i++;
    }
    *(st+j)='\0';
    return st;
    
}

/*same but now we do that for n characters for the source string*/
char * ms_nconcat(char *st,const char *str,size_t n){
    size_t i,j,step=(ms_length(str)+ms_length(st));
    assert(st && str);
    for(i=0;i<=ms_length(st);i++){
        if(*(st+i)=='\0'){
            break;
        }
    }
    
    *(st+i)=*(str+0U);
    
    i=1;
    j=ms_length(st);
    while(j<step && i<n){
        *(st+j)=*(str+i);
        i++;
        j++;
    }
    
    *(st+j)='\0';
    return st;
}

/*if the left is greater than the right string we return 1 because the st is the string we want to mainly check
else if it is less we return -1 
in other case we use a for loop to check each character in order to check if it is equal
if we find the given characters equal for the 2 string we add 1 to a counter 
if we find the main string's character has a great char we add 1 to St(main string) counter 
else we add to the Str_counter we than check if it is finally equal less or greater*/
int ms_compare(const char *st,const char *str){
    size_t St_counter=0U,Str_counter=0U;
    size_t st_len=ms_length(st),str_len=ms_length(str),i=0U,counter=0U;
    assert(st && str);
    
    if(ms_length(st)>ms_length(str)) return 1;
    else if(ms_length(st)<ms_length(str)) return -1;
    
    
    
    while(i<(str_len + st_len)){
        if(*(st+i) =='\0' || *(str+i) =='\0') break;
        if(*(st+i) == *(str+i))
            counter++;
        else if(*(st+i) > *(str+i)){
            St_counter++;
        }else Str_counter++;
        i++;
    }
    
    if(counter==i) 
        return 0;
    else if(St_counter>Str_counter)
        return 1;
    else 
        return -1;
}

/*same but for the first n characters*/
int ms_ncompare(const char *st,const char *str,size_t n){
    size_t st_len=ms_length(st),str_len=ms_length(str),i=0U,counter=0U; 
    size_t St_counter=0U,Str_counter=0U;
    assert(st && str);
   
    if(ms_length(st)>ms_length(str)) return 1;
    else if(ms_length(st)<ms_length(str)) return -1;
    
    
    while((i<(str_len + st_len)) && i<n){
        if(*(st+i) =='\0' || *(str+i) =='\0') break;
        if(*(st+i) == *(str+i))
            counter++;
        else if(*(st+i) > *(str+i)){
            St_counter++;
        }else Str_counter++;
        i++;
    }
    
    if(counter==i) 
        return 0;
    else if(St_counter>Str_counter)
        return 1;
    else 
        return -1;
}


/*we want to search a substring so we have a needle(str) and a hay(st) we put the first of the st to a char variable
and than we have a while loop until we find the FirstLetter than we have to have a "inside" for loop to check for every other character
that's why we have a variable named counter to check every char .When the main while ends we check if the counter is equal to the
length of the needle and if it is that means the substring exists else we return null*/
const char * ms_search(const char *str,const char *st){
    size_t counter=0U,i=0U,j=0U;
    size_t st_len=ms_length(st),str_len=ms_length(str);
    char FirstLetter=st[0];
    assert(str && st); 
       while(i < str_len){
        if(*(str+i)==FirstLetter){
            j=0U;
            while(j < st_len){
                if(*(st+j) == *(str+i)){
                    counter++;
                    i++;
                }
                j++;
            }
        }
        i++;
    }
    
    if(counter == st_len)
        return (char *)st;
    else
        return NULL;
    
}

    


