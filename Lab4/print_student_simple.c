/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>

void PrintStudentSimple(Node* student, char *categoryNames, FILE *file){
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
	fprintf(file, "%-25s", studentData.student_name);
	printf("%s Cumulative: ", categoryNames);
	PrintScore(studentData.Cat1.Cumulative, file);
	printf("%s Cumulative: ", (char*)categoryNames+15);
	PrintScore(studentData.Cat2.Cumulative, file);
	printf("%s Cumulative: ", (char*)categoryNames+30);
	PrintScore(studentData.Cat3.Cumulative, file);
	printf("%s Cumulative: ", (char*)categoryNames+45);
	PrintScore(studentData.Cat4.Cumulative, file);
	printf("Current Grade is: ");
	PrintScore(studentData.Current_Grade, file);
	fprintf(file, "\n");
}
