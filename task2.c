
#include <stdio.h>
#include <pthread.h>

int numbers[6] = {1, 2, 3, 4, 5, 6};

void *calculate_sum(void *arg) {
    int id = *(int *)arg;
    int sum = 0;

    int start = id * 3;
    int end = start + 3;

    for (int i = start; i < end; i++) {
        sum += numbers[i];
    }

    printf("Thread %d sum: %d\n", id + 1, sum);

    return NULL;
}

int main() {
    pthread_t threads[2];
    int ids[2] = {0, 1};

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, calculate_sum, &ids[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
