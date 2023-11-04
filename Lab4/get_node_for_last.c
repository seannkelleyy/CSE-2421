/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <string.h>

Node * GetNodeForLast(Node **listHead, char studentLast[40]){
	Node *traverseNode = *listHead;
	char *lastName;
	char studentNameCopy[40];

	// loops until node is found
	while (traverseNode != NULL){
		strcpy(studentNameCopy, traverseNode->Student.student_name);
		lastName = strtok(studentNameCopy, ",");
		if (strcmp(lastName, studentLast) == 0){
			printf("%s", lastName);
			return traverseNode;
		}
		traverseNode = traverseNode->next;
	}

    return NULL;
}
	
	
