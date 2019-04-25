#include<stdio.h>
#include<stdlib.h>

struct process

{
	int name;
	float bt;float at;float status;float wt;float tat;

};

void display(struct process pro[],int num)

{
	int i;
	printf("All input process details are: \n");
	printf("Process\tBurst-time\tArrival-time\n");
	for(i=0;i<num;i++)
	{
	  printf("p%d\t%f\t%f\n",pro[i].name,pro[i].bt,pro[i].at);
    }
	printf("\n");
}

void sort(struct process pro[],int num)
{
	int i,j;//variables for iteration
	struct process temp;
	for(i=0;i<num-1;i++)//use of sort
    {
        for(j=i+1;j<num;j++)
        {
            if(pro[i].at>pro[j].at){
				//here we will swap the process wth the lesser arrival time one
                temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
			}
        }

 	}


}

void schedule(struct process pro[],int num,int sum){
	int i,j;
	float f,avgWaitTime=0,avgtat=0;
	sort(pro,num);
	printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");
	for(f=pro[0].at;f<(float)sum;)
	
	{
		float pr=-9999;
		int nxt;
		float temp;
		for(i=0;i<num;i++){

			if(pro[i].at<=f && pro[i].status!=1){
				temp=(pro[i].bt + (f - pro[i].at)) / pro[i].bt;
				if(pr<temp){

					pr=temp;
					nxt=i;
				}
			}
		}

		f=pro[nxt].bt+f;

		pro[nxt].wt=f-(pro[nxt].at)-(pro[nxt].bt);

		pro[nxt].tat=f-pro[nxt].at;

		avgWaitTime+=pro[nxt].wt;

		avgtat+=pro[nxt].tat;

		pro[nxt].status=1;

		printf("p%d\t%f\t%f",pro[nxt].name,pro[nxt].bt,pro[nxt].at);
		printf("\t%f\t%f\n",pro[nxt].wt,pro[nxt].tat);

	}
	printf("Avg wait time=%f\n",avgWaitTime/num);
	printf("Avg turn-around time=%f\n",avgtat/num);

}

int main()
	{
	int i;//for loop
	float arr,burst,sum=0;//assigned sum=0
	static int num;//it will hold the number of process
	struct process pro[10];//this is the array to hold multiple propeties of a process
	printf("\t\tOS Process Priority PROJECT:\n");
	printf("Enter the number of processes");
	scanf("%d",&num);

	printf("\nEnter the info for the %d processes:\n",num);

	
	for(i=0;i<num;i++)
	
	{

		pro[i].name=i+1;
		printf("Process_p%d\n",pro[i].name);

		printf("Burst-time:");
		scanf("%f",&burst);
		pro[i].bt=burst;

		printf("Arrival-time:");
		scanf("%f",&arr);
		pro[i].at=arr;

		pro[i].status=0;
		sum+=pro[i].bt;

		printf("\n");
	}
	
	

	display(pro,num);

	
	sort(pro,num);


	schedule(pro,num,sum);
}
