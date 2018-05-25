#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int smallet(int x, int , int z);

int main() {

	int totalFeet = 0;

    int currPresentFeet = 0;



	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/home/alexander/Documents/C/input.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
    	int currLenght = 0;
    	int currWidht = 0;
    	int currHeight = 0;


           char *substr = NULL;
           /*"Initializes" strtok and gets the first substring*/
           substr = strtok(line,"x");
           /*Loops until there are no more substrings*/
           int i = 0;
           while(substr!=NULL)  {
               /*Prints the token*/
                if (i==0) {
                    sscanf(substr, "%d", &currLenght);
            
                } else if (i==1) {
                    sscanf(substr, "%d", &currWidht);
                    
                } else {
                    sscanf(substr, "%d", &currHeight);
                }
                i++;
               
               /*Gets the next substrings*/
               substr = strtok(NULL," x");
          }

        printf("%d\n", currLenght);
        printf("%d\n", currWidht);
        printf("%d\n", currHeight);
        currPresentFeet = (2*currLenght*currWidht) + (2*currWidht*currHeight) + (2*currHeight*currLenght) 
        + (smallet((currLenght*currWidht), (currWidht*currHeight), (currHeight*currLenght)));

        totalFeet +=currPresentFeet;
        

    }
    printf("%d\n", totalFeet);

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);


	return 0;
}

int smallet(int x, int y, int z) {
	if((x < y) && (x < z)) {
		return x; 
	} else if(y < z) {
		return y;
	} else {
		return z;
	}
}