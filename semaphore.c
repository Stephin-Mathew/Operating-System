#include <stdio.h>
#include <stdlib.h>
int mutex=1,full=0,empty=3;
int wait(int s){
 s--;
 return s;
}
int signal(int s){
 s++;
 return s;
}
void producer(){
 mutex=wait(mutex);
 full=signal(full);
 empty=wait(empty);
 mutex=signal(mutex);
}
void consumer(){
 mutex=wait(mutex);
 full=wait(full);
 empty=signal(empty);
 mutex=signal(mutex);
 }
void main(){
 int ch,c=1;
while(c==1){
 printf("1)Producer 2)Consumer 3)Exit \n");
 scanf("%d",&ch);
 switch(ch){
  case 1:{
   if(mutex==1&&empty!=0){
     producer();
     printf("Produced Successfully \n");
     }
   else 
     printf("Buffer Full \n");
     break;
   }
   case 2:{
    if(mutex==1&&full!=0){
      consumer();
      printf("Consumed Successfully \n");
      }
    else
      printf("Buffer Empty \n");
    break;
   }
   case 3:{
    exit(0);
    break;
   }
   default :{
    printf("wrong choice\n");
   break;
   }
     
   
}
}
}

