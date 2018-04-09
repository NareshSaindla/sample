#include<stdio.h>
#include<conio.h>
int burst[10],priority[10],Q[10],queue1[10],queue2[10],s[10],arrival[10],p[10],s1[10],p1[10],burst1[10],burst2[10],arrival1[10],priority1[10];
int n,n1=0,n2=0,time=3;
int t=0,a;
int k=0,l=0;
int priority_scheduling();
void sort();
void delete1();
int main()
{
	printf("Enter number of processor :");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		p[i]=i;
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
	for(int i=0;i<n;i++)
	{
		printf("%d          %d            %d             %d           %d\n",p[i],burst[i],arrival[i],priority[i],Q[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(Q[i]==1)
		{
			queue1[k]=p[i];
			k++;
		}
		else
		{
			queue2[l]=p[i];
			l++;
		}
	}
	printf("\n");
	printf("processor in queue1 :");
	for(int i=0;i<k;i++)
	{
		printf("p%d ",queue1[i]);
		if(arrival[queue1[i]]==0)
		{
			s1[n1]=queue1[i];
			burst1[n1]=burst[queue1[i]];
			arrival1[n1]=arrival[queue1[i]];
			priority1[n1]=priority[queue1[i]];
			burst2[n1]=burst1[queue1[i]];
			n1=n1+1;
		}
	}
	printf("\nprocessor in queue2 :");
	for(int i=0;i<l;i++)
	{
		printf("p%d ",queue2[i]);
		if(arrival[queue2[i]]==0)
		{
			s[i]=queue2[i];
			n2=n2+1;
		}
		
	}
	printf("\n");
	printf("\n");
	
first:
	{
	
	do
	{
		priority_scheduling();
	}while(n1>1); 
}
	
	// round robin
	for(int i=0;i<n2;i++)
	{
		printf("%d-p%d-",t,s[i]);
		for(int j=1;j<=time;j++)
		{
			if(burst[s[i]]>0)
			{
				t=t+1;
				burst[s[i]]-=1;
			}
			for(int k1=0;k1<l;k1++)
			{
				if(arrival[queue2[k1]]==t)
				{
					s[n2]=queue2[k1];
					n2=n2+1;
				}
			}
			for(int i6=0;i6<k;i6++)
				{
					if(arrival[queue1[i6]]==t)
					{
						s1[n1]=queue1[i6];
						burst1[n1]=burst[queue1[i6]];
						arrival1[n1]=arrival[queue1[i6]];
						priority1[n1]=priority[queue1[i6]];
						n1=n1+1;
						printf("%d ",t);
						goto first;
					}
				}
		}
		printf("%d ",t);
		if(burst[s[i]]!=0)
		{
			s[n2]=s[i];
			n2=n2+1;
		}
		
	}
}
int priority_scheduling()
{
	if(n1!=0)
	{
		sort();
		for(int i4=0;i4<n1;i4++) 
		{
			printf("%d-p%d-",t,s1[i4]);
			for(int i5=1;i5<=burst1[s1[i4]];i5++)
			{
				if(burst2[s1[i4]]>0)
				{
					t=t+1;
					burst2[s1[i4]]-=1;
				}
				for(int k1=0;k1<l;k1++)
				{
					if(arrival[queue2[k1]]==t)
					{
						s[n2]=queue2[k1];
						n2=n2+1;
					}
				}
				for(int i6=0;i6<k;i6++)
				{
					if(arrival[queue1[i6]]==t)
					{
						s1[n1]=queue1[i6];
						burst1[n1]=burst[queue1[i6]];
						arrival1[n1]=arrival[queue1[i6]];
						priority1[n1]=priority[queue1[i6]];
						n1=n1+1;
						printf("%d ",t);
						return 0;
					}
				}
			}
			printf("%d ",t);
			if(burst2[i4]=0)
			{
				delete1();
				return 0;
			}
		}
	}
	else{
		return 0;
	}
}
int x1,x2,x3,x4,x5;
void sort()
{
	for(int i2=0;i2<n1;i2++)
	{
		for(int i3=i2;i2<n1;i2++)
		{
			if(priority1[i2]>priority[i3])
			{
				x1=priority1[i2];
				priority1[12]=priority1[i3];
				priority1[13]=x1;
				x2=burst1[i2];
				burst1[i2]=burst1[i3];
				burst1[i3]=x2;
				x3=p[i2];
				s1[i2]=s1[i3];
				s1[i3]=x3;
				x4=arrival1[i2];
				arrival1[i2]=arrival1[i3];
				arrival1[i3]=x4;
				x5=burst2[i2];
				burst2[i2]=burst2[i3];
				burst2[i3]=x5;
			}
		}
	}
}
void delete1()
{
	for(int i7=0;i7<n1-1;i7++)
	{
		arrival1[i7]=arrival1[i7+1];
		burst1[i7]=burst1[i7+1];
		burst2[i7]=burst2[i7+1];
		priority1[i7]=priority1[i7+1];
		p1[i7]=p[i7+1];
	}
	n1=n1-1;
}
