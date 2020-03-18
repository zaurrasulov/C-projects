#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)

typedef struct Date{
	int day;
	int month;
	int year;
}Data;

typedef struct Student {
	int ID;
	char name[25];
	char surname[25];
	float Math;
	float Sci;
	float Turk;
	Data bday;
}Student;
Student A;

void Add(Student *A){  
	char c;
	printf("Enter ID: ");
	scanf("%d",&A->ID);
	printf("Enter First Name: ");
	c=getchar();
	gets(A->name);
	printf("Enter Last Name: ");
	gets(A->surname);
	printf("Enter Birthday Date (Day/Month/Year): ");
	scanf("%d/%d/%d",&A->bday.day,&A->bday.month,&A->bday.year);
	printf("Enter Mathematics Grade: ");
	scanf("%f",&A->Math);
	printf("Enter Science Grade: ");
	scanf("%f",&A->Sci);
	printf("Enter Turkish Grade: ");
	scanf("%f",&A->Turk);
	}
	
void Update(Student *A)
{
	char c;
	int choise;
	printf("\nWhich information do you want to update?");
	printf("\n1.ID\n2.First Name\n3.Last name\n4.Birthday\n5.Mathematics Grade\n6.Science Grade\n7.Turkish Grade\n8.All Information\nChoise: ");
	scanf("%d",&choise);
	switch(choise){
		case 1:
			printf("New ID: ");
			scanf("%d",&A->ID);
			break;
		case 2:
			printf("New First Name: ");
			scanf("%s",A->name);
			break;
		case 3:
			printf("New Last Name: ");
			scanf("%s",A->surname);
			break;
		case 4:
			printf("New Birthday Date (Day/Month/Year): ");
			scanf("%d/%d/%d",&A->bday.day,&A->bday.month,&A->bday.year);
			break;
		case 5:
			printf("New Mathematics Grade: ");
			scanf("%f",&A->Math);
			break;
		case 6:
			printf("New Science Grade: ");
			scanf("%f",&A->Sci);
			break;
		case 7:
			printf("New Turkish Gcore: ");
			scanf("%f",&A->Turk);
			break;
		case 8:
			printf("New ID: ");
			scanf("%d",&A->ID);
        	printf("New First Name: ");
            c=getchar();
        	gets(A->name);
        	printf("New Last Name: ");
        	gets(A->surname);
        	printf("New Birthday Date (Day/Month/Year):");
        	scanf("%d/%d/%d",&A->bday.day,&A->bday.month,&A->bday.year);
        	printf("New Nathematics Grade: ");
        	scanf("%f",&A->Math);
        	printf("New Science Grade: ");
        	scanf("%f",&A->Sci);
        	printf("New Turkish Grade: ");
        	scanf("%f",&A->Turk);
        	break;
		default :
			printf("The choise is invalid");
			break;
	}
}

void View(FILE *fp){
	int tell, i;
	fp=fopen("student.bin","rb+");
	if(fp==NULL)
		fp=fopen("student.bin","wb+");
    fseek(fp,0,SEEK_END);
    tell=ftell(fp)/sizeof(Student);
    printf("\nID\t\tFirst Name\tLast Name\tBirthday\tMathematics\tScience         Turkish\n");
	for(i=0;i<tell;i++){
		fseek(fp,i*sizeof(Student),SEEK_SET);
		fread(&A,sizeof(Student),1,fp);
		printf("%d\t%s\t\t%s\t\t%d/%d/%d\t%f\t%f\t%f\n", A.ID, A.name, A.surname, A.bday.day,A.bday.month,A.bday.year, A.Math, A.Sci, A.Turk);
	}
		fclose(fp);
}

int NumberofData(){
	int tell;
	FILE *file;
	file=fopen("student.bin","rb+");
	if(file==NULL)
	    file=fopen("student.bin","wb+");
    fseek(file,0,SEEK_END);
    tell=ftell(file)/sizeof(Student);
    printf("%d students are entered.\n",tell);
    fclose(file);
    return tell;
}

void Menu(){
	printf("========================Menu==========================\n");
	printf("1. Add Student Record\n");
	printf("2. Delete Student Record\n");
	printf("3. Update Student Record\n");
	printf("4. View Student Record\n");
	printf("5. Sort Records by Student Number\n");
	printf("6. Sort Records by Student Name\n");
	printf("7. Sort Records by Mathematics Grade\n");
	printf("8. Sort Records by Science Grade\n");
	printf("9. Sort Records by Turkish Grade\n");
	printf("10. Write sorted records to 'sorted.bin' file\n");
	printf("11. Exit\n");
}

