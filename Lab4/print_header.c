/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>

void PrintHeader(char *categoryNames, FILE *file){
	// prints header displaying grades and category names
	fprintf(file, "\nStudent Name \t\t  Student ID#\t\t%s\t\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t\t   Current\tFinal\n",
	categoryNames,(char*)categoryNames+15,(char *)categoryNames+30,	(char*)categoryNames+45);
	fprintf(file, "\t\t\t\t\t1\t 2\t  3\t   Cum\t    1\t     2\t      3\t      Cum\t1\t 2\t  3\t  Cum\t   1\t    2\t     3\t    Cum\n");
} 

