/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>

void PrintScore(float score, FILE *file){
	// correctly prints a score, n/a if -1 or the score if not -1
	if (score == -1 || score == 0) {
        fprintf(file, "%-8s", "n/a  ");
    } else {
        fprintf(file, "%-8.2f ", score);
    }
}
