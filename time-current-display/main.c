#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> // For sleep()

int main() {

    // Variable to store the current time in seconds since 1/1/1970 (Unix Epoch)
    time_t current_time_in_seconds;

    // Struct to store the formatted time (hours, minutes, seconds)
    struct tm* formatted_time;

    while(1){
        system("clear");

        // Get the current time in seconds since the Unix Epoch
        current_time_in_seconds = time(NULL);

        // Convert the time from seconds to a structured time in local timezone (hours, minutes, seconds)
        formatted_time = localtime(&current_time_in_seconds);

        // Print the current time in the format HH:MM:SS (Hours:Minutes:Seconds)
        printf("Current Time: %02d : %02d : %02d\n", 
            formatted_time->tm_hour,   // Hours
            formatted_time->tm_min,    // Minutes
            formatted_time->tm_sec);   // Seconds
        
        sleep(1);

    }

    return 0; // Return 0 to signal successful program completion
}
