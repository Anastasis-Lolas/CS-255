#include <stdio.h> 

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

enum States{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE
};

/*vale to teliko ellhniko sigma*/

int main(){
    /*ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ*/
   int GreekAlphabet[26]={193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217};

    /*αβγδεζηθικλμνξοπρστυφχψω*/
    int GA[26]={225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249};

    /*int TGA[7]={182,184,185,186,188,191,190};
    int tGA[7]={220,221,222,223,252,254,253};*/

    /*AVGDEZH8IKLMNKSOPRSTYFXPSW*/
    int EnglishAlphabet[26]={65,86,71,68,69,90,72,0,73,75,76,77,78,0,79,80,82,83,83,84,89,70,88,0,87};

    /*avgdezh8iklmnksoprstyfxpsw*/
    int EA[26]={97,118,103,100,101,122,104,8,105,107,108,109,110,0,111,112,114,0,115,116,121,102,120,119};


   
   /*balta ola se synarthsh,me bash enumerator*/
   /*kai meta checkare px gia to M an einai o epomenos p,P->B h alliws pare ton kainourio xarakthra me get state kai checkare an einai jana M*/
  /*kane mia search pou 8a epistrefei to index bash to x pou 8a dwseis poy einai to 256-c gia ellhnika logo overflow*/
  /*epeita apla printare to grama me  printf("%c",EnglishAlphabet[0])*/
   char c;
   int x=0,y=0;
   while(c!=EOF ){
	    x=0;
        c=getchar();
            x=256+c;

            if(c<182){
                if(c==32){
                    printf(" ");
                }else if(c==10){
                    printf("\n");
                }

            }

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
                    y=search(x,GreekAlphabet);
                    printf("%c",EnglishAlphabet[y]);                 
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
                }else if(x==249){
                        putchar(119);
                }else{
                    y=search(x,GA);
                    printf("%c",EA[y]);        
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
    
    return 0;
}

