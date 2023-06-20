#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

sem_t *sem1, *sem2, *sem3, *sem4, *gesamtSem;

/*void *maschine1(void *arg) {
        sem_wait(sem1);
       // printf("Semaphor 1 wurde betreten.\n");
        printf("Bierflasche platziert.\n");

        sem_post(sem2);
       // printf("Semaphor 2 wurde verlassen.\n");
        sem_post(sem4);
        sem_wait(gesamtSem);
        //printf("Semaphor 4 wurde verlassen.\n");
        printf("Bierflasche Entfernen.\n");
        sem_post(gesamtSem);
        sem_post(sem1);
}*/

void *maschine1(void *arg) {
    while (1) {
        sem_wait(sem1);
        printf("Bierflasche platziert.\n");
        sem_post(sem2);
        sem_post(sem4);
        sem_wait(gesamtSem);
        printf("Bierflasche Entfernen.\n");
        sem_post(sem1);
        sem_post(sem3);  // Release sem3 after gesamtSem is posted
    }
}

void *maschine2(void *arg) {
    sem_wait(sem2);
    // printf("Semaphor 2 wurde betreten.\n");
    printf("Bierflasche abgefüllt.\n");
    sem_post(sem3);
    //printf("Semaphor 3 wurde verlassen.\n");
}

void *maschine3(void *arg) {
    sem_wait(sem3);
    // printf("Semaphor 3 wurde betreten.\n");
    printf("Bierflasche verschlossen.\n");
    sem_wait(gesamtSem);
    //printf("Semaphor gesamt wurde verlassen.\n");
}

void *maschine4(void *arg) {
    sem_wait(sem4);
    printf("Etikett geklebt.\n");
    sem_post(sem4);
}

void *stopProzess(void *arg){
    sleep(5);
    printf("Stoppen des Prozesses...\n");
    exit(0);
}

int main() {
    pthread_t t1, t2, t3, t4, t5;

    // Semaphoren erstellen
    sem1 = sem_open("/sem1", O_CREAT, 0644, 1);
    sem2 = sem_open("/sem2", O_CREAT, 0644, 0);
    sem3 = sem_open("/sem3", O_CREAT, 0644, 0);
    sem4 = sem_open("/sem4", O_CREAT, 0644, 0);
    gesamtSem = sem_open("/gesamtSem", O_CREAT, 0644, 0);

    //do{
    // Threads erstellen
    pthread_create(&t1, NULL, maschine1, NULL);
    pthread_create(&t2, NULL, maschine2, NULL);
    pthread_create(&t3, NULL, maschine3, NULL);
    pthread_create(&t4, NULL, maschine4, NULL);
    pthread_create(&t5, NULL, stopProzess, NULL);

    // Auf Beendigung der Threads warten
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    // }while(1);
    // Semaphoren schließen und löschen
    sem_close(sem1);
    sem_unlink("/sem1");
    sem_close(sem2);
    sem_unlink("/sem2");
    sem_close(sem3);
    sem_unlink("/sem3");
    sem_close(sem4);
    sem_unlink("/sem4");
    sem_close(gesamtSem);
    sem_unlink("/gesamtSem");
    return 0;
}