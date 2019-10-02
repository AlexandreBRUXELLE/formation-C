
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <pthread.h>

void sing_printf(const char *format, ...){
    pthread_t self_id;
    self_id=pthread_self();
    va_list args;
    va_start(args, format);
    printf("@tid=%u :: ", (unsigned int)self_id);
    vprintf(format, args);
    va_end(args);
    return;
}

pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
int beer = 99;

void* drink_lots( ){

    do{
        pthread_mutex_lock(&beers_lock);

        sing_printf("%d bottles of beer on the wall, %d bottles of beer.\n", beer,  beer);

        beer = beer - 1 ;

        if (beer == 0)
            sing_printf("No more bottles of beer on the wall, no more bottles of beer.\n Go to the store and buy some more, 99 bottles of beer on the wall.\n");
        else
            sing_printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", beer);

        pthread_mutex_unlock(&beers_lock);

        usleep(250000);
    }while(beer > 0);

    return NULL;
}



int main() {

    pthread_t tBob, tDylan;
    void* result;

    if (pthread_create(&tBob, NULL, drink_lots, NULL) == -1 )
        printf("Can't create thread tBob");

    if (pthread_create(&tDylan, NULL, drink_lots, NULL) == -1 )
        printf("Can't create thread tB");

    if (pthread_join(tBob, &result) == -1 )
        printf("Can't join thread tBob");

    if (pthread_join(tDylan, &result) == -1 )
        printf("Can't join thread tDylan");

    return 0;
}