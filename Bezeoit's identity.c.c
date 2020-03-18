#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int a, b, r, q;
	
	printf("Welcome to the program which is written by Bezoet's theorem:\n");
	printf("This program aims to find r and q from the formula a=bq+r\n-------------------------------------------------------------------\n");
	printf("Input the value for a:");
	scanf("%d", &a);
	printf("Input the value for b:");
	scanf("%d", &b);
	if(a==0 && b==0)
		printf("Invalid");
	if(r>=0 && r<abs(b))
	{
		if(b>0)
		{
			q=floor(a/b);
			r=a-b*q;	
		}
		else
		{
			q=ceil(a/b);
			r=a-b*q;
		}	
	}
	else
		exit(1);	
	
	printf("The value of (%d, %d)\nThe formula: %d=%d*%d+(%d)", q, r, a, b, q, r);
	return 0;
}
