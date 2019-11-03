/*Implementare una rubrica telefonica seguendo le seguenti specifiche:

0) Definire una enumerazione 'TipologiaContatto' che permetta di utilizzare i seguenti valori: lavoro, famiglia, amici, altri. V
1) Definire una struttura 'Contatto' contenente:
- nome, cognome, numero di telefono, indirizzo email, tipologia contatto V
2) Implementare una funzione o procedura che acquisisca i campi di un Contatto e restituisca tale contatto.
 Effettuare i controlli sull'input:
- nome (non vuoto, non deve contenere cifre)
- cognome (non vuoto, non deve contenere cifre)
- numero di telefono (non vuoto, non deve contenere simboli o lettere)
- indirizzo email (deve contenere almeno un carattere prima della chiocciola, almeno un carattere chiocciola,
 almeno un carattere dopo la chiocchiola, un punto e un dominio come com o it)
- tipologia (deve essere richiesto in modo semplice per l'utente, ad esempio usando un menu)
3) Implementare una procedura che stampi in modo chiaro e ordinato tutti i dati del contatto
4) Implementare una funzione o procedura che permetta la modifica di un contatto. Riceverà come parametro un contatto,
 lo stamperà e chiederà quale campo deve essere modificato. Una volta inserito il nuovo valore,
 a seconda dei casi il contatto dovrà essere restituito al chiamante o meno (dipende se si utilizza una procedura o una funzione).
5) Implementare una funzione che inizializzi un vettore dinamico.
 Essa dovrà allocare lo spazio per un contatto e restituire l'indirizzo di memoria relativo se l'allocazione è andata a buon fine.
 Altrimenti il programma terminerà comunicando all'utente tale malfunzionamento.
6) Implementare la funzione di inserimento seguendo la logica seguente:
 passo il contatto, aumento lo spazio del vettore dinamico per contenere un nuovo elemento e a questo punto inserisco
 il nuovo contatto seguendo l'ordine alfabetico. Si possono presentare due casi: inserimento in coda, inserimento non in coda.
 Se in coda non dovremo far altro che inserire il contatto nell'ultima (e nuova) posizione,
 altrimenti una volta trovato il contatto successivo in ordine alfabetico dovremo far scorrere tutti i contatti di una posizione
 e inserire il nuovo contatto nella corretta posizione.
 Al termine delle operazioni ricordarsi di tenere traccia dell'eventuale cambio di valore del puntatore al vettore dinamico.
7) Implementare la funzione di eliminazione offrendo le seguenti possibilità:
- eliminare tutta la rubrica
- eliminare un contatto con un certo indice
- eliminare tutti i contatti con un certo nome o cognome
- elininare una categoria di contatti
        In tutti i casi dovremo sempre stare attenti a modificare lo spazio occupato dal vettore,
        se ad esempio abbiamo un vettore di 3 contatti A, B e C e dobbiamo eliminare B sposteremo C in B e riallocheremo lo spazio
        eliminando un elemento (l'ultimo). Ricordarsi sempre di restituire il puntatore al vettore dinamico.
8) Aggiungere alle funzionalità del programma la ricerca dei contatti offrendo le seguenti possibilità:
- ricerca mediante nome (o parte del nome)
- ricerca mediante cognome (o parte del cognome)
- ricerca mediante mail (o parte del mail)
- ricerca mediante numero
- ricerca mediante categoria*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30
#define DIM2 15
//definizione enumerazione
typedef enum {lavoro, Famiglia, Amici, Altri} TipologiaContatto;

//definizione struttura Contatto
typedef struct{
    char Nome[DIM+1];
    char Cognome[DIM+1];
    int  NumeroDiTelefono[DIM2+1];
    char IndirizzoEmail[DIM+1];
    TipologiaContatto Tipo;
} Contatto;

//Dichiarazione Procedure prima del main e dopo le direttive di pre-processing
void acquisizioneCampiContatto(Contatto);
void inserisciNome(Contatto);
void inserisciCognome(Contatto);
void inserisciNumero(Contatto);
void inserisciEmail(Contatto);
void inserisciTipo(Contatto);
void stampaContatto(Contatto);
void modificaContatto(Contatto);

int main(){

    printf("\nRubrica\n");
    Contatto persona;
    acquisizioneCampiContatto(persona);
    stampaContatto(persona);
    modificaContatto(persona);


return 0;
}

void acquisizioneCampiContatto (Contatto persona) {
    int i;

    printf("\nInserisci Nome:");
    scanf("%s", persona.Nome);
    getchar();

    for (i = 0; persona.Nome[i] != '\0'; i++) {
        while (persona.Nome[i] >= '0' && persona.Nome[i] <= '9' || persona.Nome[0] == ' '){
            printf("\nErrore, riprova:");
            scanf("%s", persona.Nome);
            getchar();
        }
    }
    printf("Inserisci Cognome:");
    scanf("%s", persona.Cognome);
    getchar();

    for (i = 0; persona.Cognome[i] != '\0'; i++) {
        while (persona.Cognome[i] >= '0' && persona.Cognome[i] <= '9' || persona.Cognome[0] == ' '){
            printf("\nErrore, riprova:");
            scanf("%s", persona.Cognome);
            getchar();
        }
    }

    printf("Inserisci Numero:");
    scanf("%[^\n]d", persona.NumeroDiTelefono);
    getchar();

    for (i = 0; persona.NumeroDiTelefono[i] != '\0'; i++) {
        while ((persona.NumeroDiTelefono[i] >= '0' && persona.NumeroDiTelefono[i] <= '9')){
            printf("\nErrore, riprova:");
            scanf("%d", persona.NumeroDiTelefono);
            getchar();
        }
    }

    printf("Inserisci Email:");
    scanf("%s", persona.IndirizzoEmail);
    getchar();

    for (i = 0; persona.IndirizzoEmail[i] != '\0'; i++) {
        while (persona.IndirizzoEmail [0] == '@'){
            printf("\nErrore, riprova:");
            scanf("%s", persona.IndirizzoEmail);
            getchar();
        }
    }

    printf("Tipo Contatto:[0=LAVORO, 1=FAMIGLIA, 2=AMICI, 3=ALTRI]");
    scanf("%d", &persona.Tipo);
    getchar();

    stampaContatto(persona);
}

void inserisciNome(Contatto persona){

    int i;

    printf("\nInserisci Nome:");
    scanf("%s", persona.Nome);
    getchar();

    for (i = 0; persona.Nome[i] != '\0'; i++) {
        while (persona.Nome[i] >= '0' && persona.Nome[i] <= '9' || persona.Nome[0] == ' ') {
            printf("\nErrore, riprova:");
            scanf("%s", persona.Nome);
            getchar();
        }
    }
}

void inserisciCognome(Contatto persona){
    int i;
    printf("Inserisci Cognome:");
    scanf("%s", persona.Cognome);
    getchar();

    for (i = 0; persona.Cognome[i] != '\0'; i++) {
        while (persona.Cognome[i] >= '0' && persona.Cognome[i] <= '9' || persona.Cognome[0] == ' ') {
            printf("\nErrore, riprova:");
            scanf("%s", persona.Cognome);
            getchar();
        }
    }

}

void inserisciNumero(Contatto persona){
    int i;
    printf("Inserisci Numero:");
    scanf("%[^\n]d", persona.NumeroDiTelefono);
    getchar();

    for (i = 0; persona.NumeroDiTelefono[i] != '\0'; i++) {
        while ((persona.NumeroDiTelefono[i] >= '0' && persona.NumeroDiTelefono[i] <= '9')){
            printf("\nErrore, riprova:");
            scanf("%d", persona.NumeroDiTelefono);
            getchar();
        }
    }


}

void inserisciEmail(Contatto persona){
    int i;
    printf("Inserisci Email:");
    scanf("%s", persona.IndirizzoEmail);
    getchar();

    for (i = 0; persona.IndirizzoEmail[i] != '\0'; i++) {
        while (persona.IndirizzoEmail [0] == '@'){
            printf("\nErrore, riprova:");
            scanf("%s", persona.IndirizzoEmail);
            getchar();
        }
    }

}

void inserisciTipo(Contatto persona){

    printf("Tipo Contatto:[0=LAVORO, 1=FAMIGLIA, 2=AMICI, 3=ALTRI]");
    scanf("%d", &persona.Tipo);
    getchar();

}

void stampaContatto(Contatto persona){
printf("\nNome: %s", persona.Nome);
printf("\nCognome: %s", persona.Cognome);
printf("\nNumero: %s", persona.NumeroDiTelefono);
printf("\nEmail: %s", persona.IndirizzoEmail);

switch (persona.Tipo){
case 0:
printf("\nLavoro\n");
break;
case 1:
printf("\nFamiglia\n");
break;
case 2:
printf("\nAmici\n");
break;
case 3:
printf("\nAltri\n");
break;
}

}

void modificaContatto(Contatto persona){
    acquisizioneCampiContatto(persona);
    int scelta;

    printf("\nModifica [1=Nome, 2=Cognome, 3=Numero, 4=Email, 5=Tipo]");
    scanf("%d", scelta);

    switch (scelta) {

        case 1:
            printf("\nModifica Nome:");
            inserisciNome(persona);
        case 2:
            printf("\nModifica Cognome:");
            inserisciCognome(persona);
        case 3:
            printf("\nModifica Numero:");
            inserisciNumero(persona);
        case 4:
            printf("\nInserisci Email:");
            inserisciEmail(persona);
        case 5:
            printf("\nModifica Tipo:");
            inserisciTipo(persona);

        default:
            printf("\nErrore. Digita un numero tra 1 e 5.");
    }


}



