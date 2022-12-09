#include<stdio.h>
struct patient_record{
	int id;
	char name[30];
	char CNIC[30];
	char Phone_number[30];
	char diseaese[30];
	int isAdmitted;
} patient;
void add_patient()
{
	FILE *cfPtr = fopen("patient_record.txt","a");
	if(cfPtr == NULL)
	{
		printf("File could not open\n");
	}
	else
	{
		printf("Enter ID: ");
		scanf("%d",&patient.id);
		fflush(stdin);
		
		printf("Enter name: ");
		gets(patient.name);
	fflush(stdin);	
		printf("Enter CNIC: ");
		gets(patient.CNIC);
	fflush(stdin);
		
		printf("Enter Number: ");
		gets(patient.Phone_number);
		fflush(stdin);
		
		printf("Enter IsAdmitted (YES 1)(No 0): ");
		scanf("%d",&patient.isAdmitted);
		
		fwrite(&patient,sizeof(patient),1,cfPtr);
		fclose(cfPtr);
	}
	
}

void display()
{
	FILE *cfPtr = fopen("patient_record.txt","r");
	if(cfPtr == NULL)
	{
		printf("File could not open\n");
	}
	else
	{
	    	printf("ID\tName\t\tCNIC\t\t\tPhone_number\t\t\tisAdmitted\n\n");
		while(fread(&patient,sizeof(patient),1,cfPtr))
		{
			printf("%d\t%s\t\t%s\t\t\t%s\t\t\t%d\n",patient.id,patient.name,patient.CNIC
			,patient.Phone_number, patient.isAdmitted);
			printf("\n\n");
		}
		fclose(cfPtr);
	}
}
int main()
{
	int choices;
	FILE *cfPtr = fopen("patient_record.txt", "r"); 
     if (cfPtr == NULL) 
    {
       cfPtr = fopen("patient_record.txt", "w");
    }
    fclose(cfPtr);
	
	do
	{
	printf("\t\t\t*******************************************************\n");
	printf("\t\t\t*\t         0.Exit                               *\n");
	printf("\t\t\t*\t         1. Add Patient                       *\n");
	printf("\t\t\t*\t         2.Delete Patient                     *\n");
	printf("\t\t\t*\t         3.Update Patient                     *\n");
	printf("\t\t\t*\t         4.Search Patient                     *\n");
	printf("\t\t\t*\t         5. Display All patients              *\n");
	printf("\t\t\t*******************************************************\n");
	printf("\t\tEnter your choices: ");
	scanf("%d",&choices);
	
	
	
	switch(choices)
	{
		case 1:
			add_patient();
		break;
		case 2:
		
		break;  
		case 3:
		
		break;
		case 4:
			
		break;
		case 5:
		display();
		break;
		default:
		printf("Invalid Option\n");	
	}
	}while(choices != 0);
    
}
