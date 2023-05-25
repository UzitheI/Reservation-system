#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
	char name[50];
	int bus_num;
	int num_of_seats;
}pd;





void reservation(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);



int main()

{
		system("cls");
	printf("\t\t|           BUS TICKET RERSERVATION SYSTEM           |\n");
    printf("\t\t|                            By K.V.N.AKHIL          |\n");
    printf("\t\t|                            AM.EN.U4EAC19030        |\n");
    printf("\t\t------------------------------------------------------\n");
    printf("\t\t---------------press any key to continue--------------\n");
    printf("\t\t------------------------------------------------------\n");
	getch();
    system("cls");
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    BUS RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Bus");
	printf("\n------------------------");
	printf("\n3>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

void viewdetails(void)
{
	system("cls");
	printf("\nBUS.No\BUS Name\t\t\tDestinations\t\tfare\t\tTime\n");
	printf("\n533101\tBus A\tKerala to karnataka\t\t       Rs.5000\t\t9am");
	printf("\n533102\tBus B\tKarnataka to Maharastra\t\t   Rs.5000\t\t12pm");
	printf("\n533103\tBus C\tKerala to Tamilnadu\t\t       Rs.4500\t\t8am");
	printf("\n533104\tBus D\tTamilnadu to Andhrapradesh\t\tRs.4500\t\t11am");
	printf("\n533105\tBus E\tAndhrapradesh to telangana\t\tRs.5000\t\t7am");
}


void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);

	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Bus<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter bus number:> ");
	start1:
	scanf("%d",&passdetails.bus_num);
	if(passdetails.bus_num>=533101 && passdetails.bus_num<=533105)
	{
		charges=charge(passdetails.bus_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
		printf("==================");
		printf("\n Reservation successful\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float charge(int bus_num,int num_of_seats)
{
		if (bus_num==533101)
	{
		return(5000.0*num_of_seats);
	}
	if (bus_num==533102)
	{
		return(5000.0*num_of_seats);
	}
	if (bus_num==533103)
	{
		return(4500.0*num_of_seats);
	}
	if (bus_num==533104)
	{
		return(4500.0*num_of_seats);
	}
	if (bus_num==533105)
	{
		return(5000.0*num_of_seats);
	}
}

void printticket(char name[],int num_of_seats,int bus_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nBus Number:\t\t%d",bus_num);
	specificbus(bus_num);
	printf("\nCharges:\t\t%.2f",charges);
}

void specificbus(int bus_num)
{

	if (bus_num==533101)
	{
		printf("\nBus:\t\t\tBUS A");
		printf("\nDestination:\t\tKerala to karnataka");
		printf("\nDeparture:\t\t9am ");
	}
	if (bus_num==533102)
	{
		printf("\nBus:\t\t\tBUS B");
		printf("\nDestination:\t\tKarnataka to Maharastra");
		printf("\nDeparture:\t\t12pm");
	}
	if (bus_num==533103)
	{
		printf("\nBus:\t\t\tBUS C");
		printf("\nDestination:\t\tKerala to Tamilnadu");
		printf("\nDeparture:\t\t8am");
	}
	if (bus_num==533104)
	{
		printf("\nBus:\t\t\tBUS D");
		printf("\nDestination:\t\tTamilnadu to Andhrapradesh");
		printf("\nDeparture:\t\t11am ");
	}
	if (bus_num==533105)
	{
		printf("\nBus:\t\t\tBUS C");
		printf("\nDestination:\t\tAndhrapradesh to telangana");
		printf("\nDeparture:\t\t7am");
	}

}