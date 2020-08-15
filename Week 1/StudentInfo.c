#include <stdio.h>
struct student {
	char Name[50];
        char rollno[15];
        int entry,m1;
	float avg;
	char grade;

} s[10];

int main() {
    int i;
    printf("Enter information of students:\n");
	
	for (i = 0; i < 3; ++i) {
        s[i].entry = i + 1;
        printf("\nFor entry%d,\n", s[i].entry);
        printf("Enter name: ");
        scanf("%s", s[i].Name);
	printf("Enter rollno: ");
        scanf("%s", s[i].rollno);
        printf("Enter marks: ");
        scanf("%d", &s[i].m1);
    }
	printf("Displaying Information:\n\n");


    	for (i = 0; i < 3; ++i) {
        	printf("\nentry: %d\n", i + 1);
  		printf("Roll number: ");
		puts(s[i].rollno);
        	printf("Name: ");
       	 	puts(s[i].Name);
        	printf("Marks: %d", s[i].m1);
        	printf("\n");
    }
    return 0;
}