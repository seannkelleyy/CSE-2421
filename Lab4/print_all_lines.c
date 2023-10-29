/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
#include <stdio.h>
#include "calculate_class_averages.c"

void PrintAllLines(Node **listHead, char *categoryNames, FILE *file){
	Node *traverseNode = *listHead;
	// checks if list is empty
	if (*listHead == NULL) {
        fprintf(file, "The list is empty.\n");
        return;
    }
	// prints header and every student
	PrintHeader(categoryNames, file);
	while (traverseNode != NULL){
		PrintStudent(traverseNode, file);
		traverseNode = traverseNode->next;
	}
}
		
