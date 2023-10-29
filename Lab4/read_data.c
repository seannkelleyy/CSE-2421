/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate_grades.c"
#include "create_node.c"
#include "insert_node.c"
#include "id_is_duplicate.c"

Node** ReadData(char *fileName){
	/*Initializing list head and file*/
	Node **listHead = malloc(sizeof(Node*));
	*listHead = NULL;
	FILE *inputFile;

	/*Opening file and exiting if its null */
	inputFile=fopen(fileName, "r");

	if (inputFile == NULL){
		printf("\nCannot Read File '%s': \n", fileName);
		exit(0);
	} else {
		printf("\nReading File...\n");
	}

	char firstLine[256];
	fgets(firstLine, sizeof(firstLine), inputFile);

	char studentName[25];

	int numberOfStudents = 0;
	while (fgets(studentName, sizeof(studentName), inputFile)){
		if (strcmp(studentName, "\n") == 0 || strcmp(studentName, "") == 0) continue;
		Data studentData;

		strcpy(studentData.student_name, studentName);
		
		fscanf(inputFile, "%d", &(studentData.student_ID));
		
		int isDuplicate = (IdIsDuplicate(listHead, studentData.student_ID));

		if (isDuplicate == 1){
			continue;
		}

		fscanf(inputFile, "%f %f %f", &(studentData.Cat1.score1), &(studentData.Cat1.score2), &(studentData.Cat1.score3));
	
		fscanf(inputFile, "%f %f %f", &(studentData.Cat2.score1), &(studentData.Cat2.score2), &(studentData.Cat2.score3));

		fscanf(inputFile, "%f %f %f", &(studentData.Cat3.score1), &(studentData.Cat3.score2), &(studentData.Cat3.score3));

		fscanf(inputFile, "%f %f %f", &(studentData.Cat4.score1), &(studentData.Cat4.score2), &(studentData.Cat4.score3));

		studentData = CalculateGrades(studentData);
		Node * newStudent = CreateNode(studentData);
		InsertNode(newStudent, listHead); 
		numberOfStudents++;
	}
	if (fclose(inputFile) != 0){
		printf("Failed to close your input file.\n");
	}
	

	printf("Completed getting students data.\n");
	printf("%d students were read\n", numberOfStudents);

	return listHead;
}
