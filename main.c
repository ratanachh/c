#include<conio.h>
#include<stdio.h>
#include<string.h>

void SetupMenu();
void SetupMenuHeader();

void AddBooking();
void UpdateBooking();
void SearchBooking();
void DeleteBooking();
void Booking();
void BookingHeader();

void AddEmployee();
void UpdateEmployee();
void SearchEmployee();
void DeleteEmployee();
void Employees();
void EmployeeHeader();

void App();

int ticketIdList[] = {};
int employeeIdList[] = {};
char destinationList[][25] = {};
char leaveDateList[][2][15] = {};

int ticketId;
int employeeId;
char destination[25];
char leaveDate[2][15];

int main()
{
	App();
	getch();
	return 0;
}

void App()
{
	SetupMenuHeader();
	SetupMenu();
}

void SetupMenuHeader()
{
	const char menu[][25] = {
		"1/Booking",
		"2/Employees",
		"3/Booking Information"		
	};

	int length = sizeof(menu) / sizeof(menu[0]);
	for(int index = 0; index < length; index++){
		printf("%s\n", menu[index]);
	}
	printf("Press number[1-%d]: ", length);
}

void SetupMenu()
{
	char key = getch();
	
	switch(key) {
		case '1': 
			AddBooking();
			break;
		case '2': 
			printf("Press %c!", key);
			break;
		case '3': 
			printf("Press %c!", key);
			break;
		default: printf("Invalid choice!"); break;
	}
}

void AddBooking()
{
	int lastIndex = sizeof(ticketIdList) / sizeof(ticketId);
	
	printf("input employee id: ");
	scanf("%d", &employeeId);
	employeeIdList[lastIndex] = employeeId;

	printf("input ticket id: ");
	scanf("%d", &ticketId);
	ticketIdList[lastIndex] = ticketId;
	
	printf("input destination: ");
	gets(destination);
	strcpy(destinationList[lastIndex], destination);
	
	printf("input leave date: ");
	gets(leaveDate[0]);
	printf("input leave time: ");
	gets(leaveDate[1]);

	memcpy(leaveDateList[lastIndex], leaveDate, sizeof(leaveDate));	
}
