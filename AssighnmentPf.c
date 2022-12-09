#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct PatientRecord{
	char Id[10];
	char Name[20];
	char CNIC[15];
	char PhoneNumber[15];
	char Disease[20];
	char isAdmitted[5];
} Patients;
int enterChoice(){
	int Choice=0;
	printf("\t\t\t\t-------------------------------------------------------------\n"
			"\t\t\t\t\t\t1. Add Patient Record.\n"
			"\t\t\t\t\t\t2. Delete Patient Record.\n"
			"\t\t\t\t\t\t3. Update Patient Record.\n"
			"\t\t\t\t\t\t4. Search Patient Record.\n"
			"\t\t\t\t\t\t5. Display All Patient Records.\n"
			"\t\t\t\t\t\t6. Exit the Program.\n"
			"\t\t\t\t--------------------------------------------------------------\n");
	printf("\t\t\t\t\t\tEnter your Choice : ");
	scanf("%d",&Choice);
	return Choice;
}
void AddPatient(){
	char temp[20];
	FILE *check;
	do
	{
		printf("Enter Id : ");
		fflush(stdin);
		gets(temp);
	} while (strlen(temp) < 1);
	check = fopen("Patients_Record.txt", "r");
	while (fread(&Patients, sizeof(Patients), 1, check)){
		if (strcmp(temp, Patients.Id) == 0){
			printf("ID already exixts!");
			return;
		}
	}
	fclose(check);
	strcpy(Patients.Id, temp);
	do{
		printf("Enter Name: ");
		gets(Patients.Name);
	}while (strlen(Patients.Name) < 1);
	do{
		printf("Enter CNIC : ");
		gets(Patients.CNIC);
	}while (strlen(Patients.CNIC) < 1);
	do{
		printf("Enter Phone Number: ");
		gets(Patients.PhoneNumber);
	}while (strlen(Patients.PhoneNumber) < 1);
	do{
		printf("Enter Disease: ");
		gets(Patients.Disease);
	}while (strlen(Patients.Disease) < 1);
	int x;
	do{
		printf("Was patient atmitted before or not(1 for 'yes' & 0 for 'no'): ");
		scanf("%d", &x);
	}while (x > 1 || x < 0);
	if (x == 1){
		strcpy(Patients.isAdmitted, "Yes");
	}else{
		strcpy(Patients.isAdmitted, "No");
	}
	FILE *fptr;
	fptr = fopen("Patients_Record.txt", "a");
	fwrite(&Patients, sizeof(Patients), 1, fptr);
	fclose(fptr);
	enterChoice();
}
void DeletePatientRecord(){
	FILE *ptr = fopen("Patients_Record.txt", "r+");
	int account = 0;
	struct PatientRecord Delete = {"0", "0", "0", "0", "0", "0"};
	printf("Enter Record Number: ");
	scanf("%d", &account);
	fflush(stdin);
	fseek(ptr, (account - 1) * sizeof(struct PatientRecord), SEEK_SET);
	fwrite(&Delete, sizeof(struct PatientRecord), 1, ptr);
	fclose(ptr);
	printf("Record deleted successfully.\n");
	enterChoice();
}
void SearchPatient(){
	char temp[20];
	FILE *check;
	do{
		fflush(stdin);
		printf("\nEnter the Patient Id to Search: ");
		gets(temp);
	}while (strlen(temp) < 1);
	check = fopen("Patients_Record.txt", "r");
	int ret = 1;
	while (fread(&Patients, sizeof(Patients), 1, check))
	{
		if (strcmp(temp, Patients.Id) == 0)
		{
			printf("\n\nID exixts: \n");
			printf("\n\nID: %s\nName: %s\nCNIC: %s\nPhone Number: %s\nDisease: %s\nStatus:%s\n\n", Patients.Id,Patients.Name, Patients.CNIC, Patients.PhoneNumber,Patients.Disease, Patients.isAdmitted);
			ret = 0;
			break;
		}
	}
	fclose(check);
	if (ret == 1){
		return;
	}
}
void UpdatePatientRecord(){
	FILE *ptr = fopen("Patients_Record.txt", "r+");
	int account = 0;
	struct PatientRecord s;
	printf("Enter Record Number: ");
	scanf("%d", &account);
	fflush(stdin);
	printf("Enter the Patient Name: ");
	gets(s.Name);
	printf("Enter Id: ");
	gets(s.Id);
	printf("Enter the Patient CNIC : ");
	gets(s.CNIC);
	printf("Enter the Patient Phone Number: ");
	gets(s.PhoneNumber);
	printf("Enter the Patient Disease: ");
	gets(s.Disease);
	int x;
	printf("Was patient atmitted before or not(1 for 'yes' & 0 for 'no'): ");
	scanf("%d", &x);
	if (x == 1){
		strcpy(s.isAdmitted, "yes");
	}else{
		strcpy(s.isAdmitted, "no");
	}
	fseek(ptr, (account - 1) * sizeof(struct PatientRecord), SEEK_SET);
	fwrite(&s, sizeof(struct PatientRecord), 1, ptr);
	fclose(ptr);
	printf("Record updated successfully.\n");
	enterChoice();
}
void DisplayAllPatients(void){
	FILE *d;
	d = fopen("Patients_Record.txt", "r");
	while (fread(&Patients, sizeof(Patients), 1, d))
	{
		if (strcmp(Patients.Id, "0") != 0)
		{
			printf("\n\nID: %s\nName: %s\nCNIC: %s\nPhone Number: %s\nDisease: %s\nStatus:%s\n\n", Patients.Id, Patients.Name, Patients.CNIC, Patients.PhoneNumber, Patients.Disease, Patients.isAdmitted);
		}
	}
	enterChoice();
}
int main(){
	FILE *PatientPtr=NULL;
	if ((PatientPtr= fopen("Patient_Record.txt", "w+")) == NULL){
        puts("File could not be opened.");
    }else{ 
		int MenuChoice=0;
		while ((MenuChoice = enterChoice())!=6)
		{
			switch (MenuChoice)
			{
				case 1:
					AddPatient();
				break;
				case 2:
					DeletePatientRecord();
				break;
				case 3:
					UpdatePatientRecord();
				break;
				case 4:
					SearchPatient();
				break;
				case 5:
					DisplayAllPatients();
				break;	
				default:
					printf("%s","Invalid Prompt.\n");
				break;
			}
		}
	}
}
