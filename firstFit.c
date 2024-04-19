#include <stdio.h>

void main(){
int lim,mem;
 struct mems{
  int size,alloc;
  }M[10];
  
 struct Proc{
  int size,flag;
  }P[10];


printf("Number of Processes : \n");
scanf("%d",&lim);
printf("Number of Memory Blocks : \n");
scanf("%d",&mem);
for(int i=0;i<mem;i++){
 printf("Enter Memory Size :\n");
 scanf("%d",&M[i].size);
 M[i].alloc=0;
}

for(int i=0;i<lim;i++){
 printf("Enter Process Size :\n");
 scanf("%d",&P[i].size);
 P[i].flag=0;
}

for(int i=0;i<lim;i++){
 for(int j=0;j<mem;j++){
  if(P[i].size<=M[j].size){
   if(M[j].alloc==1)
     continue;
   else{
    M[j].alloc=1;
    P[i].flag=1;
     printf("%d Memory is allocated for %d Process \n",M[j].size,P[i].size);
     break;
    }
   }
  }
 }

for(int i=0;i<lim;i++){
  if(P[i].flag==0){
   printf("No Space for %d process \n",P[i].size);
  }
 } 

}
