#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int smallet(int x, int , int z);
int digit_to_int(char d);

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
    	

    	

    	int i = 0;

    	char *array[3];

    	char *p = strtok(str, "x");
    	 while (p != NULL) {
    	 	array[i++] = p;
    	 	p = strtok(NULL, "x");
  		}	

  		currLenght = sscanf(array[0], "%d", &i);
  		currWidht = sscanf(array[1], "%d", &i);
  		currHeight = sscanf(array[2], "%d", &i);

  		printf("%d\n", currLenght);
  		printf("%d\n", currWidht);
  		printf("%d\n", currHeight);
  		currPresentFeet = (2*currLenght*currWidht) + (2*currWidht*currHeight) + (2*currHeight*currLenght) + (smallet((currLenght*currWidht), (currWidht*currHeight), (currHeight*currWidht)));
    	printf("%d\n", currPresentFeet);
    	totalFeet +=currPresentFeet;
    	printf("%d\n", totalFeet);
    }
    printf("%d\n", totalFeet);

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);


	return 0;
}

int digit_to_int(char d) {
 char str[2];

 str[0] = d;
 str[1] = '\0';
 return (int) strtol(str, NULL, 10);
}

int smallet(int x, int y, int z) {
	if((x < y) && (x < z)) {
		return x; 
	} else if(y < z) {
		return y;
	} else {
		return z;x§
	}
}