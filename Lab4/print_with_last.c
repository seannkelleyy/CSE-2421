/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>

void PrintWithLast(Node **listHead, char *categoryNames, FILE *file){
	Node *NodePtr;
	char studentLast[40];
#ifdef DEBUG
	fprintf(file, "Student Data. Head List is %x\n", *listHead);
#endif
	/* get studentLast to use from user */
	fprintf(file, "Enter the Student Last Name: ");
	scanf("%s", &studentLast);
	fprintf(file, "Hunting for %s\n", studentLast);
	/* look for the correct student Node */
	NodePtr = GetNodeForLast(listHead, studentLast);
	if(NodePtr == NULL){ //Student.student_name doesnt exist
		fprintf(file, "\nERROR: Student last name %s was not found in the list\n",studentLast);
		return;
	}
	else {
		PrintHeader(categoryNames, file);
		PrintStudent(NodePtr, file);
	}
}
