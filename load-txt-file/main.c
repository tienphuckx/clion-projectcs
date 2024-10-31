#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int STEPSIZE = 100;
char ** loadfile(char * filename);
int main(const int argc, char *argv[]) {
    if(argc == 1) {
        printf(stderr, "Must provide a [filename] to read\n");
        exit(1);
    }

    // load the file into data structure
    char *filename = argv[1];
    char **words = loadfile(filename);
    if(!words){
        fprintf(stderr, "Fail to load file %s\n", filename);
        exit(1);
    }

    // display the entire file
    for(int i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
    }
    printf("Done.");
    return 0;
}

char ** loadfile(char * filename) {
    FILE *f = fopen(filename, "r");
    if(!f) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    int arrlen = 0;

    // allocate space for STEPSIZE char*
    // each char* point to a string (foint to the first char of one line)
    char **lines = NULL;

    // read each line from the file
    char buf[1000];
    int i = 0;
    while (fgets(buf, sizeof(buf), f)) {
        // check if lines** is full, then reallocate(expand) it
        if (i == arrlen) {
            arrlen += STEPSIZE;
            char ** newlines = (char **)realloc(lines, sizeof(char *) * arrlen);
            if(!newlines) {
                fprintf(stderr, "Fail to realloc(), Out of memory\n");
                exit(1);
            }
            // realloc will return a new address
            // copy all exists data
            // add more exanded space
            // and return the new address
            lines = newlines;
        }
        // fgets read a string and also the "\n" at the end
        // trim off the newline char
        // P H U C \n \0
        // 0 1 2 3  4  5
        // now we need to remove the \n
        // keep the \0
        // assign \n = \0
        if(buf[strlen(buf)] == '\n') buf[strlen(buf)] = '\0';

        // get new length of buf
        int slen = strlen(buf);

        // allocate space memory a size equal with the data readed
        char *line = (char *)malloc(sizeof(char) * (slen + 1));

        // copy string from buf to space
        strcpy(line, buf);

        // Attach str to the data structure
        lines[i] = line;
        i++;
    }
    
    if(i == arrlen) {
        // realloc will return a new address
        char **newarr =  newarr = (char **)realloc(lines, sizeof(char *) * (arrlen + 1));
        if(!newarr) {
            fprintf(stderr, "Fail to realloc(), Out of memory for newarr\n");
            exit(1);
        }
        lines = newarr;
    }
    
    // Put NULL at the very last element to mark the end of the array
    lines[i] = NULL;

    // close the file
    fclose(f);

    // return the array of strings
    return lines;
}
