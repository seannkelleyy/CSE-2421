/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
#include <stdlib.h>

int FreeMemory(Node **listHead){
	// initializes pointers
	Node *currentNode = *listHead;
	Node *nextNode = NULL;
	
	// loops through nodes and free them
	int numberOfStudents = 0;
	while (currentNode != NULL){
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
		numberOfStudents++;
	}
	// free node pointers
	free(listHead);
	free(currentNode);
	free(nextNode);
	return numberOfStudents;
}
