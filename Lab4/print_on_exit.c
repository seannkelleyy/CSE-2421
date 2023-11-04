/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>

void PrintOnExit(Node **listHead, char *categoryNames, char *fileName){
	FILE *file = fopen(fileName, "w");
	if (file != NULL){
		PrintAllLines(listHead, categoryNames, file);
		fclose(file);
	} else{
		printf("Couldn't open file: %s\n", fileName);
	}

	int numberOfStudents = FreeMemory(listHead);
	printf("A total of %d student records were written to file: %s\n", numberOfStudents, fileName);
}
	
