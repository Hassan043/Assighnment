#include<stdio.h>
#include <string.h>
struct PatientRecord
{
	char Id[10];
	char Name[30];
	char CNIC[16];
	char PhoneNumber[13];
	char Disease[30];
	int isAdmitted;
} Patient;
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
	FILE *AddPatientPtr=NULL;
	if ((AddPatientPtr=fopen("Patient_Record.txt","a"))==NULL){
		printf("%s","File Could Not Be Openened.");
	}else{
        // fprintf(AddPatientPtr,"%-10s%-20s%-20s%-20s%20s","ID","Name","CNIC","Phone Number","Disease\n");
		char endoffile;
		do
		{
			int Flag=0;
			printf("Enter Id : ");
			scanf("%s",&Patient.Id);
			if (Patient.Id>='65' && Patient.Id<='90' && Patient.Id>='97' && Patient.Id<='122')
			{
				Flag=1;
			}
			while (Flag==1)
			{
				printf("Enter Id : ");
				scanf("%s",&Patient.Id);
			}
			fflush(stdin);
			printf("Enter Name : ");
			scanf("%s",&Patient.Name);
			fflush(stdin);
			printf("Enter CNIC : ");
			scanf("%s",&Patient.CNIC);
			fflush(stdin);
			printf("Enter Phone Number : ");
			scanf("%s",&Patient.PhoneNumber);
			fflush(stdin);
			printf("Enter Disease : ");
			scanf("%s",&Patient.Disease);
			fflush(stdin);
			printf("Enter isAdmitted (1 --> Yes)(2 -->No) : ");
			scanf("%d",&Patient.isAdmitted);
			fflush(stdin);
			fprintf(AddPatientPtr,"%-10s%-20s%-20s%-20s%20s\n",Patient.Id,Patient.Name,Patient.CNIC,Patient.PhoneNumber,Patient.Disease);
			printf("\t\t\t\t-----------------------------------------------------------------------\n"
				   "\t\t\t\t\t\tEnter any Chrachter to Enter More Data. (or)\n"
				   "\t\t\t\tEnter EOF(Ctrl+z -->Windows / Ctrl+d -->macOS/Linux) to end Input Data.\n"
				   "\t\t\t\t-----------------------------------------------------------------------\n");
			printf("Choice : ");
			scanf("%c",&endoffile);
		} while (!feof(stdin));
	}
	fclose(AddPatientPtr);
}
// void DisplayAllPatients(){
	// FILE *DisplayAllPatientsPtr=NULL;
	// if ((DisplayAllPatientsPtr=fopen("Patient_Record.txt","r+"))==NULL)
	// {
		// printf("File could not be opened.");
	// }else{
		// printf("%-10s%-20s%-20s%-20s%20s","ID","Name","CNIC","Phone Number","Disease\n");
		// fseek(DisplayAllPatientsPtr,(Patient.Id-1)*sizeof(struct PatientRecord),SEEK_END);
		// fscanf(DisplayAllPatientsPtr,"%-10d%-20s%-20llu%-20llu%20s",Patient.Id,Patient.Name,Patient.CNIC,Patient.PhoneNumber,Patient.Disease);
		// while (!feof(DisplayAllPatientsPtr))
		// {
		// 	size_t result=fread(&Patient,sizeof(struct PatientRecord),1,DisplayAllPatientsPtr);
		// 	if (result!=0 && Patient.Id!=0)
		// 	{
		// 		printf("%-10d%-20s%-20llu%-20llu%20s\n",Patient.Id,Patient.Name,Patient.CNIC,Patient.PhoneNumber,Patient.Disease);
		// 	}
			
		// }
		
	// }
// }
// void UpdatePatientRecord(){
// 	FILE *UpdatePatientRecordPtr=NULL;
// 	if ((UpdatePatientRecordPtr=fopen("Patient_Record.txt","r+"))==NULL){
// 		printf("%s","File could not be opened.");
// 	}else{
// 		printf("Enter The ID of the Patient to Update : ");
// 		char NewName[30];
// 		unsigned long long int NewCNIC;
// 		unsigned long long int NewPhoneNumber;
// 		char NewDisease[30];
// 		int Update=0;
// 		scanf("%d",&Update);
// 		fseek(UpdatePatientRecordPtr,(Update-1)*sizeof(struct PatientRecord),SEEK_SET);
// 		struct PatientRecord Patient={0,"",0,0,"",0};
// 		fread(&Patient,sizeof(struct PatientRecord),1,UpdatePatientRecordPtr);
// 		if (Update==Patient.Id)
// 		{
// 			printf("%-10s%-20s%-20s%-20s%20s","ID","Name","CNIC","Phone Number","Disease\n");
// 			printf("%-10d%-20s%-20llu%-20llu%20s\n",Patient.Id,Patient.Name,Patient.CNIC,Patient.PhoneNumber,Patient.Disease);
// 			printf("\n\t\t\t\tPress 1 to Update Name : \n"
// 			"\t\t\t\tPress 2 to Update CNIC : \n"
// 			"\t\t\t\tPress 3 to Update Phone Number : \n"
// 			"\t\t\t\tPress 4 to Update Disease Name : \n");
// 			printf("Enter New Name : ");
// 			scanf("%s",&NewName);
// 			printf("Enter New CNIC : ");
// 			scanf("%llu",&NewCNIC);
// 			printf("Enter New Phone Number ; ");
// 			scanf("%llu",&NewPhoneNumber);
// 			printf("Enter New Disease : ");
// 			scanf("%s",&NewDisease);
// 		}else{
// 			printf("Id #%d has no information.\n",Update);
// 		}
// 		fclose(UpdatePatientRecordPtr);	
// 	}
// }
void DeletePatientRecord(){
    FILE *DeleteRecordPtr;
    struct PatientRecord Patient;
    DeleteRecordPtr = fopen("Patient_Record.txt", "r");
    printf("\nEnter the ID of The Patient : ");
    char id[20];
    scanf("%s", id);
    FILE *CopyPtr;
    CopyPtr = fopen("New_Record.txt", "a");
    if (DeleteRecordPtr == NULL){
		printf("\nFile could not be Opened.");
    }else{
        	while (fread(&Patient, sizeof(struct PatientRecord), 1, DeleteRecordPtr)){
            	if (strcmp(Patient.Id,id)!=0){
                	fwrite(&Patient, sizeof(struct PatientRecord), 1, CopyPtr);
        		}
			}
		}
    fclose(CopyPtr);
    fclose(DeleteRecordPtr);
    printf("\n\nPATIENT RECORD DELETED SUCCESFULLY\n");
    remove("Patient_Record.txt");
    rename("New_Record.txt", "Patient_Record.txt");

    printf("\n\n----------------------------------------------------\n\n");
}
void SearchPatient(){

}
int main(){
	FILE *PatientPtr=NULL;
	if ((PatientPtr = fopen("Patient_Record.txt", "w+")) == NULL){
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
				case 3:
					// UpdatePatientRecord();
				break;
				case 4:
					// SearchPatient();
				case 5:
					// DisplayAllPatients();
				break;	
				default:
					printf("%s","Invalid Prompt.\n");
				break;
			}
		}
	}
}