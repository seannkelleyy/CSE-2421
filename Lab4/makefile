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
	zip lab4 calculate_cumulative.c delete_node.c get_node_for_Id.c insert_node.c lab4.h print_all_lines.c print_header.c print_on_exit.c print_student.c calculate_grades.c create_node.c free_memory.c id_is_duplicate.c lab4main.c makefile print_data.c print_line.c print_score.c read_data.c calculate_class_averages.c print_all.c

#runs lab4 with class_records file as input and new_records as output
run:
	./lab4 class_records new_records

#runs command that checks for memory leaks 
leak: 
	valgrind --leak-check=full -v lab4 class_records new_records



