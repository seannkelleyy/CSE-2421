/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/
int CalculateCumulative(Cat_Grade * category){
	// declares variables
    category->Cumulative = 0.0;
	int numberOfValidScores = 0;
	float scores[] = {category->score1, category->score2, category->score3};
	
	// loops through the category adding the grades up
    for (int i = 0; i < sizeof(scores)/sizeof(float); i++) {
		if (scores[i] != -1){
        	category->Cumulative += scores[i];
			numberOfValidScores++;
		}
    }
	
	// sets cumulative grades based on how many grades were not -1
	if(numberOfValidScores != 0) {
		category->Cumulative = category->Cumulative / numberOfValidScores;
	} else {
		category->Cumulative =-1;
	}
	
	return 1;
}
