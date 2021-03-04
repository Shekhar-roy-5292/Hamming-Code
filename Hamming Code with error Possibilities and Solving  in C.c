#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
void Op();
int main()
{
	int n,j,k,i=0,sum =0,maxparity = 10;
	printf("Enter the no of elements : ");
	scanf("%d",&n);
	printf("%d\n",n);
	int s[n],temp[100],temp2[100],t,t1,t2,t3,MsgBit;
	void Op(){
	printf("number of Parity Bits is :%d \n",t3);
	int t4 = t3 + MsgBit;
    printf("Number of Hamming code is : %d\n",t4);
	// char Array[t4];
    for(i=0,j=0;i<n;i++)
    {
        for(k=0;k<maxparity;k++)
        {
            t=pow(2,k)-1;
            if(j==t)
            {
                temp[j]=0;
                j++;
            }
        }
        temp[j]=s[i];
        j++;
    }
    for(i=0;i<t4;i++)
    {
        printf("%d",temp[i]);
    }
    printf("\n");
    for(k=0;k<t3;k++)
    {
        t=pow(2,k)-1;
        for(i=t;i<t4;)
        {
            for(j=0;j<=t;j++)
            {
                sum=sum+temp[i];
                i++;
                if(i>=t4)
                    break;
            }
            if(i>=t4)
                break;
            for(j=0;j<=t;j++)
            {
                i++;
                if(i>=t4)
                    break;
            }
            if(i>=t4)
                break;
        }
        temp[t]=sum%2;
        sum=0;
        printf("At Position r%d: %d\n",t+1,temp[t]);
    }
    printf("\nHamming code From Sender :   ");
    for(i=0;i<t4;i++)
    {
        printf("%d ",temp[i]);
    }
        printf("\nHamming code From Receiver : ");
    for(i=0;i<t4;i++){
        temp2[i]=temp[i]; 
    }
    int count =1;
    srand(time(NULL));
    int t5 =rand()%t4+1;
    if(temp2[t5]==0){
        temp2[t5]=1;
    }
    printf(" Hamming code will be : ");
    for(i=0;i<t4;i++){
        printf("%d ",temp2[i]);
    }
    printf("\n");
    int b[t3];
    int m=t3-1;
    sum=0;
    for(k=0;k<t3;k++)
    {
        t=pow(2,k)-1;
        for(i=t;i<t4;)
        {
            for(j=0;j<=t;j++)
            {
                sum=sum+temp2[i];
                i++;
                if(i>=t4)
                    break;
            }

            if(i>=t4)
                break;

            for(j=0;j<=t;j++)
            {
                i++;
                if(i>=t4)
                    break;
            }
            if(i>=t4)
                break;
        }
        b[m]=sum%2;
        sum=0;
        printf("At Position r%d: %d\n",t+1,b[m]);
        m--;
    }
    int position = 0;
     for(m=0;m<t3;m++)
    {
        position=position+b[t3-m-1]*pow(2,m);
    }
	if(position != 0){
    printf("Position of Error: %d\n",position);
        if(temp2[position-1]==0)
        temp2[position-1]=1;
    else
        temp2[position-1]=0;

    printf("\nError Correction complete :  ");
    for(i=0;i<t4;i++)
    {
        printf("%d ",temp2[i]);
    	}
	}
	else{
		printf("\nNo Error ");
	}

}
	printf("Enter only binary numbers :");
	for(i=0;i<n;i++)
    {
		scanf("%d",&s[i]);
	}
	MsgBit = (int)(sizeof(s)/sizeof(s[0]));
	// printf("then massege type bits is %d\n",MsgBit);
	for(i=0;i<=7;i++)
    {
		t1=MsgBit+i+1;
		t2=pow(2,i);
		if(t2>=t1)
        {
			t3=i;
			Op();
		}
	}
	return 0;
}
