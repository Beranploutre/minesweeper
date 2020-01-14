//*************************************************************************** //
//  PROGRAMME : modele.ccp (mettre � jour ce cartouche)
//  DATE      :
//  OBJET     :
//  AUTEUR(S) : B�ranger RINCENT Alexis MARINHO
//***************************************************************************

// ===================== Liste des fichiers d'en-t�te ======================= //
#include <iostream>			// flux d'entr�es/sorties
#include <iomanip>			// manipulateurs de flux
#include <cstdlib>		    // biblioth�que c standard
#define _USE_MATH_DEFINES	// biblioth�que math�matique
#include <cmath>
#include <clocale>			// caract�res accentu�s


using namespace std;		// permet d'abr�ger les appels aux flux std::cin et std::cout

// =============================== Constantes =============================== //
/* d�clarez ici les constantes */
const int MAX=8;
// ================================== Types ================================= //
/* d�clarez ici les nouveaux types */
typedef struct {
    bool mine;
    bool revele;
    int nbMines;
} tile;

typedef tile t_grille[MAX][MAX];
// ============================ Sous programmes ============================= //
/* d�clarez ici les sous-programmes */
//importer une grille

//afficher une grille

//lire les coord
void lireCoordonnees(int lig, int col){
    cout << "case � jouer" << endl;
    cout << "Ligne : ";
    cin >> lig;
    cout << "Colonne : ";
    cin >> col;
}

//indice
int indice(t_grille grille, int lig, int col){
//declarations
    int mines;
    int cpt;
//actions
    mines=0;
    lig++;
    col++;
    for(cpt = 0; cpt < 3; cpt++){
        for(cpt=0; cpt<3; cpt++){
            if(grille[lig][col].mine == true)
                mines++;
            col--;
        }
        lig++;
    }
    return mines;
}

//lire une case
void lireCase(t_grille & grille, int & nbLibres, int lig, int col)
{
    //DECL

    //ACTION
    if(grille[lig][col].mine == true) {
        cout << "fin de partie" << endl;
    }
    else {
        cout << "bien jou�"<< endl;
        grille[lig][col].revele = true;
        nbLibres++;
        grille[lig][col].nbMines = indice(grille, lig, col);
    }
}


//jouer tt les cases a partir d'une direction
void lireDirection(t_grille & grille){
//DECL
    int choix;
    int lig, col;
    int nbLibres;
//ACTION
    do{
    cout << "Voulez-vous :" << endl;
    cout << "donner la ligne(0..8) et la colonnne (0..8) : " << endl;
    lireCoordonnees(lig, col);
    cout << "donner la direction d'effacement  :" << endl;
    cout << '\t' << "(1) haut" << endl;
    cout << '\t' << "(2) bas" << endl;
    cout << '\t' << "(3) gauche" << endl;
    cout << '\t' << "(4) droite" << endl;
    cout << "Entrez votre choix :" << endl;
    cin >> choix;
    }
    while(choix < 1 || choix > 4);

    switch(choix) {
        case 1:
            for(lig; lig >= 0; --lig){
                lireCase(grille, nbLibres);
            }
            break;
        case 2:
            for(lig; lig < MAX; lig++){
               lireCase(grille, nbLibres);
            }
            break;
        case 3:
            for(col; col >= 0; --col){
                lireCase(grille, nbLibres);
            }
            break;
        case 4:
            for(col; col < MAX; col++){
                lireCase(grille, nbLibres);
            }
            break;
    }

}
//debug
void debug(){

}
// ========================== Programme principal =========================== //
int main(void)
{

    // D�clarations locales
    int nbLibres;
    int nbCases;
    int nbMines;
    int lig, col;
    int choix;
    t_grille grille;
    // Actions
    setlocale(LC_ALL, "french");
    nbLibres = 0;
    nbMines = 2; // a calculer auto plus tard
    nbCases = 8*8; // a calculer auto plus tard




    while(nbLibres < nbCases - nbMines) {
        do {
            cout << "Voulez-vous :" << endl;
            cout << '\t' << "(1) importer une grille" << endl;
            cout << '\t' << "(2) afficher la grille" << endl;
            cout << '\t' << "(3) jouer une case" << endl;
            cout << '\t' << "(4) jouer toutes les cases � partir d'une case de d�part et d'une direction" << endl;
            cout << '\t' << "(5) menu debug" << endl;
            cout << '\t' << "(6) quitter" << endl;
            cout << "Entrez votre choix :" << endl;
            cin >> choix;
        }
        while(choix < 1 || choix > 5);

        switch(choix) {
        case 1:
            //importGrille(grille);
            cout << "rien ne se passe" << endl;
            break;
        case 2:
            //afficherGrille(grille);
            cout << "rien ne se passe" << endl;
            break;
        case 3:
            lireCoordonnees(lig, col);
            lireCase(grille, nbLibres);
            break;
        case 4:
            lireDirection(grille);
            break;
        case 5:
            debug();
            break;
        case 6:
            return 0;
            break;
        }
        // retour au syst�me d'exploitattion
    }
    cout << "c'est gagn� !" << endl << "bah t'a gagn� quoi ?";
}
// ============================ Fin du programme ============================ //
