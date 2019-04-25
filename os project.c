#include<stdio.h>
#include<stdlib.h>
struct priority_scheduling 
	{
	    int pid, at, bt, priority;
		int flag,wt;
		int tt;
    };
int main () 
{
    int a,i,j;
    int TimeQ=1;
    int wt;
    printf("Enter Total Number of Processes: ");
    scanf("%d", & a);
    struct priority_scheduling p1[a];
    struct priority_scheduling p2[a];
    struct priority_scheduling pt[a];
    int flag = 1;
    int Qlevel=1;
    int q1 = 0, q2 = 0;	
    for (i = 0; i < a; i++) 
	{
            printf("\n\nEntre Process ID         : ");
            scanf("%d", & p1[q1].pid);
            printf("Entre Arrival Time of %d    : ",p1[q1].pid);
            scanf("%d", & p1[q1].at);
            printf("Entre Burst Time of %d      : ",p1[q1].pid);
            scanf("%d", & p1[q1].bt);
            printf("EntreProcess Priority of %d : ",p1[q1].pid);
            scanf("%d", & p1[q1].priority);
	        p1[q1].flag=0;
            p1[q1].wt=0;
            p1[q1].tt=0;	
            pt[i]=p1[q1];
            q1++;
        }
    printf("\nProcess ID \tArrival Time \tPriority \tBurst Time ");
    for (i = 0; i < q1; i++) 
	{
        printf("\n%d\t\t%d\t\t%d\t\t%d", p1[i].pid, p1[i].at, p1[i].priority, p1[i].bt);
    }
   
    struct priority_scheduling temp;
    i=0;
    j=0;
    for (i = 1; i < q1; i++)
        for (j = 0; j < q1 - i; j++) 
		{
            if (p1[j].at > p1[j + 1].at) 
			{
                temp = p1[j];
                p1[j] = p1[j + 1];
                p1[j + 1] = temp;
               
            }
        }
      i=0;
	  j=0;  
         for (i = 1; i < q1; i++)
         for (j = 0; j < q1 - i; j++) 
		{
            if (p1[j].at==p1[j + 1].at &&p1[j].priority>p1[j + 1].priority) 
			{
                temp = p1[j];
                p1[j] = p1[j + 1];
                p1[j + 1] = temp;
            }
        }
    //printf("\n\n \t\t\tBefore Arrival of Context Swiching\n\n"); 
	int l1 = q1;
    i = 0;
    int run;
    for (run = 0;; run++) 
	{
    	if (q1 == 0) 
		{
            break;
        }
        //premepts previous process
    	if (p1[i]. priority > p1[i + 1].priority && p1[i + 1].at == run) 
		{	
	        p2[q2] = p1[i];	
	        p2[q2].at = run;
		    p2[q2].flag=0;
	        p2[q2].priority = p1[i].priority;
	        printf("\n\n\t\tContext Swiching Arrival in Process %d \n ", p1[i].pid);
	        q1--;
	        q2++;
	        i++;
    	}
        
		if (p1[i].at <= run && p1[i].bt != 0) 
		{
			if(p1[i].flag==0)
			{	
				p1[i].wt+=((run)-p1[i].at);
				p1[i].flag=1;
			}
	        
			printf("\nProcess ID %d  Priority %d Burst Time %d time %d", p1[i].pid, p1[i].priority, p1[i].bt, (run+1));
			p1[i].bt--;
        } 
		else if (p1[i].bt == 0) 
		{
        	printf("\t\t\tProcess %d has Completed ",p1[i].pid);
            q1--;
	        run--;
            i++;
        }
    }
    int k=0;
    i=0;
    for (i = 0; i < l1; i++) 
	{
		 for(k=0;k<a;k++)
		{	
			if(p1[i].pid==pt[k].pid)
			{	
				pt[k].wt=p1[i].wt;
				
			}
		}
	}
	printf("\n");
    printf("\n\t\t\t Process Restarted after Context Swiching\n\n");
    
	int l2 = q2; 
    
    for (i = 0; i < q2; i++) 
	{
        printf("\nProcess ID %d\tpriority %d\t Arrival Time %d \tBurst Time %d", p2[i].pid,p2[i].priority, p2[i].at, p2[i].bt);
    }
   
    for (i = 1; i < q2; i++) 
	{
        for (j = 0; j < q2 - i; j++) 
		{
            if (p2[j].priority > p2[j + 1].priority) 
			{
                temp = p2[j];
                p2[j] = p2[j + 1];
                p2[j + 1] = temp;
            }
        }
    }
    printf("\n\n");
    i = 0;
    int rs = 0;
    for (run;; run++) 
     {
        if (l2 == 0)
        {
            break;
		}
    	if(p2[i].bt == 0)
        {
            printf("\t\t\tProcess %d has Completed", p2[i].pid);
            i++;
	        run--;
            l2--;
            rs = 0;
            continue;
        }
     
        
        if (p2[i].at <= run && p2[i].bt != 0)
        {
	 		if(rs==0&&p2[i].pid!=p2[i-1].pid)
			{	
				p2[i].wt+=(run-p2[i].at+1);
	
				p2[i].flag=1;
			} 
			printf("\nProcess ID %d  Burst Time %d Time Taken %d", p2[i].pid, p2[i].bt, run);
			p2[i].bt --;
        }
         else if (p2[i].bt == 0)
	 {

     
            printf("\t\t\t\t\t Process %d has Completed\n", p2[i].pid);
            i++;
	        run--;
            l2--;
	        rs = 0;
      }
      rs++;
    }
   for (i = 0; i < q2; i++) {
	 for(k=0;k<a;k++)
	{	
		if(p2[i].pid==pt[k].pid)
		{	
			pt[k].wt=p2[i].wt;
			
		}
	}
	}

	float avg_wait_time=0;
    float avg_turn_time=0;
    
	printf("\n\n\t\t -----------FINAL TABLE -------------\n");
    printf("\nProcess ID \tArrival Time \tBurst Time \twaiting Time \tTurn Time");
	for (i = 0; i < a; i++) 
	{
	pt[i].tt=pt[i].bt+pt[i].wt;
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", pt[i].pid, pt[i].at,pt[i].bt, pt[i].wt,pt[i].tt);
	avg_wait_time+=pt[i].wt;
	avg_turn_time+=pt[i].tt;
    }
    printf("\n");
	avg_wait_time/=a;
    avg_turn_time/=a;
	printf("Average Waiting Time    : %.2f\n",avg_wait_time);
    printf("Average TurnAround Time : %.2f\n",avg_turn_time);
}
