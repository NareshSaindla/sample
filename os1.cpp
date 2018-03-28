#include<stdio.h>
#include<conio.h>
int main()
{
	int burst[100],priority[100],Q[100],queue1[100],queue2[100],s[100];
	int n,n1,time=3;
	int t=0;
	printf("Enter number of processor :");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		s[i]=i;
		printf("Enter the burst time of processor %d :",i);
		scanf("%d",&burst[i]);
		printf("Enter the priority of processor %d :",i);
		scanf("%d",&priority[i]);
		printf("Enter the queue number to which processor %d belongs to:",i);
		scanf("%d",&Q[i]);
	}
	printf("process    burst_time   priority  queue\n");
	for(int i=0;i<n;i++)
	{
		printf("%d          %d            %d         %d\n",i,burst[i],priority[i],Q[i]);
	}
	n1=n;
	for(int i=0;i<n1;i++)
	{
		printf("%d-p%d-",t,s[i]);
		for(int j=1;j<=time;j++)
		{
			if(burst[s[i]]>0)
			{
				t=t+1;
				burst[s[i]]-=1;
			}
		}
		printf("%d ",t);
		if(burst[s[i]]!=0)
		{
			s[n1]=s[i];
			n1=n1+1;
		}
		
	}
}
