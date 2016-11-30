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


list createlist(int ar[], int len){
    if(ar == NULL){
        // Example handling of this error. Writing a message to stderr, and
        // exiting with failure.
        //
        fprintf(stderr, "ZeroPointer in createlist()...\n");
        exit(EXIT_FAILURE); /* indicate failure.*/;;
    } //No List
    // At least one element
    // :


    list head, PtrNew, PtrLast;

    head = (list) malloc(sizeof(elem)); // Save Head-Pointer
    head->next=NULL;
    head->value=ar[0];

    PtrLast = head;

    for(int i=1; i<len; i++){ //Children
        PtrNew = (list) malloc(sizeof(elem));
        PtrNew->value = ar[i];
        PtrNew->next = NULL;
        PtrLast->next = PtrNew;
        PtrLast=PtrNew;

    }
    return head;
}

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

    if(l==0 || t==0){
        // Example handling of this error. Writing a message to stderr, and
        // exiting with failure.
        //
        fprintf(stderr, "ZeroPointer in isPath()...\n");
        exit(EXIT_FAILURE); /* indicate failure.*/;
    }
    //Root Element
    if(l->value != t->value){
        //Return because no match at root
        return 0;
    }
    while(l->next){ // Pointer not NULL
        l = l->next;// Next List Element:
        if(t->left){// Left branch?
            if(t->left->value == l->value){
                // Go there
                t = t->left;
                continue;
            }
        }
        if(t->right){// Right branch?
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
    list h;


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
    tree treeh;
    treeh = (tree) malloc(sizeof(node));
    treeh->value=0;
    treeh->left=0;
    treeh->right=0;

    int nodecount = 14;
    tree trlist[nodecount];
    trlist[0] = treeh;

    for(int i=1;i<nodecount;i++){//Trage Children in Baum ein:
        trlist[i] = (tree) malloc(sizeof(node));
        trlist[i]->value = i;
        trlist[i]->left = NULL;
        trlist[i]->right= NULL;

        //Einhaengen:
        //n verbunden in (n+1)/2-1 an Left<=>n%2 True
        if(i%2)
            {trlist[(i+1)/2-1]->left = trlist[i];} //Links
        else{trlist[(i+1)/2-1]->right = trlist[i];}//Rechts
    }

    {int l[]={0};
    printf("a %d\n", isPath(createlist(l, 1), treeh));}
    {int l[]={2};
    printf("b %d\n", isPath(createlist(l, 1), treeh));}
    {int l[] = {0,1,3,7};
    printf("c %d\n", isPath(createlist(l, 4), treeh));}
    {int l[] = {0,1,4,10};
    printf("d %d\n", isPath(createlist(l, 4), treeh));}
    {int l[] = {0,2,6,7};
    printf("e %d\n", isPath(createlist(l, 4), treeh));}
    {int l[] = {0,2,6,13};
    printf("f %d\n", isPath(createlist(l, 4), treeh));}


    return 0;
}


