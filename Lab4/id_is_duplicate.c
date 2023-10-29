/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

/* This program looks through our linked list and
* tells the caller program if the studentID # is already
* in use within the linked list
*/
int IdIsDuplicate(Node **listHead, int newStudentID){
	Node *traversePtr = *listHead;
	while(traversePtr!=NULL){
		if (traversePtr->Student.student_ID == newStudentID) {
			/* found it already in the linked list */
			return(1);
		}
		traversePtr = traversePtr->next;
	}
	return(0);
}

