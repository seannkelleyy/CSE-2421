/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

// author: Sean Kelley

#include <stdlib.h>
#include "lab4.h"
#include "add_new_student.c"
#include "calculate_class_averages.c"
#include "calculate_cumulative.c"
#include "calculate_final_grades.c"
#include "calculate_grades.c"
#include "change_student_grade.c"
#include "create_node.c"
#include "delete_node.c"
#include "delete_student.c"
#include "free_memory.c"
#include "get_node_for_id.c"
#include "get_node_for_last.c"
#include "id_is_duplicate.c"
#include "insert_node.c"
#include "print_all.c"
#include "print_all_lines.c"
#include "print_data.c"
#include "print_header.c"
#include "print_line.c"
#include "print_on_exit.c"
#include "print_score.c"
#include "print_student.c"
#include "print_student_simple.c"
#include "print_with_last.c"
#include "read_data.c"
#include "recalculate_all_grades.c"
#include "recalculate_grades_for_student.c"

int main(int argc, char *argv[]) {
	// checks if user didnt provide valid arguments
    if (argc != 3) {
        printf("Usage: %s filename1 filename2\n", argv[0]);
        return 1;
    }
	
	// assigns arguments to filenames
    char *fileName1 = argv[1];
    char *fileName2 = argv[2];

	Node ** listHead = ReadData(fileName1);
	PrintData(listHead, fileName2);

	return 1;
}
