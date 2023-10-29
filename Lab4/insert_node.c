/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/


int InsertNode(Node * newNode, Node ** listHead){
	// checks if node is null
    if (newNode == NULL){
        printf("New node was null");
        return 0;
    }

	// puts new node at list head if list head is empty or traverse throught list
	// until the student id is in the right location
    Data *studentData = &newNode->Student;
    if (*listHead == NULL || (*listHead)->Student.student_ID > studentData->student_ID){
        newNode->next = *listHead;
        *listHead = newNode;
    } else {
        Node *traverseNode = *listHead;
        while (traverseNode->next != NULL &&
				traverseNode->next->Student.student_ID < studentData->student_ID) {
            traverseNode = traverseNode->next;
        }
        newNode->next = traverseNode->next;
        traverseNode->next = newNode;
    }
    return 1;
}

