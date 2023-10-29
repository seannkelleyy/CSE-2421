/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

Node * Get_NodeforId(Node **listHead, int studentId){
	Node *traverseNode = *listHead;

	// returns first node if it is the right id
	if (traverseNode->Student.student_ID == studentId){
		return traverseNode;
	}

	// loops until node is found
	while (traverseNode != NULL){
		if (traverseNode->Student.student_ID == studentId){
			return traverseNode;
		}
		traverseNode = traverseNode->next;
	}

    return NULL;
}
	
	
