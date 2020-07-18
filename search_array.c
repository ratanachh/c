#include<stdio.h>
#include<conio.h>

int main(){
	
	char name[100][20];
	int age[100];
	int index = 0;
	char ch;
	
	
	do{
		printf("index: %d\n", index);
		printf("input name:");
		fflush(stdin);
		gets(name[index]);
		printf("input age:");
		scanf("%d", &age[index]);
		index++;
		ch = getch();
	}while(ch != 27); //27 = ESC
	
	
//Output
printf("-------------Output----------------");	
printf("\n\nId \t %-20s \t Age\n","Name");
for (int i=0; i < index; i++) {
	printf("%d \t %-20s \t %d\n", i, name[i], age[i]);
}	

// search

int indexarray;
int found = 0;
char sname[1][15];
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
