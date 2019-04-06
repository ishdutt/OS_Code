#include <stdio.h>

int main() 
{
      int at[10], bt[10], temp[10];
      int i, smallest, count = 0, time, n;
      double wt = 0, tat = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &n); 
      printf("\nEnter Details of %d Processes\n", n);
      for(i = 0; i < n; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &at[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &bt[i]); 
            temp[i] = bt[i];
      }
  	printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
      for(time = 0; count != n; time++)
      {
            for(i = 0; i < n; i++)
            {
                  if(at[i] <= time && bt[i] > 0)
                  {
                        smallest = i;
                  }
            }
            bt[smallest]--;
            if(bt[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wt = wt + end - at[smallest] - temp[smallest];
                  tat = tat + end - at[smallest];
		  printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",i,bt[i],wt,tat);
            }
      }
      average_waiting_time = wt /n; 
      average_turnaround_time = tat / n;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
      return 0;
}
