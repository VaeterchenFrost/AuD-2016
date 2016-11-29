#include <stdio.h>
#include <stdlib.h>

typedef struct elem* list;
typedef struct elem {
    int value;
    list next;
} elem;

/*
Schreiben Sie ein C-Programm, welches den Nutzer zur Eingabe einer Zahl
n>=0 auffordert.
Ist n>=2, so sollen die Primfaktoren von n ausgegeben werden. F�r
n = 0 bzw. n = 1 soll keine Ausgabe erfolgen.
Beispiel: Ist n = 20, dann soll "2 2 5 " ausgegeben werden.
*/

list ListpotentialPrimeF(int n){
    // Return a connected list with
    // Prime Numbers p ; p*p<n
    list primlist, PtrPrim;
    primlist = (list) malloc(sizeof(elem));
    PtrPrim = primlist;
    PtrPrim -> value = 2;
    PtrPrim -> next = NULL;

    int i, j, p;
    for(i=3; i*i<=n; i+=2){// Von 3 bis Wurzel in 2er Schritten wird i auf P getestet.
        p=1; //Nehme P an.

        PtrPrim = primlist;
        if(PtrPrim){// Vorherige Primzahlen
            if(i % (PtrPrim->value) == 0){ //Teilbar:
                p=0;
                break;
            }
            PtrPrim=PtrPrim->next;
        }

        // Wenn ok eintragen
        if(p){
            //Gehe an Ende:
            PtrPrim = primlist;
            while(PtrPrim->next){PtrPrim=PtrPrim->next;}
            //Neuen Erstellen
            PtrPrim->next = (list) malloc(sizeof(elem));
            PtrPrim = PtrPrim -> next; //enter next
            PtrPrim->value = i;
            PtrPrim->next = NULL;
        }
    }

    return primlist;
}

void prtPFZ(list primlist, int n){
    int i=n, j;
    while(primlist){//Pr�fe Value
            j = primlist->value;
            if(i%j == 0){ //Teilbar
                printf("%d ", j);
                i /= j;
            }
            else{ //Nicht Teilbar -> n�chst gr��ere
                primlist=primlist->next;
            }
    }
    if(i>1){//Eine Groessere Primzahl enthalten:
        printf("%d ", i);
    }

}

int main()
{
    list primlist, PtrPrim;

    int i, j, p; // Counter
    int n; // Inputnumber

    do{
    printf("\n\nEnter a non-negative integer n: ('0'/'1' to continue)");
    scanf("%d", &n);

    if(n<0){return n;} //First Security

    if(n<2) continue; //Second Security

    primlist = ListpotentialPrimeF(n);

//    //TEST:
//    PtrPrim = primlist;
//    printf("\nPrimelist smaller Squareroot(n):\n");
//    while(PtrPrim){
//        printf("%d\n", PtrPrim->value);
//        PtrPrim = PtrPrim->next;
//    }

    //Ausgabe:
    printf("\nResult: %d\n", n);
    prtPFZ(primlist, n);
    }while(1);

    return 0;
}