int main(){
	FILE *fp,*fp2;
	int choise1,choise2,choise3,tell,i,j;
	Student A1,*A3,temp;
	tell=NumberofData();
	Student A2[tell];
	A3=(Student *)malloc(tell);
	Menu();
    while(1){
    printf("Enter the choise:");
	scanf("%d",&choise1);
	if (choise1==1){  // Add
	    fp=fopen("student.bin","rb+");
	    if(fp==NULL)
		    fp=fopen("student.bin","wb+");
		Add(&A1);
		fseek(fp,0,SEEK_END);
		fwrite(&A1,sizeof(Student),1,fp);
		fclose(fp);
	}
	else if (choise1==2){  // Delete
		fp=fopen("student.bin","rb+");
	    if(fp==NULL)
		    fp=fopen("student.bin","wb+");
        for(i=0;i<tell;i++){
		    fseek(fp,i*sizeof(Student),SEEK_SET);
		    fread(&A1,sizeof(Student),1,fp);
		    A2[i]=A1;
        }
        fclose(fp);
		printf("Which do you want to delete?\n");
		for(i=0;i<tell;i++){
			printf("%d.%s ",i+1,A2[i].name);
			printf("%s\n",A2[i].surname);
		}
		printf("Enter the choise: ");
		scanf("%d",&choise3);
		tell-=1;
		if(choise3>tell){
			printf("Invalid!");
			break;
		}
		else{
			for(i=choise3-1;i<tell;i++){
			A2[i]=A2[i+1];
		    }
		    fp=fopen("student.bin","wb+");
		    if(fp==NULL)printf("Error!");
		    for(i=0;i<tell;i++){
			    	fseek(fp,i-1*sizeof(Student),SEEK_SET);
			    	fwrite(&A2[i],sizeof(Student),1,fp);
			    }
	    	fclose(fp);
		}
	}
	else if (choise1==3){   // Update
	    fp=fopen("student.bin","rb+");
	    if(fp==NULL)
		    fp=fopen("student.bin","wb+");        
		printf("Which student do you want to update? (Please, Enter the ID only):\n");
		for(i=0;i<tell;i++){
			fseek(fp,i*sizeof(Student),SEEK_SET);
			fread(&A1,sizeof(Student),1,fp);
			printf("%d.%s\n",i+1,A1.name);
		}
		printf("Enter the choise: ");
		scanf("%d",&choise2);
		if(choise2>tell){
			printf("Invalid!");
			break;
		}
		else{
			fseek(fp,(choise2-1)*sizeof(Student),SEEK_SET);
	    	fread(&A1,sizeof(Student),1,fp);
	    	printf("%d",A1.ID);
	    	Update(&A1);
	    	fseek(fp,(choise2-1)*sizeof(Student),SEEK_SET);
	    	fwrite(&A1,sizeof(Student),1,fp);
	    	printf("Successful update!");
	    	fclose(fp);
		}
	}
	else if (choise1==4){  // View
	    View(fp);
    }
    else if(choise1==5){  // Sort by Student number;
        fp=fopen("student.bin","rb+");
	    if(fp==NULL)
		    fp=fopen("student.bin","wb+");
        for(i=0;i<tell;i++){
		    fseek(fp,i*sizeof(Student),SEEK_SET);
		    fread(&A1,sizeof(Student),1,fp);
		    A2[i]=A1;
        }
        printf("1.Descending\n2.Ascending\nYour choise: ");
		scanf("%d",&choise2);
		if(choise2==1){
			for(i=0;i<tell-1;i++){
				for(j=0;j<tell-i-1;j++){
					if(A2[j].ID<A2[j+1].ID){
						temp=A2[j];
						A2[j]=A2[j+1];
						A2[j+1]=temp;
					}
			    }
			}
			printf("Successful Sort!\n");
	    }
	    else if(choise2==2){
	    	for(i=0;i<tell-1;i++){
			 	for(j=0;j<tell-i-1;j++){
					if(A2[j].ID>A2[j+1].ID){
						temp=A2[j];
						A2[j]=A2[j+1];
						A2[j+1]=temp;
					}
			    }
			}
			printf("Successful Sort!\n");
		}
	    else{
	    	printf("Invalid!");
	    	break;
		}
	}
	else if (choise1==6){ // Sort by Name
     	fp=fopen("student.bin","rb+");
	    if(fp==NULL)
		    fp=fopen("student.bin","wb+");
        for(i=0;i<tell;i++){
		    fseek(fp,i*sizeof(Student),SEEK_SET);
		    fread(&A1,sizeof(Student),1,fp);
		    A2[i]=A1;
        }
		for(i=0;i<tell;i++){  
            for(j=i+1;j<tell;j++){
                if(strcmp(A2[i].name,A2[j].name)>0){
                	temp=A2[i];
                	A2[i]=A2[j];
                	A2[j]=temp;
				}
            }
        }
        fclose(fp);
		printf("Succesful Sort!");   
	}
	else if (choise1==7){   // Sort by Math grade;
	    fp=fopen("student.bin","rb+");
	    if(fp==NULL)
		    fp=fopen("student.bin","wb+");
        for(i=0;i<tell;i++){
		    fseek(fp,i*sizeof(Student),SEEK_SET);
		    fread(&A1,sizeof(Student),1,fp);
		    A2[i]=A1;
        }
	    printf("1.Descending\n2.Ascending\nchoise: ");
		scanf("%d",&choise2);
		switch(choise2){
		case 1 :
		    for(i=0;i<tell-1;i++){
			    for(j=0;j<tell-i-1;j++){
				    if(A2[j].Math<A2[j+1].Math){
					    temp=A2[j];
					    A2[j]=A2[j+1];
						A2[j+1]=temp;
				    }
		      	}
		    }
		    printf("Succesful sort!\n");
		    break;
		case 2 :
			for(i=0;i<tell-1;i++){
			    for(j=0;j<tell-i-1;j++){
				    if(A2[j].Math>A2[j+1].Math){
					    temp=A2[j];
					    A2[j]=A2[j+1];
					    A2[j+1]=temp;
				    }
		      	}
		    }
		    printf("Succesful Sort!\n");
		    break;
		default :
			printf("Invalid choise!");
			fclose(fp);
			exit(1);
		}
		fclose(fp);
	}
	else if (choise1==8){   // Sort by Science grade;
	    fp=fopen("student.bin","rb+");
	        if(fp==NULL)
		        fp=fopen("student.bin","wb+");
        for(i=0;i<tell;i++){
		    fseek(fp,i*sizeof(Student),SEEK_SET);
		    fread(&A1,sizeof(Student),1,fp);
		    A2[i]=A1;
        }
	    printf("1.Descending\n2.Ascending\nPlease, choose: ");
		scanf("%d",&choise2);
		switch(choise2){
		case 1 :
		    for(i=0;i<tell-1;i++){
			    for(j=0;j<tell-i-1;j++){
				    if(A2[j].Sci<A2[j+1].Sci){
					    temp=A2[j];
					    A2[j]=A2[j+1];
					    A2[j+1]=temp;
					}
		      	}
			}
		    printf("Successful sort\n");
		    break;
		case 2 :
			for(i=0;i<tell-1;i++){
			    for(j=0;j<tell-i-1;j++){
				    if(A2[j].Sci>A2[j+1].Sci){
					    temp=A2[j];
					    A2[j]=A2[j+1];
					    A2[j+1]=temp;
				    }
		      	}
		    }
		    printf("Successful sort!\n");
		    break;
		default :
			printf("Invalid choise!");
			fclose(fp);
			exit(1);
		}
		fclose(fp);
	}
	else if (choise1==9){  // Sort by Turkish grade;
	    fp=fopen("student.bin","rb+");
	    if(fp==NULL)
			fp=fopen("student.bin","wb+");
        for(i=0;i<tell;i++){
		    fseek(fp,i*sizeof(Student),SEEK_SET);
		    fread(&A1,sizeof(Student),1,fp);
		    A2[i]=A1;
        }
	    printf("1.Descending\n2.Ascending\nPlease, choose: ");
		scanf("%d",&choise2);
		switch(choise2){
		case 1 :
		    for(i=0;i<tell-1;i++){
			    for(j=0;j<tell-i-1;j++){
				    if(A2[j].Turk<A2[j+1].Turk){
					    temp=A2[j];
					    A2[j]=A2[j+1];
					    A2[j+1]=temp;
				    }
		      	}
		    }
		    printf("Successful sort!\n");
		    break;
		case 2 :
			for(i=0;i<tell-1;i++){
			    for(j=0;j<tell-i-1;j++){
				    if(A2[j].Turk>A2[j+1].Turk){
					    temp=A2[j];
					    A2[j]=A2[j+1];
					    A2[j+1]=temp;
				    }
		      	}
		    }
		    printf("Successful sort!\n");
		    break;
		default :
			printf("Invalid choise!");
			fclose(fp);
			exit(1);
		}
		fclose(fp);
	}
	else if (choise1==10){  //sorted bin		
		FILE *fp1;
		fp1=fopen("sorted.bin","wb+");
	    if(fp1==NULL)
			printf("The file is not found!");
        for(i=0;i<tell;i++){
        	printf("%s\n",A2[i].name);
			fseek(fp1,i*sizeof(Student),SEEK_SET);
			fwrite(&A2[i],sizeof(Student),1,fp1);
		}
		printf("To read the data, press 1; to return the menu, press 1.\nPlease, choose:");
		scanf("%d",&choise3);
		if(choise3==1){
			for(i=0;i<tell;i++){
				fseek(fp1,i*sizeof(Student),SEEK_SET);
				fread(&A2[i],sizeof(Student),1,fp1);
				printf("ID:%d ",A2[i].ID);
			    printf("%s ",A2[i].name);
			    printf("%s ",A2[i].surname);
			    printf("%d/%d/%d ",A2[i].bday.day,A2[i].bday.month,A2[i].bday.year);
			    printf("Mathematics:%.2f ",A2[i].Math);
			    printf("Science:%.2f ",A2[i].Sci);
			    printf("Turkish:%.2f ",A2[i].Turk);
			    printf("\n");
			}
			fclose(fp1);
		}
		else{
			printf("Good luck!");
			fclose(fp1);
			exit(1);			
		}
	}
    else if (choise1==11){  // Exit
    	printf("Good luck!");
    	exit(1);
	}
	else{
		printf("Invalid choise! Try again.\n");
		break;
	}
	printf("\n");
	for(i=0;i<100;i++){
		printf("-");
	}
	printf("\n");	
	}
}
