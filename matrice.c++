#include <iostream>
#include <cstring>
#include <iomanip>

#define N 3
#define M 4
#define P 8

using namespace std;

/* ================= STRUCTURES ================= */

struct facture {
    int idFact;
    float montant;
    char objet[30];
    char idcl[10];
};

struct client {
    char idcl[10];
    char nom[30];
    char filiere[25];
    char niveau[25];
};

/* ================= VARIABLES GLOBALES ================= */

facture MatFact[N][M];
client tabcl[P];

/* ================= REMPLISSAGE ================= */

void remplirMatFact() {
    MatFact[0][0].idFact = 1;
    MatFact[0][0].montant = 150000;
    strcpy(MatFact[0][0].objet, "Inscription");
    strcpy(MatFact[0][0].idcl, "cl002");

    MatFact[0][1].idFact = 2;
    MatFact[0][1].montant = 200000;
    strcpy(MatFact[0][1].objet, "mensualite");
    strcpy(MatFact[0][1].idcl, "cl002");

    MatFact[0][2].idFact = 33;
    MatFact[0][2].montant = 250000;
    strcpy(MatFact[0][2].objet, "Inscription");
    strcpy(MatFact[0][2].idcl, "cl001");

    MatFact[0][3].idFact = 4;
    MatFact[0][3].montant = 600000;
    strcpy(MatFact[0][3].objet, "mensualite");
    strcpy(MatFact[0][3].idcl, "cl001");

    MatFact[1][0].idFact = 5;
    MatFact[1][0].montant = 150000;
    strcpy(MatFact[1][0].objet, "tenue");
    strcpy(MatFact[1][0].idcl, "cl002");

    MatFact[1][1].idFact = 6;
    MatFact[1][1].montant = 250000;
    strcpy(MatFact[1][1].objet, "Inscription");
    strcpy(MatFact[1][1].idcl, "cl003");

    MatFact[1][2].idFact = 7;
    MatFact[1][2].montant = 100000;
    strcpy(MatFact[1][2].objet, "tenue");
    strcpy(MatFact[1][2].idcl, "cl003");

    MatFact[1][3].idFact = 8;
    MatFact[1][3].montant = 800000;
    strcpy(MatFact[1][3].objet, "mensualite");
    strcpy(MatFact[1][3].idcl, "cl003");

    MatFact[2][0].idFact = 9;
    MatFact[2][0].montant = 700000;
    strcpy(MatFact[2][0].objet, "mensualite");
    strcpy(MatFact[2][0].idcl, "cl002");

    MatFact[2][1].idFact = 10;
    MatFact[2][1].montant = 200000;
    strcpy(MatFact[2][1].objet, "tenue");
    strcpy(MatFact[2][1].idcl, "cl004");

    MatFact[2][2].idFact = 11;
    MatFact[2][2].montant = 400000;
    strcpy(MatFact[2][2].objet, "Inscription");
    strcpy(MatFact[2][2].idcl, "cl005");

    MatFact[2][3].idFact = 12;
    MatFact[2][3].montant = 300000;
    strcpy(MatFact[2][3].objet, "Inscription");
    strcpy(MatFact[2][3].idcl, "cl006");
}

