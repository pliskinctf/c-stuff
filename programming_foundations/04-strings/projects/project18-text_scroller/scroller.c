#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    char og_string[] = "LOADING... ";
    size_t length = strlen(og_string);

    for (size_t i = 0; i < length; i++) {
        printf("\r%s", og_string + i);

        fflush(stdout);

        usleep(300000);
    }

    return 0;
}