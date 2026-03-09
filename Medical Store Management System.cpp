/*--------------------------Header Files---------------------------*/

#include<stdio.h>		//standard input/output
#include<conio.h>		//console input/output
#include<string.h>		//contains inbuilt functions to handle strings
#include<ctype.h>		//contains inbuilt functions to handle characters
#include<stdlib.h>		// For exit() function

/*--------------------------Structures---------------------------*/

typedef struct Medicine
{
	int ID,Price,Quantity;
	char Medicne_Name[100],Company[100],Mfg_Date[20],Exp_Date[20],Info[5000];
}Medi;

/*--------------------------Array of Structure's global declaration---------------------------*/

Medi M[100];		//Medical Store has the capacity to store 100 Medicines at most

/*--------------------------Function declaration---------------------------*/

void Welcome(void);
void Purchase_Medicine(int);
void Enter_Info_About_Medicine(int);
void Stock_Of_Medicine(int);
void Know_Info_About_Medicine(int);
void Add_Medicine_in_Store(int,Medi *);
void Delete_Medicine_from_Store(int);
void Change_Medicine_Details(int);
void printline(void);

/*--------------------------Main Function---------------------------*/

int main()
{
	//Variables
	int loop_counter, choice, number=0, ask_to_continue;
	
	// Welcome message
	Welcome();
	
	// Initialising all all array members
	for(loop_counter=0; loop_counter<100;loop_counter++)
	{
		M[loop_counter].ID=0;
		M[loop_counter].Price=0;
		M[loop_counter].Quantity=0;
		strcpy(M[loop_counter].Mfg_Date,"");
		strcpy(M[loop_counter].Exp_Date,"");
		strcpy(M[loop_counter].Medicne_Name,"");
		strcpy(M[loop_counter].Company,"");
		strcpy(M[loop_counter].Info,"");
	}
	
	//1st Medicine in the store
	M[0].ID=1;
	M[0].Price=200;
	M[0].Quantity=50;
	strcpy(M[0].Mfg_Date,"10/05/2021");
	strcpy(M[0].Exp_Date,"10/05/2023");
	strcpy(M[0].Medicne_Name,"Paracetamol");
	strcpy(M[0].Company,"lpca Labs");
	strcpy(M[0].Info,"Effective against fever");
	
	//do...while loop
	do
	{
		// Printing Menu
		printf("\n\n\t\t***List of operations***\n");
		printf("\n1. Purchase Medicine\n2. Enter Information about a Medicine\n3. Stock of Medicine in Store\n4. Medicine Information\n5. Add Medicine\n6. Delete a Medicine\n7. Change of Medicine details\n8. Exit\n\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		
		//Switch...case
		switch(choice)
		{
			case 1:
				Purchase_Medicine(number+1);// number + 1 is taken as an arguement and it will be used for searching medicine
				break;
			case 2:
				Enter_Info_About_Medicine(number+1);
				break;
			case 3:
				Stock_Of_Medicine(number+1);
				break;
			case 4:
				Know_Info_About_Medicine(number+1);
				break;
			case 5:
				number++;
				Add_Medicine_in_Store(number,M);// number and array of structures
				break;
			case 6:
				Delete_Medicine_from_Store(number+1);
				
				break;
			case 7:
				Change_Medicine_Details(number+1);
				break;
			case 8:
				exit(0);
			default:
				printf("\nInvalid choice\n");
		}
		
		//Asking from user for re-run the loop
		printf("\nTo perform these operations Enter 1 else any other number : ");
    	scanf("%d",&ask_to_continue);
    	
    	printline();	//for seperating different operations
    	printline();
	}while(ask_to_continue==1);
	
	return 0;
}


/*-------------------------------------------------------------------------*/
/*------------              Function definitions            ---------------*/
/*-------------------------------------------------------------------------*/


/*------------------------------Welcome---------------------------------*/
void Welcome()
{
	printf("\t\t      __ __   ___  __  __           __ ___  __  ___   __           __        __   __   __       __      ___      __       __  ___  __ \n");
	printf("\t\t|\\/| |_  | \\   |  |   |__| |       |__  |  |  | |__| |_      |\\/| |__| |\\ | |__| | _  |_  |\\/| |_  |\\ |  |      |__  \\ / |__   |  |_  |\\/|\n");
	printf("\t\t|  | |__ |__| _|_ |__ |  | |__      __| |  |__| |  \\ |__     |  | |  | | \\| |  | |__| |__ |  | |__ | \\|  |       __|  |   __|  |  |__ |  |\n\n");
	
	printline();
	printline();
}


/*--------------------------Purchase_Medicine---------------------------*/
void Purchase_Medicine(int num)
{
	// Local Variable declaration
	int id,check,i,quantity,flag=0;// flag variable for checking that the medicine is in the array
  	char name[100];
  	
  	// Asking from user to enter his /her choice for the way to find medicine
  	printf("\nEnter 1 if you know ID else any other number to enter Name of Medicine : ");
  	scanf("%d",&check);
  	
  	if(check==1)// User wants to find the medicine by medicine ID
  	{
  		//Asking for medicine ID
  		printf("\nEnter Id to purchase Medicine : ");
		fflush(stdin);
		scanf("%d",&id);
		
		//Searching for medicine in the array of medicines
		for(i=0;i<num;i++)
		{
		    if(M[i].ID==id)//Medicine found
		    {
		    	flag=1;//if medicine found in the array then flag becomes 1 otherwise 0
		    	
		    	int c; // Asking the user's choice of purchasing medicine
		    	
		    	// Printing medicine details
			    printf("\n\n# These are the details of Medicine ->\n");
			    printf("\nName : %s\nPrice : %d\nAvailable Quantity : %d\nCompany : %s\nMfg Date : %s\nExp Date : %s\n",M[i].Medicne_Name,M[i].Price,M[i].Quantity,M[i].Company,M[i].Mfg_Date,M[i].Exp_Date);
			    
			    //Medicine info check and print
			    if(strcmp(M[i].Info,"")==0)
			    	printf("Medicine Review/Info : Not Available\n\n");
			    else
			    	printf("Medicine Review/Info : %s\n\n",M[i].Info);
		    	
		    	//Asking the user to purchase
		    	printf("Do you want to purchase %s \nIf Yes Enter 1 otherwise enter any other number : ",M[i].Medicne_Name);
		    	scanf("%d",&c);
		    	
		    	// Wants to purchase medicine
		    	while(c==1)
		    	{
		    		//Asking form the user to enter quantity
		    		printf("\nEnter Quantity to Purchase : ");
		    		scanf("%d",&quantity);
		    		
		    		//Checking for available quantity
		    		if(M[i].Quantity>=quantity)
		    		{
		    			printf("\nTotal Price to be paid : %d\n",quantity*M[i].Price);
		    			break;
					}
		    		else
			    		printf("\nPlease Enter quantity below Available Quantity\n");
				}
				
				// After completion of the purchasing for loop ends (Purchased or not)
		    	break;
			}
		}
		
		//Medicine not found
		if(flag==0)
			printf("\nEntered Id Not Found\n");
	}
	else // User wants to find the medicine by medicine Name
	{
		printf("\nEnter Name to search and Purchase : ");

		//Getting the name of medicine from the user
		fflush(stdin);
		gets(name);
		
		//Searching for the medicine in the whole array by medicine name
		for(i=0;i<num;i++)
		{
			if(strcmp(M[i].Medicne_Name,name)==0)
			{
				flag=1; // if medicine found in the array then flag becomes 1 otherwise 0
				
				int c; // Asking the user's choice of purchasing medicine
				
				// Printing medicine details
			    printf("\n\n# These are the details of Medicine ->\n");
			    printf("\nName : %s\nPrice : %d\nAvailable Quantity : %d\nCompany : %s\nMfg Date : %s\nExp Date : %s\n",M[i].Medicne_Name,M[i].Price,M[i].Quantity,M[i].Company,M[i].Mfg_Date,M[i].Exp_Date);
			    
			    //Medicine info check and print
			    if(strcmp(M[i].Info,"")==0)
			    	printf("Medicine Review/Info : Not Available\n\n");
			    else
			    	printf("Medicine Review/Info : %s\n\n",M[i].Info);
			    	
			    //Asking the user to purchase
		    	printf("Do you want to purchase %s \nIf Yes Enter 1 else any other number : ",M[i].Medicne_Name);
		    	scanf("%d",&c);
		    	
		    	while(c==1)
		    	{
		    		//Asking form the user to enter quantity
		    		printf("\nEnter Quantity to Purchase : ");
		    		scanf("%d",&quantity);
		    		
		    		//Checking for available quantity
		    		if(M[i].Quantity>=quantity)
		    		{
		    			printf("\nTotal Price to be paid : %d\n",quantity*M[i].Price);
		    			c==0;
					}
		    		else
			    		printf("\nPlease Enter quantity below Available Quantity\n");
				}
				
				// After completion of the purchasing for loop ends (Purchased or not)
		    	break;
			}
		}
		//Medicine not found
		if(flag==0)
			printf("Entered Medicine Name Not Found\n");
	}
}


/*--------------------------Enter_Info_About_Medicine---------------------------*/
void Enter_Info_About_Medicine(int num)
{
	// Local Variable declaration
	int i,flag=0,c;//flag is only for checking whether the medicine found or not
	char name[100],info[100];
	
	printf("\nEnter Name of the medicine you want to Review or include Info : ");
	fflush(stdin);
	gets(name);// Taking Medicine name from the user
	
	//Searching for medicine in the array of medicines
	for(i=0;i<num;i++)
	{
		// Medicine name comparision
		if(strcmp(M[i].Medicne_Name,name)==0)
		{
			flag=1; // if medicine found in the array then flag becomes 1 otherwise 0
				
			// Printing medicine details
			printf("\n\n# These are the details of Medicine ->\n");
			printf("\nName : %s\nPrice : %d\nAvailable Quantity : %d\nCompany : %s\nMfg Date : %s\nExp Date : %s\n",M[i].Medicne_Name,M[i].Price,M[i].Quantity,M[i].Company,M[i].Mfg_Date,M[i].Exp_Date);
			    
			//Checking for Info/ Review already available or not
			if(strcmp(M[i].Info,"")!=0)//Review already available
		    {
			    printf("\nReview Already Available!\nIf you want to Add a Review Enter 1 else Any other number : ");
			    scanf("%d",&c);//Asking for adding review 1-> yes ,any other-> no
		    }
		    else//no Review done yet, 1st review for this medicine
		    {
			    printf("\nEnter review(less than 100 Characters) : ");
			    fflush(stdin);
			    gets(M[i].Info);//get 1st info/ review about the medicine
		    }
		    
		    // User want to add more with the existing reviews
		    if(c==1)
		    {
			     printf("\nEnter review(less than 100 Characters) :");
			     fflush(stdin);
			     gets(info);// getting new info/ review
			     
			     //Adding new review with the existing one
			     strcat(M[i].Info,"; ");
			     strcat(M[i].Info,info);
		    }
		}
	}
	
	//Medicine not found
	if(flag==0)
		printf("\nEntered Name Not Found\n");
}


/*--------------------------Stock_Of_Medicine---------------------------*/
void Stock_Of_Medicine(int num)
{
	// Local Variable declaration
	int i, mp=0, count=0;	//mp is for checking any medicine present in the store or not & count is for medical count
	
	//Checking for medicine availability in the store
	if(num!=0)	//Medicine available in the store
	{
		printf("\n# All Available Items are->\n");
		
		//Printing details of all available medicines
		for(i=0;i<num;i++)
		{
			if(M[i].ID!=0)//ID has some positive value
			{
				mp=1;
				printf("\n$ Medicine %d : \n",++count);
				// Printing medicine details
				printf("\nName : %s\nPrice : %d\nAvailable Quantity : %d\nCompany : %s\nMfg Date : %s\nExp Date : %s\n",M[i].Medicne_Name,M[i].Price,M[i].Quantity,M[i].Company,M[i].Mfg_Date,M[i].Exp_Date);
				
				//Medicine info check and print
				if(strcmp(M[i].Info,"")==0)
					printf("Medicine Review/Info : Not Available\n\n\n");
				else
				    printf("Medicine Review/Info : %s\n\n\n",M[i].Info);
			}
		}
	}
	if(mp==0)	//Medicine not available in the store
		printf("\nNo Items or Medicines Available\n");
}


/*--------------------------Know_Info_About_Medicine---------------------------*/
void Know_Info_About_Medicine(int num)
{
	// Local Variable declaration
	int i,flag=0;
	char name[100];
	
	// Asking for medicine name from user
	printf("\nEnter Name of the medicine you want to see Review and Info : ");
	fflush(stdin);
	gets(name);// getting medicine name
	
	//Searching for medicine in the medicine array
	for(i=0;i<num;i++)
	{
		if(strcmp(M[i].Medicne_Name,name)==0)
		{
			flag=1; // if medicine found in the array then flag becomes 1 otherwise 0
			
			// Printing medicine details
			printf("\n\n\t# These are the Medicine details ->\n");
			printf("\nName : %s\nPrice : %d\nAvailable Quantity : %d\nCompany : %s\nMfg Date : %s\nExp Date : %s\n",M[i].Medicne_Name,M[i].Price,M[i].Quantity,M[i].Company,M[i].Mfg_Date,M[i].Exp_Date);
			    
			//Medicine info check and print
			if(strcmp(M[i].Info,"")==0)
				printf("Medicine Review/Info : Not Available\n\n");
			else
			    printf("Medicine Review/Info : %s\n\n",M[i].Info);
		}
	}
	//Medicine not found
	if(flag==0)
 		printf("\nEntered Name Not Found\n\n");
}


/*--------------------------Add_Medicine_in_Store---------------------------*/
void Add_Medicine_in_Store(int num,Medi M[])
{
	//Local Variable Declaration
	char name[100];
	//Adding medicine
	printf("\nEnter Medicine Id : ");			// ID
	scanf("%d",&(M[num].ID));
	printf("\nEnter Medicine Name : ");			// Name
	fflush(stdin);
	gets(M[num].Medicne_Name);
	printf("\nEnter Company Name : ");			// Company Name
	fflush(stdin);
	gets(M[num].Company);
	printf("\nEnter Manufactured Date : ");		// Mfg Date
	fflush(stdin);
	gets(M[num].Mfg_Date);
	printf("\nEnter Expiry Date : ");			// Exp Date
	fflush(stdin);
	gets(M[num].Exp_Date);
	printf("\nEnter Quantity : ");				// Quantity
	scanf("%d",&(M[num].Quantity));
	printf("\nEnter Price : ");					// Price
	scanf("%d",&(M[num].Price));
	strcpy(M[num].Info,"");						// Empty string for info
	
	printf("\nMedicine with id %d Added Successfully\n",M[num].ID);	// Success message
}


/*--------------------------Delete_Medicine_from_Store---------------------------*/
void Delete_Medicine_from_Store(int num)
{
	// Local Variable Declaration
	int id,i,flag=0;
	//Asking from the user to enter thre medicine name
	printf("\nEnter ID to be deleted : ");
	scanf("%d",&id);
	for(i=0;i<num;i++)
	{
		if(M[i].ID==id)
		{
		    flag=1;			// Medicine found
			M[i].ID=0;
		    M[i].Price=0;
		    M[i].Quantity=0;
		    strcpy(M[i].Medicne_Name,"");
		    strcpy(M[i].Company,"");
		    strcpy(M[i].Mfg_Date,"");
		    strcpy(M[i].Exp_Date,"");
		    strcpy(M[i].Info,"");
		    break;
	   }
	}
	if(flag==1)
		printf("\nMedicine with %d is Deleted Successfully\n",id);
	else
		printf("\nMedicine with %d is not present in the store\n",id);
}


/*----------------Change_Medicine_Details-----------------*/
void Change_Medicine_Details(int num)
{
	// Local Varible Declaration
	int id, quantity, choice, c, i, mp=0;
	//Asking form the user to enter medicine ID
	printf("\n\nEnter ID to change Details : ");
	scanf("%d",&id);
	for(i=0;i<num;i++)// Traversing through the array of structures(Medicine list)
	{
		// Checking for medicine
		if(M[i].ID==id && M[i].ID!=0)// If ID is 0 then medicine was deleted from the medicine list
		{
			mp=1;// Medicine present
			do // For making several changes
			{
				// Contents
				printf("\n\n\t***Operations you can perform***\n");
				printf("\n1. Change Quantity\n2. Change Price\n3. Change Medicine Name\n4. Change Company\n5. Change Manufaturing Date\n6. Change Expiry Date\n7. Change Info\n8. Exit\n");
			    printf("Enter your choice : ");
				scanf("%d",&choice);
			    //Switch...case
			    switch(choice)
			    {
			    	case 1:		//Changing quantity
			    		int quantity;
				        printf("\nEnter Quantity to be changed : ");
				        scanf("%d",&quantity);
				        M[i].Quantity=quantity;
				        printf("\nQuantity changed Successfully\n");
				        break;
			    	case 2:		//Changing price
			    		int price;
				        printf("\nEnter Price to be changed : ");
				        scanf("%d",&price);
				        M[i].Price=price;
				        printf("\nPrice changed Successfully\n");
				        break;
			    	case 3:		//Changing Medicine name
			    		char name[100];
				        printf("\nEnter Medicine Name to be changed : ");
				        fflush(stdin);
				        gets(name);
				        strcpy(M[i].Medicne_Name,name);
				        printf("\nMedicine Name changed Successfully\n");
				        break;
			    	case 4:		//Changing Company name
			    		char company[100];
				        printf("\nEnter company to be changed : ");
				        fflush(stdin);
				        gets(company);
				        strcpy(M[i].Company,company);
				        printf("\nCompany changed Successfully\n");
				        break;
			    	case 5:		//Changing company name
			    		char mfg[20];
				        printf("\nEnter Manufacturing date to be changed : ");
				        fflush(stdin);
						gets(mfg);
				        strcpy(M[i].Mfg_Date,mfg);
				        printf("\nManufacturing Date changed Successfully\n");
				        break;
			    	case 6:		//Changing manufacturing date
			    		char exp[20];
				        printf("\nEnter Expiry date to be changed : ");
				        fflush(stdin);
						gets(exp);
				        strcpy(M[i].Exp_Date,exp);
				        printf("\nExpiry Date changed Successfully\n");
				        break;
			    	case 7:		//Changing expiry date
			    		char info[100];
				        printf("\nEnter Info to be changed(Less than 100 Characters) : ");
				        fflush(stdin);
				        gets(info);
				        strcpy(M[i].Info,info);
				        printf("\nInfo changed Successfully\n");
				        break;
			    	case 8:		//Changing info
			    		exit(0);
			    	default:	//Invalid choice
			    		printf("\nInvalid Choice.\n");
				}
				printf("\nEnter 1 to Change other Details Else any other number : ");//Asking from the user for changing further (continuation of do...while loop)
			    scanf("%d",&c);
			}while(c==1);
			
			break;// for loop break after making changes in the medicine with particular id 
		}
	}
	if(mp==0)
		printf("\nMedicine not present in the store.\n");
}


/*--------------------------printline----------------------------*/
void printline()
{
	int i;
	for(i=0;i<100;i++)
		printf("__");
	printf("\n");
}
