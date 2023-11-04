/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
		
#include <stdlib.h>

void CalculateFinalGrades(Node **listHead, char *categoryNames, FILE *file){
	//initializes variables
	Node *traverseNode = *listHead;
	float grade1; 
	float grade2;
	float grade3;
	float grade4; 

	// checks if list is empty
	if (*listHead == NULL) {
        fprintf(file, "The list is empty.\n");
        return;
    }
	// calculates final for all students and prints them all
	while (traverseNode != NULL){
		// sets grade for each cateogry to itself or 0 for -1
		grade1 = (traverseNode->Student.Cat1.Cumulative != -1 ? traverseNode->Student.Cat1.Cumulative : 0);
		grade2 = (traverseNode->Student.Cat2.Cumulative != -1 ? traverseNode->Student.Cat2.Cumulative : 0);
		grade3 = (traverseNode->Student.Cat3.Cumulative != -1 ? traverseNode->Student.Cat3.Cumulative : 0);
		grade4 = (traverseNode->Student.Cat4.Cumulative != -1 ? traverseNode->Student.Cat4.Cumulative : 0);
		
		// calculates final grade
		traverseNode->Student.Final_Grade = (grade1 * .15) + (grade2 * .3) + (grade3 * .2) + (grade4 * .35);
		traverseNode = traverseNode->next;
	}

	PrintAll(listHead, categoryNames, file);
}
