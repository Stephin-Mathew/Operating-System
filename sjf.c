#include <stdio.h>
void main(){
int lim;
printf("Enter Number of Proccess : \n");
scanf("%d",&lim);
int prid[lim],wt[lim],tat[lim],bt[lim],tot_wt=0,tot_tat=0,temp;

for(int i=0;i<lim;i++){
 printf("Enter Process id : \n");
 scanf("%d",&prid[i]);
 printf("Enter Burst Time : \n");
 scanf("%d",&bt[i]);
}

for(int a=0;a<lim;a++){
for(int b=a;b<lim;b++){
 if(bt[b]<bt[a]){
  temp=bt[a];
  bt[a]=bt[b];
  bt[b]=temp;
  
  temp=prid[a];
  prid[a]=prid[b];
  prid[b]=temp;

}
}
}


 wt[0]=0;
 tat[0]=bt[0];
 tot_tat=bt[0];
 
 
for(int i=1;i<lim;i++){
 wt[i]=wt[i-1]+bt[i-1];
 tot_wt=tot_wt+wt[i]; 
 tat[i]=tat[i-1]+bt[i];
 tot_tat=tot_tat+tat[i]; 
 }
 
 printf("Total Waiting Time : %d \n",tot_wt);
 printf("Average Waiting Time : %f \n",(float)tot_wt/lim);
 printf("Total TurnAround Time : %d \n",tot_tat);
 printf("Average TurnAround Time : %f \n",(float)tot_tat/lim);
 
}
