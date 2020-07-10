#include<conio.h>
#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

#define NOT_FOUND -1
#define MAX_ELEMENT 100

void SetupMenu();
void SetupMenuHeader();

void AddBooking();
int UpdateBooking(int);
int SearchBooking(int);
int DeleteBooking(int);
void Booking();
void BookingList();

void AddEmployee();
void UpdateEmployee();
void SearchEmployee();
void DeleteEmployee();
void Employees();
void EmployeeHeader();

void App();

int ticketIdList[MAX_ELEMENT];
int employeeIdList[MAX_ELEMENT];
char destinationList[MAX_ELEMENT][25];
char leaveDateList[MAX_ELEMENT][2][15];

int ticketId;
int employeeId;
char destination[25];
char leaveDate[2][15];

int recordedLength = 0;

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
			AddBooking();
			BookingList();
			
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

void InputTicket(int index, int update)
{
	printf("index: %d", index);
	if ( update == FALSE) {
		printf("input employee id: ");
		scanf("%d", &employeeId);
		employeeIdList[index] = employeeId;
	
		printf("input ticket id: ");
		scanf("%d", &ticketId);
		ticketIdList[index] = ticketId;
	}
	
	printf("input destination: ");
	fflush(stdin);
	gets(destination);
	strcpy(destinationList[index], destination);
	
	printf("input leave date: ");
	gets(leaveDate[0]);
	printf("input leave time: ");
	gets(leaveDate[1]);

	memcpy(leaveDateList[index], leaveDate, sizeof(leaveDate));	
}

void AddBooking()
{
	InputTicket(recordedLength, FALSE);
	recordedLength++;
}

int UpdateBooking(int ticketId)
{
	int updated = 0;
	for(int index = 0; index < recordedLength; index++) {
		if(ticketIdList[index] == ticketId) {
			InputTicket(index, TRUE);
			updated = 1;
			break;
		}
	}
	return updated;
}

int SearchBooking(int ticketId)
{
	int recordedLength = sizeof(ticketIdList) / sizeof(ticketId);
	
	int found = 0;
	for(int index = 0; index < recordedLength; index++) {
		if(ticketIdList[index] == ticketId) {
			return index;
		}
	}
	
	if (found == FALSE) return NOT_FOUND;
}

int DeleteBooking(int ticketId)
{
	int index = SearchBooking(ticketId);
	if (index == NOT_FOUND) return FALSE;
	
	for(int i = index; i <= recordedLength - 2; i++) {
		
		/*swap ticket id*/
		ticketIdList[i] = ticketIdList[i + 1];
		
		/*swap employee id*/
		employeeIdList[i] = employeeIdList[i + 1];
		
		/*swap destination id*/
		strcpy(destinationList[i], destinationList[i + 1]);
		
		/*swap leaveDate id*/
		memcpy(leaveDateList[i], leaveDateList[i + 1], sizeof(leaveDate));	
		
	}
	--recordedLength;
}

void BookingList()
{
	printf("%-20s%-20s%-20s%-20s\n", "ID", "Destination", "Leave Date", "Leave Time");
	for(int index = 0; index < recordedLength; index++) {
		printf("%-20d%-20s%-20s%-20s\n", ticketIdList[index], destinationList[index], leaveDateList[index][0], leaveDateList[index][1]);
	}
	
}
