/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
		
#include <stdlib.h>
#include "calculate_cumulative.c"

Data CalculateGrades(Data studentData){
	// calcualtes cumulative grades for all 4 categories
	CalculateCumulative(&studentData.Cat1);
	CalculateCumulative(&studentData.Cat2);
	CalculateCumulative(&studentData.Cat3);
	CalculateCumulative(&studentData.Cat4);
	
	// sets grade for each cateogry to itself or 100 for -1
	float grade1 = (studentData.Cat1.Cumulative != -1 ? studentData.Cat1.Cumulative : 100);
	float grade2 = (studentData.Cat2.Cumulative != -1 ? studentData.Cat2.Cumulative : 100);
	float grade3 = (studentData.Cat3.Cumulative != -1 ? studentData.Cat3.Cumulative : 100);
	float grade4 = (studentData.Cat4.Cumulative != -1 ? studentData.Cat4.Cumulative : 100);
	
	// calculates current grade and sets final to -1
	studentData.Current_Grade = (grade1 * .15) + (grade2 * .3) + (grade3 * .2) + (grade4 * .35);

	studentData.Final_Grade = -1;

	return studentData;
}
