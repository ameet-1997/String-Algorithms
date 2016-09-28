/*
Knuth-Morris-Prath Algorithm

This algoritm is used to search for a given substring in a given string and
returns the position of the initial index of the matchings

Inputs: Larger String S, Substring to find W
Outputs: The positions of matching

Ameet S Deshpande
CS15B001

*/

/*
Tested and verified for various test cases
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
# define NO_OF_CHARS 256


int main()
{	void build_table(char*,int*,int);	//This function builds the table

	char w[20],s[100];		//w stores the substring, s the string in which searching happens
	int *t,*ans;		// t is the table that is preconstructed
	int len;	//Stores the length of the substring

	int i,m;	//Markers for the two arrays
	int count=0;

	scanf("%s",w);	
	scanf("%s",s);

	len=strlen(w);

	t=(int*) malloc(sizeof(int)*len);
	ans=(int*) malloc(sizeof(int)*len);

	ans[0]=-1;	//As an internal flag

	build_table(w,t,len);

	for(i=0;i<len;++i)
	{
		printf("%d ",t[i]);
	}
	printf("\n");

	printf("Built table\n");

	i=0;	//For main array
	m=0;	//For substring array

	while(s[i+m]!='\0')
	{	
		if(w[m]=='\0')
		{
			ans[count]=i;
			count++;
			i=i+(m-1)-t[m-1];

			if(t[m-1]>0)
			{
				m=(m-1)-t[m-1];
			}
			else
			{
				m=0;
			}

			//m=(m-1)-t[m-1];
			//i=i+m;
			//break;
		}

		else
		{
			if(s[i+m]==w[m])
			{
				m++;
			}

			else
			{
				i=i+m-t[m];

				if(t[m]>0)
				{
					m=m-t[m];
				}
				else
				{
					m=0;
				}
				
			}	
		}
		
	}


	if(ans[0]!=-1)
	{
		for(i=0;i<count;++i)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
	}


	free(t);
	free(ans);

	return 0;

}


void build_table(char *w,int *t,int len)
{	
	int i;	//Loop variable
	int check=-1;	//The new position to be checked


	t[0]=-1;

	for(i=1;i<len;++i)
	{
		if(t[i-1]<=0)
		{
			if((w[0]==w[i-1])&&(i!=1))
			{
				t[i]=1;

				check=1;
			}
			else
			{
				t[i]=0;

				check=0;
			}

		}

		else
		{
			if(w[i-1]==w[check])
			{
				check++;
				t[i]=t[i-1]+1;
			}
			else
			{
				t[i]=t[t[i-1]]+1;
				check=t[t[i-1]];

				if(w[i-1]!=w[check])
				{
					t[i]=0;
					check=0;
				}
				else
				{
					check++;
				}
				
			}
		}
	}

	return;
}


 


 

