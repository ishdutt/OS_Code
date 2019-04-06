#include<stdio.h>
int main()
{
int i,j,n,time,count,remain,flag=0,time_quant;
int w_time=0,tat=0,at[10],bt[10],rt[10];
float avTAT=0,avWT=0;
printf("Enter the numbre of processes ");
scanf("%d",&n);

remain=n;

for(i=0;i<n;i++)
{
printf("Arrival time of process[%d]  ",i+1);
scanf("%d",&at[i]);
printf("Burst time of process[%d] ",i+1);
scanf("%d",&bt[i]);               
rt[i]=bt[i];
printf("\n");
}

printf("Enter the time quantum ");
scanf("%d",&time_quant);

printf("\n\nProcess\t\tWT\t\tTAT\n");
for(time=0,count=0;remain!=0;)
{
if(rt[count]<=time_quant&&rt[count]>0)
{
time+=rt[count];
rt[count]=0;
flag=1;
}

else if(rt[count]>0)
{
rt[count]-=time_quant;
time+=time_quant;
}


if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("\nP[%d]\t|\t%d\t|\t%d",count+1,time-at[count]-bt[count],time-at[count]); 
      flag=0; 
	avTAT+=time-at[count];
	avWT+=time-at[count]-bt[count];
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 


} 

printf("\nThe average TAT is %f \n The Average WT is %f\n",avTAT/n,avWT/n);

return 0;
}
