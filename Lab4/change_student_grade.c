/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
#include <stdio.h>
#include <string.h>

void ChangeStudentGrade(Node **listHead, char *categoryNames, FILE *file){
	// initializes variables
	Node *NodePtr;
	int studentId;
	int userChoice;
	int userCategory;
	int userScore;
	float newScore;
	Cat_Grade *selectedCategory;
	char copyOfName[40];
	
#ifdef DEBUG
	fprintf(file, "Student Data. Head List is %x\n", *listHead);
#endif
	/* get studentLast to use from user */
	fprintf(file, "Enter the Student ID # ");
	scanf("%d", &studentId);
	fprintf(file, "Hunting for %d\n", studentId);
	/* look for the correct student Node */
	NodePtr = GetNodeForId(listHead, studentId);

	if(NodePtr == NULL){ //Student.student_ID == -1
		fprintf(file, "\nERROR: Student ID number %d was not found in the list\n",studentId);
		return;
	}
	else {
		// checks to make sure name isnt empty and takes off \n at end
		strcpy(copyOfName, NodePtr->Student.student_name);
		int length = strlen(copyOfName);

		if (length > 0 && copyOfName[length-1] == '\n') {
		    copyOfName[length-1] = '\0';
		}
		
		// asks user to decide if they want to change the score
		// then prompts them for the data
		printf("Enter 1 to change the score for %s or 2 to exit: ", copyOfName);
		scanf("%d", &userChoice);
		if (userChoice == 1){
			printf("Which category?\n");
			printf("1) %s\n", categoryNames);
			printf("2) %s\n", (char*)categoryNames+15);
			printf("3) %s\n", (char*)categoryNames+30);
			printf("4) %s\n", (char*)categoryNames+45);
			scanf("%d", &userCategory);
			printf("Which score?\nEnter 1, 2 or 3: ");
			scanf("%d", &userScore);
			printf("New score: ");
			scanf("%f", &newScore);

			// switch statements get the category and changes the
			// score for that category
			switch(userCategory) {
				case (1) :
					selectedCategory = &(NodePtr->Student.Cat1);
					break;
				case (2) :
					selectedCategory = &(NodePtr->Student.Cat2);
					break;
				case (3) :
					selectedCategory = &(NodePtr->Student.Cat3);
					break;
				case (4) :
					selectedCategory = &(NodePtr->Student.Cat4);
					break;
				default :
					printf("Error access category %d", userCategory);
				
			}
			switch(userScore){
				case (1) :
					selectedCategory->score1 = newScore;
					break;
				case (2) :
					selectedCategory->score2 = newScore;
					break;
				case (3) :
					selectedCategory->score3 = newScore;
					break;
				default :
					printf("Error accessing score #%d", userScore);
					break;
			}
			
			// calculates cumulative and prints header and student
			CalculateCumulative(selectedCategory);
			PrintHeader(categoryNames, file);
			PrintStudent(NodePtr, file);
		}
	}
}
