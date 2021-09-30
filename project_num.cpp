#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int table[4][4];
int frx,fry;
struct realval{
	int x,y;
}v[10];
int prevfx=69,prevfy=69;
void setval()
{
	int z=1;
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			v[z].x=j;
			v[z].y=i;
			printf("z = %d ; i = %d ; j = %d\n",z,v[z].y,v[z].x);
			z++;
		}
	}
	v[0].x=2;
	v[0].y=2;
	
}

void shwtbl ()
{
	printf("***********************\n");
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			printf("%d ",table[i][j]);
		}printf("\n");
	}
	printf("\n***********************\n");
}
void swap(int changex,int changey,int freex,int freey)
{
	table[freey][freex]=table[freey+changey][freex+changex];
	table[freey+changey][freex+changex]=0;
}
void swapback(int changex,int changey,int freex,int freey)
{
	table[freey+changey][freex+changex]=table[freey][freex];
	table[freey][freex]=0;
	
}
int abs(int x)
{
	if(x>0)
	return x;
	
	return -x;
}
int imp_val (int changex,int changey,int freex,int freey)
{

//	printf("chx = %d ; chy = %d ; frx = %d ; fry = %d\n",changex,changey,freex,freey);
	swap(changex,changey,freex,freey);
	int sum=0;
	for(int i=0;i<=2;i++)
	for(int j=0;j<=2;j++)
	{
		sum+=abs(v[table[i][j]].x-j)+abs(v[table[i][j]].y-i);
		
	//	printf("i = %d ; j = %d ;; %d \nsum += %d + %d\n",i,j,table[i][j],v[table[i][j]].x-j,abs(v[table[i][j]].y-i));
	}
//	printf("sum = %d\n",sum);
	
	swapback(changex,changey,freex,freey);
	return sum;
}

int findway()
{
	int chx,chy;
	int impval=2e9;
	int i,j;
	//printf("** prfx = %d ; prfy = %d\n",prevfx,prevfy);
	for(i=-1;i<=1;i++)
	{
		for(j=-1;j<=1;j++)
		{
			if(i!=j)
			if(abs(i-j)==1)
			{
				if(frx+j>=0 and frx+j<=2)
				if(fry+i>=0 and fry+i<=2)
				{
					//printf("frx+j = %d ; fry+i = %d\n",frx+j,fry+i);
					if(!(frx+j==prevfx and fry+i==prevfy))
					{
						int temp=imp_val(j,i,frx,fry);
						if(temp<impval)
						{		
							impval=temp;
							chx=j,chy=i;
						}
					}
					
				}
			}
		}
	}
	printf("\nchx = %d ; chy = %d\n",chx,chy);
	swap(chx,chy,frx,fry);
	shwtbl();
	prevfx=frx;
	prevfy=fry;
	frx=frx+chx;
	fry=fry+chy;
	return impval;
}

main()
{
	//setval();
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{	int z;
			scanf("%d",&z);
			v[z].x=j;
			v[z].y=i;
		}
		
	}
	
	
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			scanf("%d",&table[i][j]);
			if(table[i][j]==0)
			{
				frx=j,fry=i;
			}
		}
		
	}
	while(1)
	{
		if(findway()==0)
		break;
	}
}
/* 1 2 3
8 0 4
7 6 5
1 3 4
8 0 5
7 2 6*/ 
