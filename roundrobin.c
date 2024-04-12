#include <stdio.h>
void main(){
int lim,tq;
printf("Enter Number of Proccess : \n");
scanf("%d",&lim);
printf("Enter Time Quantum :\n");
scanf("%d",&tq);

int total=0,rt[lim],flag=0,prid[lim],wt[lim],tat[lim],bt[lim],tot_wt=0,tot_tat=0;

for(int i=0;i<lim;i++){
 printf("Enter Process id : \n");
 scanf("%d",&prid[i]);
 printf("Enter Burst Time : \n");
 scanf("%d",&bt[i]);
 rt[i]=bt[i];
}

while(flag!=lim){
for(int i=0;i<lim;i++){
if(rt[i]>tq){
 total=total+tq;
 rt[i]=rt[i]-tq;
}
else if(rt[i]==0){
 continue;
}
else{
 total=total+rt[i];
 rt[i]=0;
 tat[i]=total;
 wt[i]=total-bt[i];
 flag++; 
}
}
}
printf("Pid \t BT \t WT \t TAT \t \n");
for(int i=0;i<lim;i++){
 printf("%d \t %d \t %d \t %d \t \n",prid[i],bt[i],wt[i],tat[i]);
 tot_wt=tot_wt+wt[i]; 
 tot_tat=tot_tat+tat[i]; 
 }
 
 printf("Total Waiting Time : %d \n",tot_wt);
 printf("Average Waiting Time : %f \n",(float)tot_wt/lim);
 printf("Total TurnAround Time : %d \n",tot_tat);
 printf("Average TurnAround Time : %f \n",(float)tot_tat/lim);
 
}

