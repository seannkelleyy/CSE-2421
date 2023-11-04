/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/


#include <stdio.h> 

typedef struct Cat_Grade{
	float score1;
	float score2;
	float score3;
	float Cumulative;
} Cat_Grade;

typedef struct Data {
	char student_name[40];
	int student_ID;
	struct Cat_Grade Cat1;
	struct Cat_Grade Cat2;
	struct Cat_Grade Cat3;
	struct Cat_Grade Cat4;
	float Current_Grade;
	float Final_Grade;
} Data;

typedef struct Node {
	struct Data Student;
	struct Node *next;
} Node;

/*Reads student data from input file 1 and constructs the linked list for the student data */
Node** ReadData(char *fileName);


/*------------ Functions that relate to grades ------------*/
/*Calculates the grades for a student */
Data CalculateGrades(Data studentData);


/*Calculates the grades for the given category */
int CalculateCumulative(Cat_Grade * category);

/*Calculates class averages */
float * CalculateClassAverages(Node ** listHead);


/*---------- Functions that relate to nodes ------------- */
/*Creates a new student node with the given data and returns a pointer to it */
Node * CreateNode(Data studentData);


/*Insterts a new Node with the given student info in the linked list */
int InsertNode(Node* student, Node** listHead);


/* Deletes the given node */
void DeleteNode(Node **listHead, Node *node);


/*------------ Functions that print data ---------- */
/*Prints the info that the user requests. */
void PrintData(Node **listHead, char *fileName);


/*Prints the header that says that each section of student data means */
void PrintHeader(char *categoryNames, FILE *file);


/*Prints all the information about a student in one line */
void PrintStudent(Node* student, FILE *file);


/*Prints a simpler version of student for option 4 */
void PrintStudentSimple(Node* student, char* categoryNames, FILE *file);


/*Prints a score for a given category, if its -1 prints n/a */
void PrintScore(float score, FILE *file);


/*Prints all lines of student data */
void PrintAllLines(Node **listHead, char *categoryNames, FILE *file);


/*User option 1: prints a single line about a student specified by the user */
void PrintLine(Node **listHead, char *categoryNames, FILE *file);


/*User option 2: prints a single line about a student specified by the user with the last name */
void PrintWithLast(Node **listHead, char *categoryNames, FILE *file);


/*User option 3: prints all lines of the linked list */
void PrintAll(Node **listHead, char *categoryNames, FILE *file);


/*User option 4: recalculates a students grades and prints them */
void RecalculateGradesForStudent(Node **listHead, char * categoryNames, FILE* file);


/*User option 5: recalculates all students grades and prints them */
void RecalculateAllGrades(Node **listHead, char *categoryNames, FILE *file);


/*User option 6: asks user for student id and what grades they want to change for that student */
void ChangeStudentGrade(Node **listHead, char *categoryNames, FILE *file);


/* User option 7: calculates final grades for a student */
void CalculateFinalGrades(Node **listHead, char *categoryNames, FILE *file);


/*User options 8: adds new student using info provided by user */
void AddNewStudent(Node **listHead, char* categoryNames, FILE *file);


/*User option 9: deletes a student using student id */
void DeleteStudent(Node **listHead);


/*User Options 10: Prints all data to output file */
void PrintOnExit(Node **listHead, char *categoryNames, char *fileName);


/*------------ Helper functions --------- */
/*Checks whether a student with the given id is already in the list */
int IdIsDuplicate(Node **listHead, int newStudentID);


/*Gets the node for the given student id if it exists */
Node * GetNodeForId(Node **listHead, int studentId);


/*Gets the node for the given student last name if it exists */
Node * GetNodeForLast(Node **listHead, char studentLast[40]);


/*Frees all memory used by program */
int FreeMemory(Node **listHead);


