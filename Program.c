#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	int turn =1;
	while(turn<=t)
	{
		int r,c,m;
		scanf("%d %d %d",&r,&c,&m);
		char a[60][60]={'.'};
		int i=0,j=0;
		for(i=0;i<r;i++) //initiating matrix with '.'
		{
			for(j=0;j<c;j++)
			{
				a[i][j]='.';
			}
		}
		int mines=m;
		int flag=0;  //at the end if flag is still zero, then the case is impossible.
		
		if(r==1 || c==1) // if either number of rows or number of columns is one. This case would always get accepted.
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					if(mines>0)
					{
						a[i][j]='*';
						mines--;
					}
					else break;
				}
			}
			a[r-1][c-1]='c';
			flag=1;
			printf("Case #%d:\n",turn);
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
			goto imp;
		}

		if(c==2 && !(m == (r*c)-1))  //If number of columns is 2, and m is not equal to one less than total number of blocks
		{
			if(m%2==1)  //If number of mines are odd in this case, it would never be possible.
			{
				goto imp;
			}
			
			if(m>(r*c)-4)  //If (r*c)-4 < number of mines < (r*c)-1
			{
				goto imp;
			}
			
			for(i=0;i<r;i++)  //all remaining cases here will be possible.
			{
				for(j=0;j<c;j++)
				{
					if(mines>0)
					{
						a[i][j]='*';
						mines--;
					}
					else break;
				}
			}
			a[r-1][c-1]='c';
			flag=1;
			printf("Case #%d:\n",turn);
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
			goto imp;
		}

		if(r==2 && !(m == (r*c)-1))  //If number of rows is 2, and m is not equal to one less than total number of blocks
		{
			if(m%2==1)  //If number of mines are odd in this case, it would never be possible.
			{
				goto imp;
			}
			
			if(m>(r*c)-4)  //If (r*c)-4 < number of mines < (r*c)-1
			{
				goto imp;
			}
			
			for(j=0;j<c;j++)  //all remaining cases here will be possible.
			{
				for(i=0;i<r;i++)
				{
					if(mines>0)
					{
						a[i][j]='*';
						mines--;
					}
					else break;
				}
			}
			a[r-1][c-1]='c';
			flag=1;
			printf("Case #%d:\n",turn);
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
			goto imp;
		}
		
		if(mines == (r*c)-1)  //if number of mines is one less than total number of blocks. Solution is always possible.
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					a[i][j]='*';
				}
			}
			a[r-1][j-1]='c';
			flag=1;
			printf("Case #%d:\n",turn);
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
			goto imp;
		}

		int h1=0;
		for(i=0;i<r-3;i++)  //rest all cases
		{
			for(j=0;j<c;j++)
			{
				if(mines==1 && j==c-2)  //if last mine is to be filled in second last column, it would be wrong case. Setting offset.
				{
					h1=1;
					break;
				}
				if(mines>0)
				{
					a[i][j]='*';
					mines--;
				}
			}
			if(h1==1)
				break;
		}

		if(h1==1)  // if last mine is to be placed in second last column, making a correct apprach.
		{
			a[i+1][0]='*';
			mines--;
		}

		int h2=0;
		for(j=0;j<c;j++)
		{
			for(i=r-3;i<r;i++)
			{
				if(mines==1 && i==r-2)  ////if last mine is to be filled in second last row, it would be wrong case. Setting offset.
				{
					h2=1;
					break;
				}
				if(mines==1 && j==c-2)
				{
					goto imp;
				}
				if(mines>0)
				{
					a[i][j]='*';
					mines--;
				}
				else break;
			}
			if(h2==1)
				break;
		}

		if(h2==1)  // if last mine is to be placed in second last row, making a correct apprach.
		{
			a[r-3][j+1]='*';
			mines--;
			if(j+1==c-2)
				goto imp;
		}

		a[r-1][c-1]='c';

		if(a[r-2][c-2]=='*' || a[r-1][c-2]=='*' || a[r-2][c-1]=='*') //If 'c' is surrounded by mine
			goto imp;

		flag=1;
		printf("Case #%d:\n",turn);  //printing out the solution
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("%c",a[i][j]);
			}
			printf("\n");
		}

		imp:
		if(flag==0)  //printing out impossible if flag=0
		{
			printf("Case #%d:\n",turn);
			printf("Impossible\n");
		}

		turn++;
	}


	return 0;
}
