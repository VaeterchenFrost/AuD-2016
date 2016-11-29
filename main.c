#include <stdio.h>
#include <stdlib.h>

typedef struct elem* list;
typedef struct elem {
    int value;
    list next;
} elem;

typedef struct node* tree;
typedef struct node {
    int value;
    tree left, right;
} node;

void histogram(list l, int h[], int length){
    // GO through list keys while next not Null
    int v, i;
    // Genutzte auf 0 Setzen:
    for(i=0;i<length;i++){
        h[i] = 0;
    }
    do{
        // change h[i] by one
        v = l->value;
        printf("\n%d, %d ", v,l->next);
        if(v < length && v >=0 ){
            h[v] += 1;
        }
        l = l->next;
    }while(l->next != NULL);
}

int isPath(list l, tree t){
    //RETURN:
    // 1 if tree contains given Path in list
    // 0 if tree does not.^^
    // Every "valid" Path contains the root element.


    //Root Element
    if(! (l->value == t->value)){
            //Return because no match at root
        return 0;
    }
    while(l->next){ // Pointer not NULL
        l = l->next;//Search for next equality
        if(t->left){
            if(t->left->value == l->value){
                // Go there
                t = t->left;
                continue;
            }
        }
        if(t->right){
            if(t->right->value == l->value){
                //Go There
                t = t->right;
                continue;
            }
        }
        // Not found
        return 0;
    }
    // Everything found:
    return 1;

}

int main(int argc, char* argv[])
{
//_______________________________________________________
// a)
/*
    int n;
    int n_gc = 0;
    int n_uc = 0;

    while(1){
        scanf("%d", &n);

        // Break if 0 entered:
        if(!n){printf(" Break. "); break;
              }

        printf( "\nYou entered:  %d \n", n);

        if(n%2){
            n_uc ++;
        }
        else{
            n_gc ++;
        }
    }
    printf( "\nYou entered:  %d even numbers", n_gc);
    printf( "\nYou entered:  %d odd numbers \n", n_uc);
    */
//_______________________________________________________
// b)
/*
    // CREATE LIST
    list lp, h, nel;
    h = (list) malloc(sizeof(elem)); // Save Head-Pointer
    lp = h;
    printf("OK.");

    for(int i=0;i<10;i++){
        nel = (list) malloc(sizeof(elem)); // Create next
        lp->value = (i*11)%13; // Save Value
        lp->next = nel; // Save Next
        lp = nel; // Set to next
        printf(" %d ", i);
    }
    lp->value = 0;
    lp->next = NULL;

    // LIST h READY. Create Array:
    int ar[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};

    // output each array element's value
    for (int j = 0; j < 13; j++ ) {
      printf("\nPre Element[%d] = %d", j, ar[j] );
    }

    histogram(h, ar, 13);

    // output each array element's value
    for (int j = 0; j < 13; j++ ) {
      printf("\nElement[%d] = %d", j, ar[j] );
    }
*/
//_______________________________________________________
// c)
    // CREATE LIST
    list h, lp, nel;
    h = (list) malloc(sizeof(elem)); // Save Head-Pointer
    lp = h;
    printf("OK.");

    for(int i=0;i<10;i++){
        nel = (list) malloc(sizeof(elem)); // Create next
        lp->value = (i*11)%13; // Save Value
        lp->next = nel; // Save Next
        lp = nel; // Set to next
        printf(" %d ", i);
    }
    lp->value = 0;
    lp->next = NULL;
    //List Created

    tree treeh, ndPtr, childPtr;
    treeh = (tree) malloc(sizeof(node));
    treeh->value=0;
    treeh->left=0;
    treeh->right=0;
    ndPtr = treeh; //First Node
    int nodecount = 10
    for(int i=0;i<nodecount;i++){
        childPtr = (tree) malloc(sizeof(node));
        childPtr->value = i;
        //TODO: Einhaengen:

    }


    return 0;
}


