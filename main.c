#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
    /*
    Scrivere un programma C in cui il processo padre crea un processo figlio tramite fork().
    Il figlio deve stampare a schermo i numeri da 1 a 5, con una pausa di 1 secondo tra ciascun numero.
    Il padre deve attendere che il figlio completi la propria esecuzione tramite wait(NULL)
    prima di iniziare a stampare i numeri da 6 a 10.
    */

    pid_t pid = fork();

    if (pid == -1) {
        perror("Errore fork");
        exit(1);
    }
    if (!pid) {
        for (int i = 0; i < 5; i++) {
            printf("[Figlio] %d\n", i);
            sleep(1);
        }
        exit(0);
    }
    wait(NULL);

    for (int i = 6; i <= 10; i++) {
        printf("[Padre] %d\n", i);
        sleep(1);
    }

    return 0;
}