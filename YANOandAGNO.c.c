#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int num_less, num_sem, i, j, choice;
	float credit, credit_sum=0, sum=0, agno=1, grade, yano=1;
	while(1)
	{
		printf("Welcome to the note calculator!\nWhat do you want to calculate?\n1.YANO.\n2.AGNO.\nYour Choice:");
		scanf("%d",&choice);
		printf("Successful choice!\n");
		system("pause");
		system("cls");
		printf("The table of the grades:\n");
		printf("AA - 4.0\nBB - 3.5\nBB - 3.0\nCB - 2.5\nCC - 2.0\nDC - 1.5\nDD - 1.0\nFD - 0.5\nFF - 0.0\nF0 - 0.0");
		if(choice == 1)
		{
			printf("Input the number of the lessons:");
			scanf("%d",&num_less);
			for(i=0;i<num_less;i++)
			{
				printf("Input the credit of %d:", i+1);
				scanf("%f", &credit);
				if(credit>=0.0 || credit<=9.0)
					credit_sum+=credit;
				else
					exit(0);
				printf("Input the grade of %d:",i+1);
				scanf("%f",&grade);
				if(grade>=0.0 || grade<=4.0)
				{
					if(grade == 4.0)
						sum+=4*credit;
					else if(grade == 3.5)
						sum+=3.5*credit;
					else if(grade == 3.0) 
						sum+=3.0*credit;
					else if(grade == 2.5)
						sum+=2.5*credit;
					else if(grade == 2.0)
						sum+=2.0*credit;
					else if(grade == 1.5)
						sum+=1.5*credit;
					else if(grade == 1.0)
						sum+=1.0*credit;
					else if(grade == 0.5)
						sum+=0.5*credit;
					else if(grade == 0.0)
						sum+=0.0*credit;
					else
						exit(1);
				}
				else
					exit(1);
			}
			yano=sum/credit_sum;
			printf("YANO:%f", yano);
		}
		if(choice == 2)
		{
		printf("Input the number of semester:");
		scanf("%d",&num_sem);
		for(i=0;i<num_sem;i++)
		{
			printf("Input the number of lessons in %d semester:",i+1);
			scanf("%d",&num_less);
			for(j=0;j<num_less;j++)
			{
				printf("Input the credit of %d lesson in %d semester:", j+1);
				scanf("%f", &credit);
				if(credit>=0.0 || credit<=9.0)
					credit_sum+=credit;
				else
					exit(0);
				printf("Input the grade:");
				scanf("%f",&grade);
				if(grade>=0.0 || grade<=4.0)
				{
					if(grade == 4.0)
						sum+=4*credit;
					else if(grade == 3.5)
						sum+=3.5*credit;
					else if(grade == 3.0) 
						sum+=3.0*credit;
					else if(grade == 2.5)
						sum+=2.5*credit;
					else if(grade == 2.0)
						sum+=2.0*credit;
					else if(grade == 1.5)
						sum+=1.5*credit;
					else if(grade == 1.0)
						sum+=1.0*credit;
					else if(grade == 0.5)
						sum+=0.5*credit;
					else if(grade == 0.0)
						sum+=0.0*credit;
					else
						exit(1);
				}
				else
					exit(1);	
				}
			}
			agno=sum/credit_sum;
			printf("AGNO:%f",agno);
		}
	}
}

