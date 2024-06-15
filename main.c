
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOTS 100
#define MAX_REPONSE 50
#define MAX_JOUEURS 2
#define MAX_WORD_LENGTH 100
#define WORD_LIST_SIZE 10
#define MAX_WORD_LENGTH 100
#define FILENAME "database.txt"

const char* wordList[WORD_LIST_SIZE] = {
    "ordinateur", "clavier", "souris", "ecran", "programme",
    "code", "compilation", "execution", "debug", "algorithme"
};


void clearScreen(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif // _WIN32
}

struct mot {
    char *mots;
    struct mot *suivant;
};

struct joueur {
    char *pseudo;
    struct mot *mots;
    struct joueur *suivant;
};

void display_welcome_screen() {
    printf("                                 ||=======================================================||\n");
    printf("                                 ||======================||UDBL - DACTYLOGICIEL||=========||\n");
    printf("                                 ||=======================================================||\n");
    printf("                                 ===========================================================\n");

    printf("                                 ||:::::::::::::::::::::||Nom de l'equipe||::::::::::::::::||");


    printf("\t\t\t\t\t\t\t\t\t\tMUMBA KISALA JOHN\n");
    printf("\t\t\t\t\t\t\tSAIDI ISAAC ALAIN\n");
    printf("\t\t\t\t\t\t\tSABU SABU AGABUS\n");
    printf("\t\t\t\t\t\t\tSANDE KUYELA SAAMMY\n");


    sleep(10);
    clearScreen();
}

void display_menu() {

    printf("\t\t\t\t\t\t\tEcran d'accueil\n");

    printf("========MENU PRINCIPALE=======\n");
    printf("\t1. Demarrer\n");
    printf("\t2. Configurer\n");
    printf("\t3. Aide\n");
    printf("\t4. Quitter\n");
    printf("\tSelectionnez une option : \n");
}

void display_help() {
    // Ajouter le code pour afficher les informations sur l'application
    printf("\nAide :\n");
    printf("Description de l'application : ...\n");
    printf("Version du jeu : 1.0\n");
    printf("Concepteurs : John,Alain,Agabus,Sammy\n");
    printf("Date de conception : 01/01/2022\n");

}

//void configure() {
    // Ajouter le code pour remplir la base de données avec les mots

// Fonction pour afficher le menu

void displayMenu() {
    printf("\n=== Menu Configurer ===\n\n\n");
    printf("1. Ajouter un mot à la base de données\n\n");
    printf("2. Afficher tous les mots\n\n");
    printf("3. Supprimer un mot\n\n");
    printf("4. Rechercher un mot\n\n");
    printf("5. Quitter\n\n");
}

// Fonction pour ajouter un mot à la base de données
void addWord() {
    char word[MAX_WORD_LENGTH];
    FILE *file = fopen(FILENAME, "a"); // Ouvre le fichier en mode ajout

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("Entrez le mot à ajouter: ");
    scanf("%s", word); // Lit le mot entré par l'utilisateur

    fprintf(file, "%s\n", word); // Écrit le mot dans le fichier
    fclose(file); // Ferme le fichier

    printf("Mot ajouté avec succès.\n");
}

// Fonction pour afficher tous les mots de la base de données
void displayWords() {
    char word[MAX_WORD_LENGTH];
    FILE *file = fopen(FILENAME, "r"); // Ouvre le fichier en mode lecture

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("\nMots dans la base de données:\n");
    while (fgets(word, MAX_WORD_LENGTH, file) != NULL) {
        printf("%s", word); // Affiche chaque mot
    }
    fclose(file); // Ferme le fichier
}

