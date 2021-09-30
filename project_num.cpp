#include<stdio.h>
#include<map>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct data{
	int dx,md,val;
	char from[10];
	int owntable[4][4];
	int freei,freej;
	bool chc;

	bool operator <(const data &a)const{
		return a.val<val;
	}
	
}d;

struct sateeng{
	char xx[10];
}st;
stack <sateeng> sx;

priority_queue <data> q;
map <string,data> m;

struct tableset{
	int i,j;
}startz[10],endz[10];

struct temp{
	char xz[10];
}t;
temp inttostring (data d)
{
	char xz[10];
	int a=0;
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++,a++)
		t.xz[a]=d.owntable[i][j]+'0';
	}
	return t;
}

int abs (int x)
{
	if(x>0)
	return x;
	
	return -x;
}


int mdcal(data d)
{
	int sum=0;
	for(int i=0;i<=2;i++)
	for(int j=0;j<=2;j++)
	{
		sum+=abs(endz[d.owntable[i][j]].i-i)+abs(endz[d.owntable[i][j]].j-j);
	}
	
	return sum;	
}

void shwtbl(data d)
{
	printf("\n*****************\n");
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			printf("%d ",d.owntable[i][j]);
				}		printf("\n");
	}printf("*****************\n");
	return ;
}

bool findway (data datax)
{
	//shwtbl(datax);
	if(mdcal(datax)==0)
	{
		return true;
	}
	
	
	for(int chi=-1;chi<=1;chi++)
	for(int chj=-1;chj<=1;chj++)
	{
		if(chi!=chj)
		if(abs(chi+chj)==1)
		{
			if(datax.freei+chi>=0 and datax.freei<=2)
			if(datax.freej+chj>=0 and datax.freej<=2)
			{
				int dd=0;
					for(int ii=0;ii<=2;ii++)
					for(int jj=0;jj<=2;jj++,dd++)
					d.from[dd]=datax.owntable[ii][jj]+'0';
					
				datax.owntable[datax.freei][datax.freej]=datax.owntable[datax.freei+chi][datax.freej+chj];
				datax.owntable[datax.freei+chi][datax.freej+chj]=0;
				
				if(!m[inttostring(datax).xz].chc)
				{
					d.dx=datax.dx+1;
					d.md=mdcal(datax);
					d.val=d.dx+d.md;
					d.freei=datax.freei+chi;
					d.freej=datax.freej+chj;
					d.chc=true;
					
					
					
					
					for(int ii=0;ii<=2;ii++)
					for(int jj=0;jj<=2;jj++,dd++)
					d.owntable[ii][jj]=datax.owntable[ii][jj];
					
					m[inttostring(d).xz]=d;
					q.push(d);
				}
				
				datax.owntable[datax.freei+chi][datax.freej+chj]=datax.owntable[datax.freei][datax.freej];
				datax.owntable[datax.freei][datax.freej]=0;
			}
		}
	}
	
	
	
	return false;
}
void creditz()
{
	printf("\n\n\n\n");
	char xx[6][69]={"8-Puzzle Solver  ","\" project_num \"","version 4 (domanbu build)","by colormarked_","25/8/2019"};
	for(int i=0;i<=4;i++)
	printf("\t%s\n",xx[i]);
}
void printsx (sateeng sss)
{
	printf("\n******************\n");
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		printf("%c ",sss.xx[i*3+j]);
		
		printf("\n");
	}
	printf("\n******************\n");
}
char ww[10];
char tt[10];
main()
{
	for(int i=0;i<=2;i++)
	for(int j=0;j<=2;j++)
	{
		int xz;
		scanf("%d",&xz);
		startz[xz].i=i;
		startz[xz].j=j;
		
		d.owntable[i][j]=xz;
		if(xz==0)
		{
			d.freei=i;
			d.freej=j;
		}
	}
	d.from[0]='H';
	d.from[1]='A';
	d.from[2]='Y';
	d.chc=true;
	d.dx=0;
	d.md=mdcal(d);
	d.val=d.dx+d.md;
	q.push(d);
	m[inttostring(d).xz]=d;
	for(int i=0;i<=2;i++)
	for(int j=0;j<=2;j++)
	{
		int xz;
		scanf("%d",&xz);
		endz[xz].i=i;
		endz[xz].j=j;
	}
/*	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		scanf("%d",&table[i][j]);
	}
//	char xz[10]=inttostring().xz;
	printf("%s",inttostring().xz);
*/	
	while(!q.empty())
	{
		data temp = q.top();
		q.pop();
		if(findway(temp))
		{
			
			int dd=0;
			for(int ii=0;ii<=2;ii++)
			for(int jj=0;jj<=2;jj++,dd++)
			{
			ww[dd]=temp.owntable[ii][jj]+'0';	
			st.xx[dd]=ww[dd];
			}
			sx.push(st);
			
			
			while(m[ww].from[0]!='H')
			{
			//	printf("YO\n");
			//	printf("%s\n",ww);
				
			
				for(int i=0;i<=8;i++)
				{
				tt[i]=m[ww].from[i];	
				st.xx[i]=tt[i];
				
				}//printf("stxx = %s\n",st.xx);
				sx.push(st);
				
				for(int i=0;i<=8;i++)
				ww[i]=tt[i];
			}
			
			while(!sx.empty())
			{
//				sateeng ss;
//				for(int i=0;i<=8;i++)
//				ss.xx[i]=sx.top().xx[i];
//				sx.pop();
//				printf("%s\n\n",ss.xx);
				printsx(sx.top());
				sx.pop();
			}
			
			creditz();
			
			return 0;
		}
		
	}
	
}

/*

1 2 3
5 6 0
7 8 4
1 2 3
4 5 6
7 8 0
*/
