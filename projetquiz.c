#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct projetquiz{
    char question[40][100];   
    char choix[40][3][20];
    int reponse[40];
} ProjetQuiz;

int main(void){
    ProjetQuiz quiz = {
        {
        "Combien font 10 + 2000",
        "Quelle est la capitale de Madagascar",
        "Quelle est la capitale de la france",
        "Combien font 5 + 7 ?",
        "Quelle est la couleur du ciel ?",
        "Quel langage utilise l'extension .c ?",
        "Combien y a-t-il de continents ?",
        "Quelle est la planete la plus proche du Soleil ?",
        "Combien font 10 * 10 ?",
        "Quel est le plus grand ocean du monde ?",
        "Combien de cotes possede un triangle ?",
        "Quelle est la capitale de l'Allemagne ?",
        "Combien font 100 / 4 ?",
        "Quel animal est appele le roi de la jungle ?",
        "Combien de jours y a-t-il dans une semaine ?",
        "Quel est le plus grand continent du monde ?",
        "Combien font 9 + 8 ?",
        "Quelle est la capitale de l'Italie ?",
        "Quel est le symbole chimique de l'eau ?",
        "Combien de pattes possede une araignee ?",
        /* AJOUT : 20 questions supplementaires */
        "Combien font 8 * 7 ?",
        "Quelle est la capitale de l'Espagne ?",
        "Combien de minutes y a-t-il dans une heure ?",
        "Quel est le plus long fleuve d'Afrique ?",
        "Quelle planete est appelee la planete rouge ?",
        "Combien de lettres y a-t-il dans l'alphabet ?",
        "Combien font 15 - 6 ?",
        "Quelle est la capitale du Japon ?",
        "Quel est le plus grand animal terrestre ?",
        "Combien de mois y a-t-il dans une annee ?",
        "Quel metal est liquide a temperature ambiante ?",
        "Combien font 3 * 9 ?",
        "Quelle est la capitale du Canada ?",
        "Quel est le plus petit nombre premier ?",
        "Combien de joueurs y a-t-il sur le terrain dans une equipe de football ?",
        "Quelle est la capitale du Portugal ?",
        "Quel gaz les plantes absorbent-elles ?",
        "Combien font 144 / 12 ?",
        "Quel ocean est situe entre l'Afrique et l'Australie ?",
        "Combien font 2 puissance 5 ?"
        },
        {
        {"2015", "2010", "2013"},
        {"Antsiranana", "Fianarantsoa", "Antananarivo"},
        {"Marseille", "Paris", "Lyon"},
        {"12", "13", "14"},
        {"Vert", "Rouge", "Bleu"},
        {"Java", "C", "Python"},
        {"7", "8", "9"},
        {"Vénus", "Terre", "Mercure"},
        {"101", "100", "102"},
        {"Atlantique", "Indien", "Pacifique"},
        {"4", "3", "5"},
        {"Berlin", "Hambourg", "Munich"},
        {"26", "27", "25"},
        {"Tigre", "Lion", "Éléphant"},
        {"7", "8", "9"},
        {"Afrique", "Amérique", "Asie"},
        {"18", "17", "19"},
        {"Rome", "Milan", "Naples"},
        {"CO2", "O2", "H2O"},
        {"6", "8", "10"},
        {"54", "56", "58"},
        {"Madrid", "Barcelone", "Seville"},
        {"50", "60", "100"},
        {"Congo", "Niger", "Nil"},
        {"Mars", "Jupiter", "Saturne"},
        {"24", "26", "28"},
        {"8", "9", "10"},
        {"Osaka", "Kyoto", "Tokyo"},
        {"Elephant", "Girafe", "Rhinoceros"},
        {"10", "12", "14"},
        {"Mercure", "Fer", "Cuivre"},
        {"27", "28", "26"},
        {"Toronto", "Ottawa", "Montreal"},
        {"1", "2", "3"},
        {"9", "10", "11"},
        {"Lisbonne", "Porto", "Faro"},
        {"Oxygene", "CO2", "Azote"},
        {"11", "12", "13"},
        {"Indien", "Atlantique", "Arctique"},
        {"16", "32", "64"}
        },
        {1, 2, 1, 0, 2, 1, 0, 2, 1, 2,
         1, 0, 2, 1, 0, 2, 1, 0, 2, 1,
         1, 0, 1, 2, 0, 1, 1, 2, 0, 1,
         0, 0, 1, 1, 2, 0, 1, 1, 0, 1}
    };

    int score = 0;
    int i;
    int reponse = 0;
    int nb_posees = 20;
    int ordre[40];
    int k, j, tmp, r, c;

    srand((unsigned int)time(NULL));
    for (i = 0; i < 40; i++) {
        ordre[i] = i;
    }
    for (i = 39; i > 0; i--) {
        j = rand() % (i + 1);
        tmp = ordre[i];
        ordre[i] = ordre[j];
        ordre[j] = tmp;
    }

    printf("===== QUIZ =====\n");

    for (k = 0; k < nb_posees; k++) {
        i = ordre[k];   /* AJOUT : indice de la question tiree au hasard */
        printf("\nQuestion %d : %s\n", k + 1, quiz.question[i]);
        printf("1. %s\n", quiz.choix[i][0]);
        printf("2. %s\n", quiz.choix[i][1]);
        printf("3. %s\n", quiz.choix[i][2]);
        printf("Votre reponse : ");
        while ((r = scanf("%d", &reponse)) != 1 || reponse < 1 || reponse > 3) {
            if (r == EOF) {
                printf("\nFin de la saisie.\n");
                return 0;
            }
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Reponse invalide, tapez 1, 2 ou 3 : ");
        }

        if (reponse == quiz.reponse[i] + 1) {
            printf("Bonne reponse !\n");
            score++;
        } else {
            printf("Mauvaise reponse. La bonne reponse etait : %s\n", quiz.choix[i][quiz.reponse[i]]);
        }
    }

    printf("\nScore final : %d/%d\n", score, nb_posees);
    return 0;

}