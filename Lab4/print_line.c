/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
/* This is the program for option 1
* print student scores for a specific student ID#
*/
#include <stdio.h>
#include "get_node_for_Id.c"

void PrintLine(Node **listHead, char *categoryNames, FILE *file){
	Node *NodePtr;
	int StudentID;
#ifdef DEBUG
	fprintf(file, "Student Data. Head List is %x\n", *listHead);
#endif
	/* get studentID to use from user */
	fprintf(file, "Enter the Student ID #: ");
	scanf("%i", &StudentID);
	fprintf(file, "Hunting for %d\n", StudentID);
	/* look for the correct student Node */
	NodePtr = Get_NodeforId(listHead, StudentID);
	/* we found it or not */
	if(NodePtr == NULL){ //Student.student_ID == -1
		fprintf(file, "\nERROR: Student ID number %i was not found in the list\n",StudentID);
		return;
	}
	else {
		PrintHeader(categoryNames, file);
		PrintStudent(NodePtr, file);
	}
}
