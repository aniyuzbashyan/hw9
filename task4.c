
#include <stdio.h>
#include <pthread.h>

void *square(void *arg) {
    int num = *(int *)arg;
    int result = num * num;

    printf("Square of %d = %d\n", num, result);

    return NULL;
}

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    pthread_t t1, t2, t3, t4, t5;

    pthread_create(&t1, NULL, square, &numbers[0]);
    pthread_create(&t2, NULL, square, &numbers[1]);
    pthread_create(&t3, NULL, square, &numbers[2]);
    pthread_create(&t4, NULL, square, &numbers[3]);
    pthread_create(&t5, NULL, square, &numbers[4]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);

    printf("All calculations finished\n");

    return 0;
}
