#include <stdio.h> 
#include <assert.h>
#include <stdlib.h>

/*Calcuates the length of the string or else the sum of the characters that it includes without the \0*/
size_t ms_length(const char* str); 

/*we have a source and a destination string,it copys the source string to the destination string withouth changing the destination's 
already included string*/
char * ms_copy(char *st,const char * str); 

/*same as before but now there is a n which represents the number of the characters that will be copied*/
char * ms_ncopy(char *st,const char * str ,size_t n); 

/*takes the source string and puts it to the destination string*/
char * ms_concat(char *st,const char * str); 

/*same as before but the n again represents the number of characters to be put to the string*/
char * ms_nconcat(char *st,const char * str,size_t n);

/*takes the 2 string and compares them and return an integer according to the situation*/
int ms_compare(const char* st,const char* str);

/*compares 2 string for the first n characters*/
int ms_ncompare(const char* st,const char* str,size_t n);

/*takes a string and search if it exists as a substring to another string*/
const char * ms_search(const char* str,const char* st);
    
