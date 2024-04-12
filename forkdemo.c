#include <stdio.h>
#include <unistd.h>
void main(){
  int pd;
  pd=fork();
  if(pd==0){
   int lim;
   printf("This is Child Process and process id is %d \n",getpid());
   printf("Parents id is %d \n", getppid());
   
   printf("Enter Limit : \n");
   scanf("%d",&lim);
   for(int i=1;i<=lim;i++){
   printf("%d \n",i);
   }
  }
  else if(pd>0){
  wait();
  int num;
  printf("This is a Parent Process and process id is %d \n",getpid());
  printf("Enter Number : \n");
  scanf("%d",&num);
  
  if(num%2==0){
    printf("%d is an even number \n ",num);
  }else{
    printf("%d is an odd number \n ",num);
    }
    
    }
  else{
   printf("Fork Failed ");
  }
  
 }
  
