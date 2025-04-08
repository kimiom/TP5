#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud* precedent;
    struct Noeud* suivant;
} Noeud;

Noeud* creerNoeud(int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (!nouveau) return NULL;
    nouveau->valeur = valeur;
    nouveau->precedent = NULL;
    nouveau->suivant = NULL;
    return nouveau;
}

Noeud* insererDebut(Noeud* tete, int valeur) {
    Noeud* nouveau = creerNoeud(valeur);
    if (!nouveau) return tete;
    if (tete != NULL) {
        nouveau->suivant = tete;
        tete->precedent = nouveau;
    }
    return nouveau;
}

void afficherAvant(Noeud* tete) {
    Noeud* temp = tete;
    printf("Liste : ");
    while (temp != NULL) {
        printf("%d <-> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

void insererFIN(Noeud ** tete, int val)
{
    Noeud *NV = creerNoeud(val);
    if (*tete == NULL)
    *tete =NV;
    Noeud * courant = *tete;
    while (courant->suivant != NULL)
    courant = courant->suivant;
    courant->suivant= NV;
    NV->precedent = courant;

}

int main() {
    Noeud* liste = NULL;
    liste = insererDebut(liste, 10);
    liste = insererDebut(liste, 20);
    liste = insererDebut(liste, 30);
insererFIN(&liste,100);
    afficherAvant(liste);

    return 0;
}
