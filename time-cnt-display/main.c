#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep()

int main() {
    int h = 0, m = 0, s = 0;
    
    printf("TIME: \n");
    while(1)
    {
        // Clear the screen
        system("clear");

        // Print time in HH:MM:SS format
        printf(" %02d : %02d : %02d\n", h, m, s);
        fflush(stdout);  // Ensure the output is immediately written

        // Increment seconds
        s++;
        if(s >= 60) {
            m++;
            s = 0;
        }

        if(m >= 60) {
            h++;
            m = 0;
        }

        if(h >= 2) break;  // Stop after 2 hours

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}
