# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
#THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
#THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
#INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
#TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY

#makes shortcut to clean, build and run the project
all:clean lab4 run

#removes old executable and object file
clean:
	rm -f lab4.o lab4

#creates lab3 executable
lab4: lab4.o
	gcc lab4.o -o lab4

#creates lab3 executable dependency
lab4.o: lab4main.c lab4.h
	gcc -std=c99 -pedantic -g -c lab4main.c -o lab4.o

#creates zip file to turn into carmen
lab4.zip: makefile lab4main.c lab4.h
	zip lab4 add_new_student.c get_node_for_last.c print_all_lines.c print_student.c calculate_class_averages.c create_node.c id_is_duplicate.c print_data.c print_student_simple.c calculate_cumulative.c delete_node.c insert_node.c print_header.c print_with_last.c calculate_final_grades.c delete_student.c makefile print_line.c read_data.c calculate_grades.c free_memory.c lab4.h print_on_exit.c recalculate_all_grades.c change_student_grade.c get_node_for_id.c lab4main.c print_all.c print_score.c recalculate_grades_for_student.c


#runs lab4 with class_records file as input and new_records as output
run:
	./lab4 class_records new_records

#runs command that checks for memory leaks 
leak: 
	valgrind --leak-check=full -v lab4 class_records new_records

#runs debugger
debug: clean lab4
	gdb ./lab4 class_records new_records
	

