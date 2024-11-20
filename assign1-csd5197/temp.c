#include <stdio.h> 

/*for normal states take the "normal" state letter find where it belongs to the greek letter array and return it's index*/
int search(int x,int array[]){
    int found=0,i=0;
        for(i=0;i<27;i++){
            if(array[i]==x){
                found=i;
                break;
            }
        }
    return found;
}

/*the states according to the letters upper-lower or the normal one(=1)*/
enum States{
    ONE,
    M,
    m,
    N,
    n
};

/*we use this getter in order to "locate" in which state we are at the current time based on the integer of the char we got*/
enum States get_State(int c){
    if(c==204){
        return M;
    }else if(c==236){
        return m;
    }else if(c==205){
        return N;
    }else if(c==237){
        return n;
    }else return ONE;
}

/*prototypes of the state functions*/
void state_ONE(int x,int array1[],int array2[],int array3[],int array4[]);
void state_M(int x,int array1[],int array2[],int array3[],int array4[]);
void state_m(int x,int array1[],int array2[],int array3[],int array4[]);
void state_N(int x,int array1[],int array2[],int array3[],int array4[]);
void state_n(int x,int array1[],int array2[],int array3[],int array4[]);

int main(){ 
    int x;
    enum States state;
    /*ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ*/
   int GreekAlphabet[26]={193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217};

    /*αβγδεζηθικλμνξοπρστυφχψω*/
    int GA[26]={225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249};

    /*AVGDEZH8IKLMNKSOPRSTYFXPSW*/
    int EnglishAlphabet[26]={65,86,71,68,69,90,72,0,73,75,76,77,78,0,79,80,82,83,83,84,89,70,88,0,87};

    /*avgdezh8iklmnksoprstyfxpsw*/
    int EA[26]={97,118,103,100,101,122,104,8,105,107,108,109,110,0,111,112,114,0,115,116,121,102,120,119};


   

    /*we start the first time by getting a char and we assign to it the state and then we read from any file till it's empty*/
   char c;
   c=getchar();
   x=256+c;
   state=get_State(x);
   
   while(c!=EOF){
    /*according to the states we call the proper function*/
        switch(state){
            case ONE:
               
                if(x==204){
                    state=M;
                }else if(x==236){
                    state=m;  
                }else if(x==205){
                    state=N;
                }else if(x==237){
                    state=n;  
                }else{
                    state_ONE(x,GreekAlphabet,GA,EnglishAlphabet,EA);
                    break;
                }
            case M:
                state_M(x,GreekAlphabet,GA,EnglishAlphabet,EA);
                break;
            case m:
                state_m(x,GreekAlphabet,GA,EnglishAlphabet,EA);
                break;
            case N:
                state_N(x,GreekAlphabet,GA,EnglishAlphabet,EA);
                break;
            case n:
                state_n(x,GreekAlphabet,GA,EnglishAlphabet,EA);
                break;
        }
    /*after the states we call again to get a char and get the state accordingly*/
    c=getchar();
    if(c<0){
        x=256+c;
        state=get_State(x);
    }else{
        x=c;
        printf("%c",c);
        state=get_State(c);
    }
    
  }

   return 0;
}

/*this state checks first for the space and the ENTER and then according to the range it checks for the upper or the lower case
or the special characters such as 8,ks,ps */
void state_ONE(int x,int array1[],int array2[],int array3[],int array4[]){
    int y;
    if(x>=193 && x<=217){
        if(x==206){
            putchar(75);
            putchar(83);
        }else if(x==216){
            putchar(80);
            putchar(83);
        }else if(x==200){
            printf("8");
        }else if(x==217){
            putchar(87);
        }else{
            y=search(x,array1);
            printf("%c",array3[y]);                 
        }
    }else if(x>=225 && x<=249){
        if(x==238){
            putchar(107);
            putchar(115);
        }else if(x==248){
            putchar(112);
            putchar(115);
        }else if(x==232){
            printf("8");
        }else if(x==242){
            putchar(115);
        }else if(x==249){
                putchar(119);
        }else{
            y=search(x,array2);
            printf("%c",array4[y]);        
        }
    }else if(x>=182 && x<=192){
               
        if(x==182){
            putchar(39);
            putchar(65);
        }else if(x==184){
            putchar(39);
            putchar(69);
        }else if(x==185){
            putchar(39);
            putchar(72);
        }else if(x==186){
            putchar(39);
            putchar(73);
        }else if(x==188){
            putchar(39);
            putchar(79);
        }else if(x==191){
            putchar(39);
            putchar(87);
        }else if(x==190){
            putchar(39);
            putchar(89);
        }else if(x==192){
            putchar(105);
            putchar(34);
            putchar(39);
        }
    }else if(x>=220){            
        if(x==220){
            putchar(97);
            putchar(39);
        }else if(x==221){
            putchar(101);
            putchar(39);
        }else if(x==222){
            putchar(104);
            putchar(39);
        }else if(x==223){;
            putchar(105);
            putchar(39);
        }else if(x==224){
            putchar(121);
            putchar(34);
            putchar(39);
        }else if(x==252){
            putchar(111);
            putchar(39);
        }else if(x==254){
            putchar(119);
            putchar(39);
        }else if(x==253){
            putchar(121);
            putchar(39);
        }else if(x==250){
            putchar(105);
            putchar(34);
        }else if(x==251){
            putchar(121);
            putchar(34);
        }
    }       
}

