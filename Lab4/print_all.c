/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>

void PrintAll(Node **listHead, char *categoryNames, FILE *file){
	// calls print all lines then calculates the average grades */
	PrintAllLines(listHead, categoryNames, file);

	float *averages = CalculateClassAverages(listHead);
	fprintf(stdout, "\nClass Averages for Quizzes: %.2f, Midterms: %.2f, Homework: \
%.2f, Final: %.2f Current Grade: %.2f\n", *averages, *(averages + 1), 
	*(averages + 2), *(averages + 3), *(averages + 4));
	free(averages);

}
