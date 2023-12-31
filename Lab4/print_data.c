/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>

void PrintData(Node **listHead, char *fileName){
	// creates function pointer array and assigns functions
	void (*fp[8])(Node **, char *, FILE *);
	fp[0] = PrintLine;
	fp[1] = PrintWithLast;
	fp[2] = PrintAll;
	fp[3] = RecalculateGradesForStudent;
	fp[4] = RecalculateAllGrades;
	fp[5] = ChangeStudentGrade;
	fp[6] = CalculateFinalGrades;
	fp[7] = AddNewStudent;
	
	// declares variables used later in function
	int userChoice;
	char *categoryNames = malloc(60 * sizeof(char));
	
	// checks if memory was allocated correctly
	if(categoryNames == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	
	// assigns category names for students grades
	strcpy(categoryNames, "Quizzes");
	strcpy(categoryNames + 15, "Midterms");
	strcpy(categoryNames + 30, "Homeworks");
	strcpy(categoryNames + 45, "Final");
	
	// loops until user enters 10. prompts user for their option choice 
	int validEntry;
	do {
		printf("\nPlease enter an option between 1 and 10: \n1) Print Student Scores by Student ID\n2) Print Student Scores by Last Name\n3) Print Student Scores for All Students\n4) Recalculate Student Scores for a Single Student ID\n5) Recalculate All Student Scores\n6) Insert a score for a specific Student ID\n7) Calculate Final Grades\n8) Add a new student\n9) Delete a student\n10) Exit Program\n");
		printf("Option: ");
		
		validEntry = scanf("%d", &userChoice);

		// checks if user entered a valid entry
		if(validEntry != 1){
		    printf("Invalid input. Please enter a number between 1 and 10.\n");

		    // clears the input buffer
		    while(getchar() != '\n');

		    continue;
		}
		
		// tells user that their entry was invalid and prompts them for a new input
		if(userChoice < 1 || userChoice > 10){
		    printf("Invalid input. Please enter a number between 1 and 10.\n");
		    continue;
		}
		
		// calls the function based on what the user chose, using an array of 
		// function pointers or switch
		if ((unsigned)userChoice <= 8){
		    fp[userChoice - 1](listHead, categoryNames, stdout);
		} else {
		    switch (userChoice){
		        case 9 :
		            DeleteStudent(listHead);
		            break;
		        case 10 :
		            PrintOnExit(listHead, categoryNames, fileName);
		            break;
		        default : 
		            printf("Please enter a valid number.");
		            break;
		    }
		}        
	} while(userChoice != 10);

	// frees memory used
	free(categoryNames);
}
		
