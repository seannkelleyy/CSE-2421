/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
void deleteNode(Node **listHead, Node *node){
	Node *prevNode = *listHead;
	Node *traverseNode =prevNode->next;
	if(*listHead == node){
		*listHead = node->next;
	} else{
		while(traverseNode != NULL){
			if (traverseNode->Student.student_Id == node->Student.student_Id){
				prevNode->next = traverseNode->next;
			}
			prevNode = prevNode->next;
			traverseNode = traverseNode->next;
		}
	}
}
