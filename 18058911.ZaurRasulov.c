#include<stdio.h>
#include<stdlib.h>
 // All the T(n) functions are calculated in the comments! 
struct node
{
	float coef;
	int exp;
	struct node *link;
};

struct node *create(struct node *);
struct node *insert_s(struct node *,float,int);
struct node *insert(struct node *,float,int);
void display(struct node *ptr);
void poly_addition(struct node *,struct node *);
void poly_multiplication(struct node *,struct node *);



// creation
struct node *create(struct node *start)
{
 	int i,n,ex;
 	float co;
 	printf("Enter the number of terms : ");
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)                                  // 2n+2       // T(N) = 2N+2+6=2N+8    T(N)=O(N)
 	{
 		printf("Enter coeficient for term %d : ",i);   //1
 		scanf("%f",&co);                               //1
 		printf("Enter exponent for term %d : ",i);     //1
 		scanf("%d",&ex);                               //1
 		start=insert_s(start,co,ex);                   //2
	}
 	return start;
}

// insertion
struct node *insert_s(struct node *start,float co,int ex)
{
 	struct node *ptr,*temp;
 	temp=(struct node *)malloc(sizeof(struct node));
 	temp->coef=co;
 	temp->exp=ex;
 	//either empty list or exp is greater than the first one;
 	if(start==NULL || ex > start->exp)
 	{
 		temp->link=start;                             //1
 		start=temp;                                   //1
 	}
 	else
 	{
 		ptr=start;                                        //1 
 		while(ptr->link!=NULL && ptr->link->exp >= ex)    
 			ptr=ptr->link;                                    //1
 		temp->link=ptr->link;                         //1  
 		ptr->link=temp;                               //1
	}
 	return start;
}

// insertion
struct node *insert(struct node *start,float co,int ex)
{
 	struct node *ptr,*temp;
 	temp=(struct node *)malloc(sizeof(struct node));
 	temp->coef=co;
 	temp->exp=ex;
 	// Empty list
 	if(start==NULL)
 	{
 		temp->link=start;      //1
 		start=temp;               // 1 
 	}	
 	else // Insert at the end
 	{
 		ptr=start;             //1
 		while(ptr->link!=NULL)   //1
 			ptr=ptr->link;     //1
 		temp->link=ptr->link;  //1
 		ptr->link=temp;       //1
 	}
 	return start;
}


//display
void display(struct node *ptr)
{
 	if(ptr==NULL)
 	{
 		printf("Zero polynomial\n");          //1
 		return;                       //1
 	}
 	while(ptr!=NULL)
 	{
 		printf("(%.1fx^%d)", ptr->coef,ptr->exp);
 		ptr=ptr->link;
 		if(ptr!=NULL)
 			printf(" + ");  //1
 		else
 			printf("\n"); //1
 	}
}

void poly_addition(struct node *p1,struct node *p2)
{
 	struct node *start3;
 	start3=NULL;
 	while(p1!=NULL && p2!=NULL)
 	{
 		if(p1->exp > p2->exp)
 		{
 			start3=insert(start3,p1->coef,p1->exp);//1
	 		p1=p1->link;  //1
 		}
 		else if(p2->exp > p1->exp)
 		{
 			start3=insert(start3,p2->coef,p2->exp);  //1
 			p2=p2->link;   //1 
 		}
 		else if(p1->exp==p2->exp)
 		{
 			start3=insert(start3,p1->coef+p2->coef,p1->exp);  //1 
 			p1=p1->link;  //1
 			p2=p2->link; //1 
 		}
 	}
	 /*if poly2 has finished and elements left in poly1*/
 	while(p1!=NULL)
 	{
 		start3=insert(start3,p1->coef,p1->exp);
 		p1=p1->link;
 	}
 	/*if poly1 has finished and elements left in poly2*/
 	while(p2!=NULL)
 	{
 		start3=insert(start3,p2->coef,p2->exp);
 		p2=p2->link;
 	}
 	printf("Added polynomial is : ");
 	display(start3);
}

void poly_multiplication(struct node *p1, struct node *p2)
{
 	struct node *start3;
 	struct node *p2_beg = p2;
 	start3=NULL;
 	if(p1==NULL || p2==NULL)
 	{
 		printf("Multiplied polynomial is zero polynomial\n");      //1
 		return;   //1
 	}
 	while(p1!=NULL)
 	{
 		p2=p2_beg;
 		while(p2!=NULL)
 		{
 			start3=insert_s(start3,p1->coef*p2->coef,p1->exp+p2->exp);
 			p2=p2->link;
 		}
		p1=p1->link;
 	}
 	printf("Multiplied polynomial is : ");
 	display(start3);
}
int main(void)
{
 	struct node *start1=NULL,*start2=NULL;
 	int choice;
 	char name[20];
	int choice1;
	printf("===========================Welcome!=====================\n");
	printf("This is the program doing operations with the polynomials!\n");
	printf("Input your name:");
	scanf("%s",&name);
	
 	while(1){
		printf("Welcome %s!\nChoose the operation:\n1. Addition of polynomials\n2. Multiplication of polynomials\n3. Exit\nChoice:", name);
		scanf(" %d", &choice1);
		printf("Enter polynomial 1 :\n");
		start1=create(start1);
		printf("Enter polynomial 2 :\n");
		start2=create(start2);
		printf("Polynomial 1 is : ");
		display(start1);
 		printf("Polynomial 2 is : ");
 		display(start2);
 		printf("Choose the operation:\n1. Addition of polynomials\n2. Multiplication of polynomials\nTo exit press any button\nChoice:");
 		scanf(" %d",&choice);
 		if(choice==1)
 			poly_addition(start1, start2);     //1
 		else if(choice==2)
 			poly_multiplication(start1, start2); //1
		else
			printf("Exit!");  //1
	}	
	return 0;
 	
}


