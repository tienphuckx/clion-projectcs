#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int STEPSIZE = 100;
char ** loadfile(char * filename, int * len);
int main(const int argc, char *argv[]) {
    if(argc == 1) {
        printf(stderr, "Must provide a [filename] to read\n");
        exit(1);
    }

    // load the file into data structure
    int length = 0;
    char *filename = argv[1];
    char **words = loadfile(filename, &length);
    if(!words){
        fprintf(stderr, "Fail to load file %s\n", filename);
        exit(1);
    }

    // display the entire file
    printf("Loaded %d words\n", length);
    for(int i = 0; i < length; i++) {
        printf("%s\n", words[i]);
    }
    printf("Done.");
    return 0;
}

char ** loadfile(char * filename, int * len) {
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
        buf[strlen(buf) - 1] = '\0';

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

    *len = i; // set leng
    return lines;
}
