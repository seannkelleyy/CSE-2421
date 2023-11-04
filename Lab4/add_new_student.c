/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
#include <stdio.h> 
#include <string.h>

void AddNewStudent(Node **listHead, char *categoryNames, FILE *file){
	// inital value declarations 
	char studentName[40];
	int studentId;
	float newScore;
	int validId = 0;
	Cat_Grade cat1, cat2, cat3, cat4;
	Data newStudentData;

	// prompts user for student name
	printf("Enter the Students's Name: ");
	scanf(" %39[^\n]", studentName);
	strcpy(newStudentData.student_name, studentName);
	
	// clears input buffer
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }


	// prompts user for student id until they provide one that is valid
	while (validId == 0){
		printf("Enter the Students's ID Number: ");
		scanf("%d", &studentId);
		if (IdIsDuplicate(listHead, studentId) == 1){
			printf("Student ID Number entered was duplicate\n");
		} else {
			validId = 1;
			newStudentData.student_ID = studentId;
		}
	}
	
	// prompts user for each score for each category and sets the values
	printf("Enter first %s score (use -1 if there is no score): ", categoryNames);
	scanf("%f", &newScore);
	cat1.score1 = newScore;

	printf("Enter second %s score (use -1 if there is no score): ", categoryNames);
	scanf("%f", &newScore);
	cat1.score2 = newScore;

	printf("Enter third %s score (use -1 if there is no score): ", categoryNames);
	scanf("%f", &newScore);
	cat1.score3 = newScore;

	printf("Enter first %s score (use -1 if there is no score): ", (char*)categoryNames+15);
	scanf("%f", &newScore);
	cat2.score1 = newScore;

	printf("Enter second %s score (use -1 if there is no score): ", (char*)categoryNames+15);
	scanf("%f", &newScore);
	cat2.score2 = newScore;

	printf("Enter third %s score (use -1 if there is no score): ", (char*)categoryNames+15);
	scanf("%f", &newScore);
	cat2.score3 = newScore;

	printf("Enter first %s score (use -1 if there is no score): ", (char*)categoryNames+30);
	scanf("%f", &newScore);
	cat3.score1 = newScore;

	printf("Enter second %s score (use -1 if there is no score): ", (char*)categoryNames+30);
	scanf("%f", &newScore);
	cat3.score2 = newScore;

	printf("Enter third %s score (use -1 if there is no score): ", (char*)categoryNames+30);
	scanf("%f", &newScore);
	cat3.score3 = newScore;
	
	printf("Enter first %s score (use -1 if there is no score): ", (char*)categoryNames+45);
	scanf("%f", &newScore);
	cat4.score1 = newScore;

	printf("Enter second %s score (use -1 if there is no score): ", (char*)categoryNames+45);
	scanf("%f", &newScore);
	cat4.score2 = newScore;

	printf("Enter third %s score (use -1 if there is no score): ", (char*)categoryNames+45);
	scanf("%f", &newScore);
	cat4.score3 = newScore;

	// sets categories equal to values given by user
	newStudentData.Cat1 = cat1;
	newStudentData.Cat2 = cat2;
	newStudentData.Cat3 = cat3;
	newStudentData.Cat4 = cat4;
	
	// creates and adds new node
	newStudentData.Current_Grade = -1;
	newStudentData.Final_Grade = -1;	
	newStudentData = CalculateGrades(newStudentData);
	Node *newStudent = CreateNode(newStudentData);
	InsertNode(newStudent, listHead);

	// prints new student
	PrintHeader(categoryNames, file);
	PrintStudent(newStudent, file);
}

