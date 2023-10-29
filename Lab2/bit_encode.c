/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE ** WORK TO
CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
** FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR ** OR GRADERS
OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE ** OHIO STATE UNIVERSITY’S
ACADEMIC INTEGRITY POLICY. */

#include <stdio.h>
#include <stdlib.h>

#define PROMPT


/* This function either takes in user input or file input and generates a hex ciphertext */
/*Author: Sean Kelley */

int main() {
    char userInputText[201];
    int maxTextLength = 200;
    int character, c, i = 0, textLength = 0;
    char Cipher[100]={0};
    char keyPattern[9];
    unsigned char Key = 0; 
    unsigned char ONE = 1;	
	
    /* The ifdef, else and endif parts check if there is the PROMPT macro defined and 
	runs the user input based upon if it is defined or not */

    #ifdef PROMPT

   		/* In the case that PROMPT is defined, file input is directly led using the first while 
		loop and the key pattern is generated in the second while loop. */
	    while (character != '\n' && character != EOF && i < maxTextLength){
			textLength++;
			character = getchar();
			userInputText[i++] = character;
	    }

	 	userInputText[i] = '\0'; 

		i = 0;
	 	while (c != '\n' && c != EOF && i < 4){
			c = getchar();
			keyPattern[i] = c;
			keyPattern[i + 4] = c;
			i++;
	   	 }

    #else

		/* In this case that PROMPT is not defined then the user is prompted for the inputs 
		and the first while gets the input and the second generates the key. The for loop in 
		the middle prints the user input in hex encoding in rows of 10.*/
	    printf("\nEnter clear text to be encrypted (200 characters max): \n");

		while (character != '\n' && character != EOF && i < maxTextLength){
			textLength++;
			character = getchar();
			userInputText[i++] = character;
	   	}

	   	userInputText[i] = '\0'; 

	    printf("\nThe text you entered is: %s\n", userInputText);
		
	   	printf("In hex encoding: \n");

	    for(i = 0; i < textLength - 2 && userInputText[i + 1] != '\0'; i++) {
			printf("%02x ", userInputText[i]);
			if ((i + 1) % 10 ==0 || userInputText[i + 1] == '\n'){
				printf("\n");
			}
	  	}

		printf("\nEnter a 4 bit key pattern (ex: '0110'): \n");

	  	i = 0;
	   	while (c != '\n' && c != EOF && i < 4){
			c = getchar();
			keyPattern[i] = c;
			keyPattern[i + 4] = c;
			i++;
	  	}

    #endif

   	printf("\n");

    /* The following for loop shifts the bits of the key pattern based upon 
	the pattern given by the user. */
    i = 0;
   	for (i; i < 8; i++){ 
 		if(keyPattern[i] == '1'){
			Key = Key | ONE;
        } 
        if(i != 7){
        	Key = Key << 1;
        }
    }
    
    /* The following code uses the key and ciphers the user input absed upon the key given
	and prints it out to the user */

    printf("Your input in hex ciphertext:\n");

    i = 0;
    for (i; i < textLength - 2; i++)
    {
        Cipher[i] = userInputText[i]^Key;
        if(i == 10){
            printf("\n");
        }
		if (&Cipher[i] == "\n"){
	    	break;
		}
        printf("%02x ", Cipher[i]);
    }
    printf("\n");

    return 0;
}

