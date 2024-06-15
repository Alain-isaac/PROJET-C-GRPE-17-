
Voici comment ces représente le code qui concernent le LANCEMENT de notre application
 

Après avoir écrire la fonction qui va afficher le texte centre sur l’écran lors du démarrage   
Nous allons maintenant vous montrer le code principal de cette partie de lancement

 
Apres l’exécution de notre code voici ce qui s’affiche comme résultats :




 

Après 10 secondes, les noms vont disparaitre et l’écran d’accueil du jeu s’affichera 
Dans l’écran d’accueil nous trouvons un MENU qui est composer de démarrer, configurer ainsi que d’Aide. 
Voici comment l’écran d’accueil s’affiche par la suite :
 


Voici un programme en langage C qui implémente le jeu de vitesse de frappe pour deux joueurs. L'ordinateur propose des mots aléatoires que les joueurs doivent saisir et valider l'un après l'autre. Si un mot est incorrectement saisi, le joueur doit le retaper jusqu'à ce qu'il soit correct. À la fin du jeu, le programme affiche le temps de saisie des deux joueurs et indique lequel des joueurs est plus rapide.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 100
#define WORD_LIST_SIZE 10

const char* wordList[WORD_LIST_SIZE] = {
    "ordinateur", "clavier", "souris", "ecran", "programme", 
    "code", "compilation", "execution", "debug", "algorithme"
};

void getWordsFromPlayer(const char* playerName, int wordCount, const char** words) {
    char word[MAX_WORD_LENGTH];
    printf("%s, tapez les mots proposés aussi vite que possible:n", playerName);
    for (int i = 0; i < wordCount; i++) {
        printf("Mot %d: %sn", i + 1, words[i]);
        printf("Tapez le mot: ");
        scanf("%s", word);
        while (strcmp(word, words[i]) != 0) {
            printf("Incorrect. Essayez encore: ");
            scanf("%s", word);
        }
    }
}

int main() {
    int wordCount;
    char player1[50], player2[50];

    printf("Bienvenue dans le jeu de vitesse de frappe !n");
    printf("Entrez le nombre de mots à saisir dans la partie: ");
    scanf("%d", &wordCount);

    printf("Entrez le pseudo du joueur 1: ");
    scanf("%s", player1);
    printf("Entrez le pseudo du joueur 2: ");
    scanf("%s", player2);

    // Générer des mots aléatoires
    srand(time(NULL));
    const char* words[wordCount];
    for (int i = 0; i < wordCount; i++) {
        words[i] = wordList[rand() % WORD_LIST_SIZE];
    }

    printf("nLe jeu commence maintenant !n");

    clock_t start, end;
    double timeTakenPlayer1, timeTakenPlayer2;

    // Joueur 1
    start = clock();
    getWordsFromPlayer(player1, wordCount, words);
    end = clock();
    timeTakenPlayer1 = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Joueur 2
    start = clock();
    getWordsFromPlayer(player2, wordCount, words);
    end = clock();
    timeTakenPlayer2 = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("nTemps pris par %s: %.2f secondesn", player1, timeTakenPlayer1);
    printf("Temps pris par %s: %.2f secondesn", player2, timeTakenPlayer2);

    if (timeTakenPlayer1 < timeTakenPlayer2) {
        printf("%s a gagné !n", player1);
    } else if (timeTakenPlayer1 > timeTakenPlayer2) {
        printf("%s a gagné !n", player2);
    } else {
        printf("C'est une égalité !n");
    }

    return 0;
}


### Explications :

1. Déclarations et initialisations :
   - Le programme commence par inclure les bibliothèques nécessaires et définir quelques constantes.
   - Une liste de mots (wordList) est définie pour être utilisée dans le jeu.

2. Fonction getWordsFromPlayer :
   - Cette fonction prend en entrée le nom du joueur, le nombre de mots à saisir, et un tableau de mots.
   - Elle affiche chaque mot et demande au joueur de le saisir. Si le mot saisi est incorrect, elle redemande jusqu'à ce que le mot soit correct.

3. Fonction main :
   - Le programme demande le nombre de mots à saisir et les pseudos des joueurs.
   - Il génère des mots aléatoires à partir de la liste de mots.
   - Il chronomètre le temps que chaque joueur met à saisir les mots en utilisant les fonctions clock(), Start, et end.
   - Les temps pris par chaque joueur sont affichés.
   - Le programme détermine et affiche le gagnant en fonction du temps pris par chaque joueur.

Compilez et exécutez ce programme pour jouer au jeu de vitesse de frappe avec deux joueurs.




				MENU CONFIGURER


 
Ces bibliothèques standard fournissent les fonctions nécessaires pour les entrées/sorties, la gestion de la mémoire et la manipulation des chaînes de caractères

 
MAX_WORD_LENGTH` : définit la longueur maximale d’un mot. - `FILENAME` : nom du fichier où les mots seront stockés.


 
Cette fonction affiche le menu principal du programme.






 
Cette fonction permet d’ajouter un mot à la base de données en l’écrivant dans le fichier.



 
Cette fonction lit et affiche tous les mots stockés dans le fichier


 

Cette fonction permet de supprimer un mot en créant un fichier temporaire sans le mot à supprimer, puis en remplaçant le fichier original par ce fichier temporaire





Synthèse du Programme de Gestion de Base de Données :
 Ce programme en langage permet de gérer une base de données de mots via un menu interactif. Il offre les fonctionnalités suivantes :
 1. Ajouter un mot : L’utilisateur peut ajouter un mot à la base de données, qui est stockée dans un fichier texte. 
2. Afficher tous les mots : Le programme lit et affiche tous les mots présents dans le fichier.
 3. Supprimer un mot : L’utilisateur peut supprimer un mot spécifique de la base de données. Le programme crée un fichier temporaire sans le mot à supprimer, puis remplace le fichier original.
 4. Rechercher un mot : Le programme permet de rechercher un mot spécifique dans la base de données et affiche s’il est trouvé. 
5. Quitter : L’utilisateur peut quitter le programme. Le programme utilise des fonctions pour chaque fonctionnalité et gère l’interaction utilisateur via un menu affiché en boucle. 









