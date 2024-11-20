#include "mystring.h"

int main()
{
    /*for Arrays*/
    char st[]="Hi dude";
    char st1[20]="lolas agapa tzetza";
    char st2[7];
    char st3[100]="baby se 8elw";
    char st4[50]="wassup bro ";
    char st5[20]="abcde";
    char st6[20]="abcde";
    char st7[20]="abd";
    char st8[20]="abcdE";
    char st9[40]="onPoint";
    char st10[40]="Point";
    size_t res;
    int result=0;
    
    res=ms_length(st);
    printf("size of st= %lu\n",res);
    res=ms_length(st1);
    printf("Size of st1= %lu\n",res);
    
    ms_copy(st1,st);
    printf("st1=%s\n",st1);
    ms_ncopy(st2,st,4);
    printf("st2=%s \n",st2);
    
    ms_concat(st3,st);
    printf("st3=%s\n",st3);
    
    ms_nconcat(st4,st1,2);
    printf("st4=%s\n",st4);
    
   
    result = ms_compare(st5,st6);
    printf("%d\n",result);
    
    result = ms_compare(st5,st7);
    printf("%d\n",result);
    
    result = ms_compare(st7,st5);
    printf("%d\n",result);
     
    result = ms_compare(st8,st5);
    printf("%d\n",result);
    
    result = ms_ncompare(st8,st5,2);
    printf("result is=%d\n",result);
    
    ms_search(st9,st10);
    printf("st10=%s\n",ms_search(st9,st10));
    
    
    return 0;
}
