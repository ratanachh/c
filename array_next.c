#include<stdio.h>
#include<conio.h>

char name[100][20];
int age[100];
int index = 0;
char ch;

void Output()
{
	printf("-------------Output----------------");	
	printf("\n\nId \t %-20s \t Age\n","Name");
	for (int i=0; i < index; i++) {
		printf("%d \t %-20s \t %d\n", i, name[i], age[i]);
	}	
}

void Search()
{
	int indexarray;
	int found = 0;
	char sname[15];
	search:
	
	printf("\n 1/Search by index :");
	printf("\n 2/Search by name :");
	
	ch = getch();
	switch(ch){
		case '1':
			printf("\nEnter index to search\n");
			scanf("%d", &indexarray);
			printf("-------------Search----------------");
			for(int a=0; a<index ; a++){
				if(indexarray == a){
					printf("\n\nId \t %20s \t Age\n","Name");
					printf("%d \t %20s \t %d\n", a, name[a], age[a]);
					found = 1;
				}
			}
			if(found == 0){
				printf("\nSearch index not found!!!");
				goto search;
			}
	
		break;
		case '2':
			printf("\nEnter name to search\n");
			fflush(stdin);
			gets(sname);
			printf("-------------Search----------------");
			for(int a=0; a<index ; a++){
				if(strcmp(name[a], sname) == 0){  
					printf("\n\nId \t %20s \t Age\n","Name");
					printf("%d \t %20s \t %d\n", a, name[a], age[a]);
					found = 1;
				}
			}
			if(found == 0){
				printf("\nSearch name not found!!!");
				goto search;
			}
		break;
		default :
			printf("\nInvalid choice !!");
		 
	}
}

void Input()
{
	printf("index: %d\n", index);
	printf("input name:");
	fflush(stdin);
	gets(name[index]);
	printf("input age:");
	scanf("%d", &age[index]);
	index++;
	ch = getch();
}

// Sort
void Sort()
{
	// Sort by age
	/*
	for(int j = 0; j< index; j++){
		for(int i=0; i<index; i++) {
			if (age[j] <= age[i]) { // <= ASC , >= Desc
				int tmp_a = age[j];
				age[j] = age[i];
				age[i] = tmp_a;
				
				char tmp[20];
				strcpy(tmp, name[j]);
				strcpy(name[j], name[i]);
				strcpy(name[i], tmp);
			}
		}
	}*/
	
	// Sort by Name
	for(int j = 0; j< index; j++){
		for(int i=0; i<index; i++) {
			if (strcmp(name[j], name[i]) <= 0 ) {
				int tmp_a = age[j];
				age[j] = age[i];
				age[i] = tmp_a;
				
				char tmp[20];
				strcpy(tmp, name[j]);
				strcpy(name[j], name[i]);
				strcpy(name[i], tmp);
			}
		}
	}
}

// Delete
void Delete()
{
	int in = 0;
	
	printf("Input index to delete: ");
	scanf("%d", &in);
	
	for(int i= in; i< index -1; i++){
		age[i] = age[i+1];
		strcpy(name[i], name[i+1]);
	}
	index = index - 1;
	
	
}


// Update to update function

int main(){
	
	do{
		//Input
		Input();
	}while(ch != 27); //27 = ESC
	
//Output
Output();

// search
//Search();

//Sort
//Sort();

//Delete
Delete();

//Output
//Output();



//	update
//	int up_ind = 1;
//	for (int j= 0; j<index; j++) {
//		if (j == up_ind) {
//			printf("input age:");
//			scanf("%d", &age[j]);
//			break;
//		}
//	}
//	
//	printf("\n\nName\tAge\n");
//	for (int i=0; i < index; i++) {
//		printf("%s\t%d\n", name[i], age[i]);
//	}
	
	getch();
	return 0;
}
