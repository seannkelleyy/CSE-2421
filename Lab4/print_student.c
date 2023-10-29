/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>
#include "print_score.c"

void PrintStudent(Node* student, FILE *file){
	// checks if needed data is NULL
	if (student == NULL) {
        fprintf(file, "Error: student is NULL\n");
        return;
    }
	if (&(student->Student) == NULL) {
        fprintf(file, "Error: student data is NULL\n");
        return;
    }

	// prints data using Print score function
	Data studentData = student->Student;
	studentData.student_name[strcspn(studentData.student_name,"\n")] = 0;
	fprintf(file, "%-25s\t", studentData.student_name);
	fprintf(file, "%d\t", studentData.student_ID);
	PrintScore(studentData.Cat1.score1, file);
	PrintScore(studentData.Cat1.score2, file);
	PrintScore(studentData.Cat1.score3, file);
	PrintScore(studentData.Cat1.Cumulative, file);
	PrintScore(studentData.Cat2.score1, file);
	PrintScore(studentData.Cat2.score2, file);
	PrintScore(studentData.Cat2.score3, file);
	PrintScore(studentData.Cat2.Cumulative, file);
	PrintScore(studentData.Cat3.score1, file);
	PrintScore(studentData.Cat3.score2, file);
	PrintScore(studentData.Cat3.score3, file);
	PrintScore(studentData.Cat3.Cumulative, file);
	PrintScore(studentData.Cat4.score1, file); 
	PrintScore(studentData.Cat4.score2, file);
	PrintScore(studentData.Cat4.score3, file);
	PrintScore(studentData.Cat4.Cumulative, file);
	PrintScore(studentData.Current_Grade, file);
	fprintf(file, "\t");
	PrintScore(studentData.Final_Grade, file);
	fprintf(file, "\n");
}
