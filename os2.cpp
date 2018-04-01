#include<stdio.h>
#include<conio.h>
int main()
{
	int burst[100],priority[100],Q[100],queue1[100],queue2[100],s[100],arrival[100],s[100];
	int n,n1,time=3,i;
	int t=0;
	printf("Enter number of processor :");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		s[i]=i;
		printf("Enter the burst time of processor %d :",i);
		scanf("%d",&burst[i]);
		printf("Enter the arrival time of processor %d :",i);
		scanf("%d",&arrival[i]);
		printf("Enter the priority of processor %d :",i);
		scanf("%d",&priority[i]);
		printf("Enter the queue number to which processor %d belongs to:",i);
		scanf("%d",&Q[i]);
	}
	printf("\n");
	printf("process    burst_time  arrival_time   priority   queue\n");
	for(i=0;i<n;i++)
	{
		printf("%d          %d            %d             %d           %d\n",i,burst[i],arrival[i],priority[i],Q[i]);
	}
	int k=0,l=0;
	for(i=0;i<n;i++)
	{
		if(Q[i]==1)
		{
			queue1[k]=i;
			k++;
		}
		else
		{
			queue2[l]=i;
			l++;
		}
	}
	printf("\n");
	printf("processor in queue1 :");
	for(i=0;i<k;i++)
	{
		printf("p%d ",queue1[i]);
	}
	printf("\nprocessor in queue2 :");
	for(i=0;i<l;i++)
	{
		printf("p%d ",queue2[i]);
	}
	printf("\n");
	n1=l;
	printf("\n");
	for(i=0;i<n1;i++)
	{
		printf("%d-p%d-",t,queue2[i]);
		for(int j=1;j<=time;j++)
		{
			if(burst[queue2[i]]>0)
			{
				t=t+1;
				burst[queue2[i]]-=1;
			}
		}
		printf("%d ",t);
		if(burst[queue2[i]]!=0)
		{
			queue2[n1]=queue2[i];
			n1=n1+1;
		}
		
	}
}
