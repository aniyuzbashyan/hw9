
#include <stdio.h>
#include <pthread.h>

void *print_numbers(void *arg) {
    int id = *(int *)arg;
    int number = 1;

    while (number <= 5) {
        printf("Thread %d prints: %d\n", id, number);
        number++;
    }

    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    int id1 = 1, id2 = 2, id3 = 3;

    pthread_create(&t1, NULL, print_numbers, &id1);
    pthread_create(&t2, NULL, print_numbers, &id2);
    pthread_create(&t3, NULL, print_numbers, &id3);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("All threads finished\n");

    return 0;
}