void remplirclient() {
    strcpy(tabcl[0].idcl,"cl001"); strcpy(tabcl[0].nom,"Moussa SARR"); strcpy(tabcl[0].filiere,"IR"); strcpy(tabcl[0].niveau,"Master2");
    strcpy(tabcl[1].idcl,"cl002"); strcpy(tabcl[1].nom,"Jean Diouf"); strcpy(tabcl[1].filiere,"IR"); strcpy(tabcl[1].niveau,"Master2");
    strcpy(tabcl[2].idcl,"cl003"); strcpy(tabcl[2].nom,"Djibrif Fall"); strcpy(tabcl[2].filiere,"MAI"); strcpy(tabcl[2].niveau,"Master1");
    strcpy(tabcl[3].idcl,"cl004"); strcpy(tabcl[3].nom,"Oumar Seck"); strcpy(tabcl[3].filiere,"IR"); strcpy(tabcl[3].niveau,"Master2");
    strcpy(tabcl[4].idcl,"cl005"); strcpy(tabcl[4].nom,"Awa Ly"); strcpy(tabcl[4].filiere,"MAI"); strcpy(tabcl[4].niveau,"Master2");
    strcpy(tabcl[5].idcl,"cl006"); strcpy(tabcl[5].nom,"Marienne Fall"); strcpy(tabcl[5].filiere,"MAI"); strcpy(tabcl[5].niveau,"Master1");
    strcpy(tabcl[6].idcl,"cl007"); strcpy(tabcl[6].nom,"Oumy Dieng"); strcpy(tabcl[6].filiere,"IR"); strcpy(tabcl[6].niveau,"Master1");
    strcpy(tabcl[7].idcl,"cl008"); strcpy(tabcl[7].nom,"Marty Mbaye"); strcpy(tabcl[7].filiere,"IR"); strcpy(tabcl[7].niveau,"Master2");
}

/* ================= FONCTIONS ================= */

int nbclien() {
    return P;
}

float TotalInscription() {
    float T = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(strcmp(MatFact[i][j].objet,"Inscription")==0)
                T += MatFact[i][j].montant;
    return T;
}

/* ===== TRI FACTURES PAR MONTANT ===== */

void TrierFactureParMontant() {
    facture tmp;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            for(int k=i;k<N;k++)
                for(int l=(k==i?j+1:0);l<M;l++)
                    if(MatFact[i][j].montant > MatFact[k][l].montant) {
                        tmp = MatFact[i][j];
                        MatFact[i][j] = MatFact[k][l];
                        MatFact[k][l] = tmp;
                    }
}

void AfficherFactures() {
    cout << "\n--- Factures par ordre croissant ---\n";
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cout << MatFact[i][j].idFact << " | "
                 << MatFact[i][j].objet << " | "
                 << MatFact[i][j].montant << " | "
                 << MatFact[i][j].idcl << endl;
}

/* ===== FACTURE MONTANT MAX ===== */

void MaxMontant() {
    facture max = MatFact[0][0];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(MatFact[i][j].montant > max.montant)
                max = MatFact[i][j];

    cout << "\nFacture au montant maximal : "
         << max.idFact << " | "
         << max.objet << " | "
         << max.montant << endl;
}

/* ===== LISTE VERSEMENT PAR IDCL ===== */

void ListeVersementIdcl(const char id[10]) {
    cout << "\nVersements du client " << id << " :\n";
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(strcmp(MatFact[i][j].idcl,id)==0)
                cout << MatFact[i][j].idFact << " | "
                     << MatFact[i][j].objet << " | "
                     << MatFact[i][j].montant << endl;
}

/* ===== TRI CLIENT PAR NOM ===== */

void TrierClientsParNom() {
    client tmp;
    for(int i=0;i<P-1;i++)
        for(int j=i+1;j<P;j++)
            if(strcmp(tabcl[i].nom,tabcl[j].nom)>0) {
                tmp = tabcl[i];
                tabcl[i] = tabcl[j];
                tabcl[j] = tmp;
            }
}

void AfficherClients() {
    cout << "\n--- Clients triés par nom ---\n";
    for(int i=0;i<P;i++)
        cout << tabcl[i].idcl << " | "
             << tabcl[i].nom << " | "
             << tabcl[i].filiere << " | "
             << tabcl[i].niveau << endl;
}

/* ================= MAIN ================= */

int main() {
    remplirMatFact();
    remplirclient();

    cout << "Nombre de clients : " << nbclien() << endl;
    cout << "Total inscription : " << TotalInscription() << endl;

    TrierFactureParMontant();
    AfficherFactures();

    MaxMontant();

    ListeVersementIdcl("cl001");
    ListeVersementIdcl("cl002");

    TrierClientsParNom();
    AfficherClients();

    return 0;
}tttttt5