// Fonction pour supprimer un mot de la base de données
void deleteWord() {
    char word[MAX_WORD_LENGTH];
    char tempFileName[] = "temp.txt";
    FILE *file = fopen(FILENAME, "r"); // Ouvre le fichier en mode lecture
    FILE *tempFile = fopen(tempFileName, "w"); // Ouvre un fichier temporaire en mode écriture

    if (file == NULL || tempFile == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("Entrez le mot à supprimer: ");
    scanf("%s", word); // Lit le mot entré par l'utilisateur

    char line[MAX_WORD_LENGTH];
    int found = 0;
    while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
        if (strstr(line, word) == NULL) {
            fputs(line, tempFile); // Écrit les lignes qui ne contiennent pas le mot dans le fichier temporaire
        } else {
            found = 1;
        }
    }
    fclose(file); // Ferme le fichier original
    fclose(tempFile); // Ferme le fichier temporaire

    remove(FILENAME); // Supprime le fichier original
    rename(tempFileName, FILENAME); // Renomme le fichier temporaire

    if (found) {
        printf("Mot supprimé avec succès.\n");
    } else {
        printf("Mot non trouvé.\n");
    }
}

// Fonction pour rechercher un mot dans la base de données
void searchWord() {
    char word[MAX_WORD_LENGTH];
    FILE *file = fopen(FILENAME, "r"); // Ouvre le fichier en mode lecture

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("Entrez le mot à rechercher: ");
    scanf("%s", word); // Lit le mot entré par l'utilisateur

    char line[MAX_WORD_LENGTH];
    int found = 0;
    while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
        if (strstr(line, word) != NULL) {
            printf("Mot trouvé: %s", line); // Affiche le mot trouvé
            found = 1;
        }
    }
    fclose(file); // Ferme le fichier

    if (!found) {
        printf("Mot non trouvé.\n");
    }



    int choice;

    while (1) {
        displayMenu(); // Affiche le menu
        printf("Choisissez une option: ");
        scanf("%d", &choice); // Lit le choix de l'utilisateur

        switch (choice) {
            case 1:
                addWord(); // Appelle la fonction pour ajouter un mot
                break;
            case 2:
                displayWords(); // Appelle la fonction pour afficher tous les mots
                break;
            case 3:
                deleteWord(); // Appelle la fonction pour supprimer un mot
                break;
                            case 4:
                searchWord(); // Appelle la fonction pour rechercher un mot
                break;
            case 5:
                printf("Au revoir!\n");
                exit(0); // Quitte le programme
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

}

void start_game() {
    srand(time(NULL));
    struct joueur *joueur[MAX_JOUEURS];
    struct mot *mots[MAX_MOTS];
    int nb_mots, nb_joueurs, i, j;
    char *pseudo;
    char *reponse;
    struct mot *temp_mots;
    struct joueur *temp_joueur;

    printf("\tCombien de mots voulez-vous pour ce jeu ? ");
    scanf("%d", &nb_mots);

    printf("\tEntrez le nombre de joueurs : ");
    scanf("%d", &nb_joueurs);

    for (i = 0; i < nb_joueurs; i++) {
        printf("\tEntrez le pseudo du joueur %d : ", i + 1);
        scanf("%s", pseudo);
    }
}

void demarrerJeu() {
    int nbMots;
    char pseudoJoueur1[50], pseudoJoueur2[50];

    printf("\nNombre de mots a saisir dans la partie : ");
    scanf("%d", &nbMots);

    printf("Pseudo du joueur 1 : ");
    scanf("%s", pseudoJoueur1);

    printf("Pseudo du joueur 2 : ");
    scanf("%s", pseudoJoueur2);
    printf("le jeu commence maintenant ");

    for (int i = 0; i < nbMots;) {
        char motAttendu[50],motSaisiJoueur1[50], motSaisiJoueur2[50];
        printf("Mot à saissir: %s\n",motAttendu);

        printf("%s, saisissez le Mot : ",pseudoJoueur1 );
        scanf("%s",motSaisiJoueur1 );

        printf("%s, saisissez le Mot : ", pseudoJoueur2 );
        scanf("%s", motSaisiJoueur2);


          }
}


                // Mettre à jour les statistiques du joueur

                //printf("");
                // Mettre à jour les statistiques du joueur



    // Calculer les statistiques et afficher le gagnant


int main() {
    int option;

    display_welcome_screen();

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                start_game();
                break;
            case 2:
                displayMenu();
                break;
            case 3:
                display_help();
                break;
            case 4:
                printf("\n\\tA bientot !\\");
                return 0;
            default:
                printf("\\tOption invalide Veuillez reessayer \\");
        }
    }

return 0;
}
