/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF 
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS 
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR OR
GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE 
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY. THIS IS THE README FILE 
FOR LAB 3.*/

// CSE 2421 Lab 3
// Author: Sean Kelley

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lab3.h"

int main() {
    int numberOfTitles = 0;
    int *pNumberOfTitles = &numberOfTitles;
	int numberOfFavorites = 0;
    int *pNumberOfFavorites = &numberOfFavorites;
    char **titles;
	char **favorites;
	int saveFile;

	// call functions to create list of titles and books
    titles = createTitleArray(pNumberOfTitles);
	
	favorites = createFavoritesArray(titles, numberOfTitles, pNumberOfFavorites);
    
	// Ask user if they want to save to a file then creates a file if they do
	printf("Would you like to save your books to a file (1=yes, 2=no): ");
	scanf("%d", &saveFile);

	if (saveFile == 1){
		createOutputFile(titles, favorites, numberOfTitles, numberOfFavorites);
	} else{
		printf("File will not be created, exiting...");
	}

    // Deallocate dynamic memory used in the program
    for (int i = 0; i < numberOfTitles; i++) {
        free(*(titles + i));
    }
    free(titles);

	for (int i = 0; i < numberOfFavorites; i++) {
        free(*(favorites + i));
    }
    free(favorites); 

    return 0;
}

char **createTitleArray(int *numberOfTitles) {
    char **titles;
	
	// Asks user for number of books and checks if they entered a valid number
    printf("Please enter the number of book titles that you would like to enter: ");
    scanf("%d", numberOfTitles);

    if (*numberOfTitles < 1) {
        printf("Number of titles must be at least 1. Exiting.\n");
        exit(1);
    }

    // Allocate memory for titles. returns if memory isn't allocated
    titles = (char **)malloc(sizeof(char *) * (*numberOfTitles));

	if (!titles) {
        printf("Memory allocation failed. Exiting.\n");
        return 0;
    }

    getchar(); // Remove the newline character left in the input buffer
			   // the newline causes issues when entering input in next part

	// Gets the user input and stores it in the title array, makes sure memory
	// was allocated properly and gets input and exits if input was improperly read
    printf("Enter the %d book titles, one per line:\n", *numberOfTitles);
    for (int i = 0; i < *numberOfTitles; i++) {
        *(titles + i) = (char *)malloc(61);
        if (!(*(titles + i))) {
            printf("Memory allocation failed. Exiting.\n");
            return 0;
        }
        if (fgets((*(titles + i)), 60, stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            return 0;
        }
        (*(titles + i))[strcspn((*(titles + i)), "\n")] = '\0'; 
			// Remove the trailing newline that causes input issues
    }

	// Prints users titles that were imput back 
    printf("\nYou've entered:\n");
    for (int i = 0; i < *numberOfTitles; i++) {
        printf("%d. %s\n", i + 1, *(titles + i));
    }

    return titles; // Return the allocated memory
}

char** createFavoritesArray(char **titles, int numberOfBooks, 
	int *numberOfFavorites) {

    char **favorites;
	char validNumOfFavorites = 0;

	// Asks user for number of favorites, prompting them until they enter a 
	// valid number
	printf("\nOf those %d books, how many would you like to add to favorites?: ",
	 numberOfBooks);
	scanf("%d", numberOfFavorites);

	if (*numberOfFavorites >= 0 && *numberOfFavorites <= numberOfBooks){
		validNumOfFavorites = 1;
	}
		
	while (!validNumOfFavorites){
		printf("Invalid number, enter a number between 0 and %d: ", numberOfBooks);
		scanf("%d", numberOfFavorites);
		if (*numberOfFavorites == 0){
			printf("No favorites will be added.");
			return 0;
		} else if (*numberOfFavorites >= 0 && *numberOfFavorites <= numberOfBooks){
			validNumOfFavorites = 1;
		} 
	}
		

	// Allocates memory for favorites then fills up array. Returns if invalid
	// input, due to null title
	favorites = (char **)malloc(sizeof(char *) * (*numberOfFavorites));

	if (!favorites) {
        printf("Memory allocation failed. Exiting.\n");
        return 0;
    }
	
	// asks user for number for each book to be added to favorites, 
	// then allocates memory returns if memory isn't allocated, then 
	// adds title to favorites array
	printf("Enter the number next to each book that you want to add to favorites: ");
	for (int i = 0; i < *numberOfFavorites; i++){
		int bookNumber;
		scanf("%d", &bookNumber);
		if (bookNumber < 1 || bookNumber > numberOfBooks){
			printf("Invalid book number input, Exiting...", bookNumber);
			return 0;
		}
		*(favorites + i) = (char *)malloc(61);

		if (!*(favorites + i)){
			printf("Failed to allocate memory. Exiting... \n");
			return 0;
		}
		strcpy(*(favorites + i), *(titles + (bookNumber - 1)));
	}
	
	// prints titles on favorites list then returns list
	printf("\nYour favorites are: \n");
    for (int i = 0; i < *numberOfFavorites; i++) {
        printf("%d. %s\n", i + 1, *(favorites + i));
    }

    return favorites; 
}

int createOutputFile(char **titles, char **favorites, int titleLength,
	int favoriteLength){

	char fileName[100];
	char *bookTitle;

	// get file name from user and create file
	printf("Enter the file name: ");
	scanf("%s", fileName);
	strcat(fileName, ".txt");
	FILE *out=fopen(fileName,"w"); 

	// loop through all books and favorite and write them to the file
	fputs("Books I've Read:\n" ,out);
	for (int i = 0; i < titleLength; i++){
		bookTitle = *(titles + i);
		strcat(bookTitle, "\n");
		fputs(bookTitle,out);
	}

	fputs("\n\nMy Favorites Are:\n" ,out);
	for (int i = 0; i < favoriteLength; i++){
		bookTitle = *(favorites + i);
		strcat(bookTitle, "\n");
		fputs(bookTitle ,out);
	}
	
	// close file and tell user that the file is ready
	fclose(out);
	printf("Your booklist and favorites have been saved to %s\n", fileName);

	return 1;
}


