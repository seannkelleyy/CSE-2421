/*function to create the title array of books for the user */
char** createTitleArray(int *numberOfTitles);

/*function to create favorites array */
char** createFavoritesArray(char **titles, int numberOfTitles, int *numberOfFavorites);

/*function to create the output file */
int createOutputFile(char **titles, char **favorites, int titleLength, int favoriteLength);
