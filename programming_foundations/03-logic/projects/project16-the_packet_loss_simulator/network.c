#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int send_packet() {
    return rand() % 2;  // 0 is success, 1 is failure
}

int main() {
    srand(time(NULL));

    for (int packet = 0; packet <= 10; packet++) {

        int retries = 0;

        while (1) {
            if (send_packet() == 0) {
                printf("packet %d sent successfully\n", packet);
                break;
            }

            retries++;
            printf("packet %d failed... retrying\n", packet);

            if (retries > 5) {
                printf("connection lost!\n");
                return 1;
            }
        }
    }

    return 0;
}
