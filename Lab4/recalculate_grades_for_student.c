/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>

void RecalculateGradesForStudent(Node **listHead, char * categoryNames, FILE* file){
	Node *NodePtr;
	int studentId;
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
		// if the student exists, recalcualte grades and print
		CalculateGrades(NodePtr->Student); 
		PrintStudentSimple(NodePtr, categoryNames, file);
	}
}
