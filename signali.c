#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void obradi_dogadjaj(int sig);
void obradi_sigterm(int sig);
void obradi_sigint(int sig);
void obradi_signal1(int sig);

int trenutni_prekid = 0;
int zastavica1 = 0;
int zastavica2 = 0;
int zastavica3 = 0;


int nije_kraj = 1;

int main()
{
 struct sigaction act;

act.sa_handler = obradi_dogadjaj; //signal broj 4
sigaction(SIGUSR1, &act, NULL); 

act.sa_handler = obradi_sigterm; //signal broj 3
sigaction(SIGTERM, &act, NULL);

act.sa_handler = obradi_sigint; //signal broj 2
sigaction(SIGINT, &act, NULL);

act.sa_handler = obradi_signal1; //obradi signal 1
sigaction(SIGUSR2, &act, NULL);

 printf("Program s PID=%ld krenuo s radom\n", (long) getpid());

 int i = 1;
 while(nije_kraj) {
 printf("Program: iteracija %d\n", i++);
 sleep(1);
 }
 printf("Program s PID=%ld zavrsio s radom\n", (long) getpid());
 return 0;
}


void obradi_dogadjaj(int sig)
{
 int i;
 trenutni_prekid = 4;

 printf("Pocetak obrade signala 4\n");

 for (i = 1; i <= 20; i++) {
    printf("Obrada signala 4: %d/20\n", i);
    printf("Stanje stoga: %d%d%d\n",zastavica1,zastavica2,zastavica3);
    sleep(1);
 }

 printf("Kraj obrade signala 4\n");
 
 
 trenutni_prekid = 0;

 if(zastavica3 == 1){
    obradi_sigterm(SIGTERM);
 }

 if(zastavica2 == 1) {
    obradi_sigint(SIGINT);
 }

 if(zastavica1 == 1){
    obradi_signal1(SIGUSR2);
 }
 

}


void obradi_sigterm(int sig)
{
 int i;

if(trenutni_prekid > 3) {
    zastavica3 = 1;
    printf("Pojavio se prekid razine 3, ali on se ne obraduje te se pamti\n");
    return;
 }
else{ 

    trenutni_prekid = 3;
    zastavica3 = 0;

    printf("Pocetak obrade signala 3\n");

    for (i = 1; i <= 20; i++) {
        printf("Obrada signala 3: %d/20\n", i);
        printf("Stanje stoga: %d%d%d\n",zastavica1,zastavica2,zastavica3);
        sleep(1);
    }

    printf("Kraj obrade signala 3\n");

    trenutni_prekid = 0;
    //zastavica3 = 0;

    if(zastavica2 == 1) {
        obradi_sigint(SIGINT);
    }

    if(zastavica1 == 1){
        obradi_signal1(SIGUSR2);
    }

}
}


void obradi_sigint(int sig)
{
 int i;

if(trenutni_prekid > 2) {
    zastavica2 = 1;
    printf("Pojavio se prekid razine 2, ali on se ne obraduje te se pamti\n");
    return;
 }
else{ 

    trenutni_prekid = 2;
    zastavica2 = 0;

    printf("Pocetak obrade signala 2\n");

    for (i = 1; i <= 20; i++) {
        printf("Obrada signala 2: %d/20\n", i);
        printf("Stanje stoga: %d%d%d\n",zastavica1,zastavica2,zastavica3);
        sleep(1);
    }

        printf("Kraj obrade signala 2\n");

    trenutni_prekid = 0;
    //zastavica2 = 0;

    if(zastavica1 == 1){
        obradi_signal1(SIGUSR2);
    }

}
}


void obradi_signal1(int sig) {
int i;

if(trenutni_prekid > 1) {
    zastavica1 = 1;
    printf("Pojavio se prekid razine 1, ali on se ne obraduje te se pamti\n");
    return;
 }
else{ 

    trenutni_prekid = 1;
    zastavica1 = 0;

    printf("Pocetak obrade signala 1\n");

    for (i = 1; i <= 20; i++) {
        printf("Obrada signala 1: %d/20\n", i);
        printf("Stanje stoga: %d%d%d\n",zastavica1,zastavica2,zastavica3);
        sleep(1);
    }

    printf("Kraj obrade signala 1\n");

    trenutni_prekid = 0;
    //zastavica1 = 0;
}
}