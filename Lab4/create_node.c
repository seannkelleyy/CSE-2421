/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
Node* CreateNode(Data studentData) {
	// allocates memory for new node and returns if the node could not be calculated
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Could not allocate memory for new node\n");
        return NULL;
    }

	// sets data on new node and returns it
    newNode->Student = studentData;
    newNode->next = NULL;
    return newNode;
}

