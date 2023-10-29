/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

float * CalculateClassAverages(Node ** listHead){
	// initializes the traverseneNode and averages array
	Node *traverseNode = *listHead;
	
	float *averages = calloc(5, sizeof(float));
	int numberOfStudents = 0;
	
	// adds up all the grades for each category
	while (traverseNode != NULL){
		averages[0] += traverseNode->Student.Cat1.Cumulative;
		averages[1] += traverseNode->Student.Cat2.Cumulative;
		averages[2] += traverseNode->Student.Cat3.Cumulative;
		averages[3] += traverseNode->Student.Cat4.Cumulative;
		averages[4] += traverseNode->Student.Current_Grade;
		traverseNode = traverseNode->next;
		numberOfStudents++;
	}
	
	// computes averages for each category
	averages[0] /= numberOfStudents;
	averages[1] /= numberOfStudents;
	averages[2] /= numberOfStudents;
	averages[3] /= numberOfStudents;
	averages[4] /= numberOfStudents;

	return averages;
}