/*this state is for the M if the next letter is a p,P we print B else we print the M and we have to check again if the next letter is M 
we do this to all this state-functions*/
void state_M(int  x,int array1[],int array2[],int array3[],int array4[]){
    int z=0;
    char next;
    enum States next_state;
    next=getchar();
    if(next<0)
        z=256+next;
    else z=next;

    if(z==208 || z==240){
        putchar(66); 
    }else{
        putchar(77);
        next_state=get_State(z);
        switch(next_state){
            case ONE:
                state_ONE(z,array1,array2,array3,array4);
                break;
            case M:
                state_M(z,array1,array2,array3,array4);
                break;
            case m:
                state_m(z,array1,array2,array3,array4);
                break;
            case N:
                state_N(z,array1,array2,array3,array4);
                break;
            case n:
                state_n(z,array1,array2,array3,array4);
                break;
        }
    }
}

/*same for this but this time the first letter is m so it will print b or m */
void state_m(int  x,int array1[],int array2[],int array3[],int array4[]){
    int z=0;
    char next;
    enum States next_state;
    next=getchar();;
    if(next<0)
        z=256+next;
    else z=next;

    if(z==208 || z==240){
        putchar(98);       
    }else{
        putchar(109);
        next_state=get_State(z);
        switch(next_state){
            case ONE:
                state_ONE(z,array1,array2,array3,array4);
                break;
            case M:
                state_M(z,array1,array2,array3,array4);
                break;
            case m:
                state_m(z,array1,array2,array3,array4);
                break;
            case N:
                state_N(z,array1,array2,array3,array4);
                break;
            case n:
                state_n(z,array1,array2,array3,array4);
                break;
        }
    }
}

/*same thinking,different result:the letter is N so if it has T,t it will print D else it will print N and check again for the next letter etc*/
void state_N(int x,int array1[],int array2[],int array3[],int array4[]){
    int z=0;
    char next;
    enum States next_state;
    next=getchar();
    if(next<0)
        z=256+next;
    else z=next;

    if(z==212 || z==244){
        putchar(68);
    }else{
        putchar(78);
        next_state=get_State(z);
        switch(next_state){
            case ONE:
                state_ONE(z,array1,array2,array3,array4);
                break;
            case M:
                state_M(z,array1,array2,array3,array4);
                break;
            case m:
                state_m(z,array1,array2,array3,array4);
                break;
            case N:
                state_N(z,array1,array2,array3,array4);
                break;
            case n:
                state_n(z,array1,array2,array3,array4);
                break;
        }
    }
}

/*same as before but now the letter is n and it will print d or else n*/
void state_n(int x,int array1[],int array2[],int array3[],int array4[]){
    int z=0;
    char next;
    enum States next_state;
    next=getchar();
    if(next<0)
        z=256+next;
    else z=next;

    if(z==212 || z==244){
        putchar(100);
    }else{
        putchar(110);  
        next_state=get_State(z);
        switch(next_state){
            case ONE:
                state_ONE(z,array1,array2,array3,array4);
                break;
            case M:
                state_M(z,array1,array2,array3,array4);
                break;
            case m:
                state_m(z,array1,array2,array3,array4);
                break;
            case N:
                state_N(z,array1,array2,array3,array4);
                break;
            case n:
                state_n(z,array1,array2,array3,array4);
                break;
        }
    }
}