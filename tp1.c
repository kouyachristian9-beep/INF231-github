#include <stdio.h>
#include <stdlib.h>

void somme_matrices();
void produit_matrices();
void recherche_sequentielle();
void multiplication_par_plus_un();
void tester_tableau_trie();
void mediane_tableau();
void inverser_tableau();
void produit_vectoriel();
void produit_vecteur_matrice();

int main() {
    int choix;

    do {
        printf("Choisissez une opération:\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche séquentielle dans un tableau\n");
        printf("4. a × b pour a, b > 0 en utilisant exclusivement +1\n");
        printf("5. Tester si un tableau est trié\n");
        printf("6. Trouver la médiane dans un tableau\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel\n");
        printf("9. Produit vecteur × matrice\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: somme_matrices(); break;
            case 2: produit_matrices(); break;
            case 3: recherche_sequentielle(); break;
            case 4: multiplication_par_plus_un(); break;
            case 5: tester_tableau_trie(); break;
            case 6: mediane_tableau(); break;
            case 7: inverser_tableau(); break;
            case 8: produit_vectoriel(); break;
            case 9: produit_vecteur_matrice(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}

void somme_matrices() {
    int i, j;
    int a[10][10], b[10][10], somme[10][10];
    int lignes, colonnes;

    printf("Entrez le nombre de lignes et de colonnes: ");
    scanf("%d %d", &lignes, &colonnes);

    printf("Entrez les éléments de la première matrice:\n");
    for (i = 0; i < lignes; i++)
        for (j = 0; j < colonnes; j++)
            scanf("%d", &a[i][j]);

    printf("Entrez les éléments de la seconde matrice:\n");
    for (i = 0; i < lignes; i++)
        for (j = 0; j < colonnes; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < lignes; i++)
        for (j = 0; j < colonnes; j++)
            somme[i][j] = a[i][j] + b[i][j];

    printf("La somme des matrices est:\n");
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++)
            printf("%d ", somme[i][j]);
        printf("\n");
    }
}

void produit_matrices() {
    int i, j, k;
    int a[10][10], b[10][10], produit[10][10];
    int lignes_a, colonnes_a, lignes_b, colonnes_b;

    printf("Entrez le nombre de lignes et colonnes de la première matrice: ");
    scanf("%d %d", &lignes_a, &colonnes_a);
    printf("Entrez le nombre de lignes et colonnes de la seconde matrice: ");
    scanf("%d %d", &lignes_b, &colonnes_b);

    if (colonnes_a != lignes_b) {
        printf("Erreur: Les matrices ne peuvent pas être multipliées.\n");
        return;
    }

    printf("Entrez les éléments de la première matrice:\n");
    for (i = 0; i < lignes_a; i++)
        for (j = 0; j < colonnes_a; j++)
            scanf("%d", &a[i][j]);

    printf("Entrez les éléments de la seconde matrice:\n");
    for (i = 0; i < lignes_b; i++)
        for (j = 0; j < colonnes_b; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < lignes_a; i++)
        for (j = 0; j < colonnes_b; j++) {
            produit[i][j] = 0;
            for (k = 0; k < colonnes_a; k++)
                produit[i][j] += a[i][k] * b[k][j];
        }

    printf("Le produit des matrices est:\n");
    for (i = 0; i < lignes_a; i++) {
        for (j = 0; j < colonnes_b; j++)
            printf("%d ", produit[i][j]);
        printf("\n");
    }
}

void recherche_sequentielle() {
    int i, n, x;
    int tableau[100];

    printf("Entrez le nombre d'éléments dans le tableau: ");
    scanf("%d", &n);
    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &tableau[i]);

    printf("Entrez l'élément à rechercher: ");
    scanf("%d", &x);

    for (i = 0; i < n; i++) {
        if (tableau[i] == x) {
            printf("Élément trouvé à l'indice %d.\n", i);
            return;
        }
    }
    printf("Élément non trouvé.\n");
}

void multiplication_par_plus_un() {
    int a, b, resultat = 0;

    printf("Entrez deux nombres positifs a et b: ");
    scanf("%d %d", &a, &b);

    for (int i = 0; i < b; i++) {
        resultat++;
    }
    for (int i = 0; i < a - 1; i++) {
        resultat += b;
    }

    printf("Le produit de %d et %d est: %d\n", a, b, resultat);
}

void tester_tableau_trie() {
    int n, i, est_trie = 1;
    int tableau[100];

    printf("Entrez le nombre d'éléments dans le tableau: ");
    scanf("%d", &n);
    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &tableau[i]);

    for (i = 1; i < n; i++) {
        if (tableau[i] < tableau[i - 1]) {
            est_trie = 0;
            break;
        }
    }

    if (est_trie)
        printf("Le tableau est trié.\n");
    else
        printf("Le tableau n'est pas trié.\n");
}

void mediane_tableau() {
    int n, i;
    float mediane;
    int tableau[100];

    printf("Entrez le nombre d'éléments dans le tableau: ");
    scanf("%d", &n);
    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &tableau[i]);

    // Tri du tableau
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tableau[i] > tableau[j]) {
                int temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }

    if (n % 2 == 0)
        mediane = (tableau[n / 2 - 1] + tableau[n / 2]) / 2.0;
    else
        mediane = tableau[n / 2];

    printf("La médiane est: %.2f\n", mediane);
}

void inverser_tableau() {
    int n, i;
    int tableau[100];

    printf("Entrez le nombre d'éléments dans le tableau: ");
    scanf("%d", &n);
    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &tableau[i]);

    printf("Tableau inversé:\n");
    for (i = n - 1; i >= 0; i--)
        printf("%d ", tableau[i]);
    printf("\n");
}

void produit_vectoriel() {
    float a[3], b[3], produit[3];

    printf("Entrez les éléments du premier vecteur (x, y, z): ");
    scanf("%f %f %f", &a[0], &a[1], &a[2]);
    printf("Entrez les éléments du second vecteur (x, y, z): ");
    scanf("%f %f %f", &b[0], &b[1], &b[2]);

    produit[0] = a[1] * b[2] - a[2] * b[1];
    produit[1] = a[2] * b[0] - a[0] * b[2];
    produit[2] = a[0] * b[1] - a[1] * b[0];

    printf("Le produit vectoriel est: (%.2f, %.2f, %.2f)\n", produit[0], produit[1], produit[2]);
}

void produit_vecteur_matrice() {
    int i, j, colonnes;
    float vecteur[10], matrice[10][10], produit[10] = {0};
    int lignes;

    printf("Entrez le nombre de lignes de la matrice: ");
    scanf("%d", &lignes);
    printf("Entrez le nombre de colonnes de la matrice: ");
    scanf("%d", &colonnes);

    printf("Entrez les éléments du vecteur:\n");
    for (i = 0; i < colonnes; i++)
        scanf("%f", &vecteur[i]);

    printf("Entrez les éléments de la matrice:\n");
    for (i = 0; i < lignes; i++)
        for (j = 0; j < colonnes; j++)
            scanf("%f", &matrice[i][j]);

    for (i = 0; i < lignes; i++)
        for (j = 0; j < colonnes; j++)
            produit[i] += vecteur[j] * matrice[i][j];

    printf("Le produit du vecteur et de la matrice est:\n");
    for (i = 0; i < lignes; i++)
        printf("%.2f ", produit[i]);
    printf("\n");
}