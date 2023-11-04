/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

void DeleteStudent(Node **listHead){
	// initialize variables 
	int studentId;
	int userConfirm;
	char copyOfName[40];
	Node *student;
	
	// asks user for the student id they want to delete
	printf("Please enter the student ID number you wish to delete, followed by enter.\n");
	scanf("%d", &studentId);
	student = GetNodeForId(listHead, studentId);
	
	if (student == NULL) {
		printf("The student ID you entered doesn't exist.\n");
	} else {
		// confirms with user to delete the name
		printf("Do you really wish to delete student ID number %d, %s\n", studentId, student->Student.student_name);
		printf("Enter 1 if yes, enter 2 if no: ");
		scanf("%d", &userConfirm);
		
		// checks to make sure user wants to the delete the user
		// then deletes it
		if (userConfirm == 1) {
			DeleteNode(listHead, student);
			printf("Student ID number %d, %s has been deleted\n", studentId, student->Student.student_name);
		}
	}
}
