/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

// author: Sean Kelley

#include <stdlib.h>
#include "lab4.h"
#include "read_data.c"
#include "print_data.c"

int main(int argc, char *argv[]) {
	// checks if user didnt provide valid arguments
    if (argc != 3) {
        printf("Usage: %s filename1 filename2\n", argv[0]);
        return 1;
    }
	
	// assigns arguments to filenames
    char *fileName1 = argv[1];
    char *fileName2 = argv[2];

	Node ** listHead = ReadData(fileName1);
	PrintData(listHead, fileName2);

	return 1;
}
