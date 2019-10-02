<div style="height:24.7cm; position: relative; border: 1px solid black;">
    <h1 style="position:absolute; top: 33%; width:100%; text-align: center;">{Titre-Formation}</h1>
    <h1 style="position:absolute; top: 50%; width:100%; text-align: center;">Travaux Pratiques</h1>
    <img src="ressources/logo-zenika-small.png" style="position: absolute; bottom: 20px; right: 20px; height: 150px;">
</div>
<div class="pb"></div>


## Pré-requis

### Installation

Installer les technos demandées


## TP 1 : Premier exercice

### 1. Ecrire un programme affichant la taille en octets d'une variable de chacun des types suivant ainsi que ses valeurs min/max

- signed char
- unsigned char
- signed short
- unsigned short


## TP 2 : Utiliser les opérateurs de masquages

### 1. Déclarer en binaire aa := 1, bb := 2, cc := 4, dd := 8, puis afficher au format entier ces variables
### 2. Déclarer en binaire ee := aa ET bb, ff := aa OU bb, gg := aa XOR bb puis afficher au format entier ces variables
### 3. Ecrire à la main le calcul de chacune de ces opérations en commentaire
### 4. afficher les résulats de :
    char hh = aa << 1 ;
    char ii = hh << 1 ;
    char jj = ii << 1 ;
    char ll = jj << 1 ;
### 5. Seulement à partir de `aa`, des opérateurs de masquages et décalage  obtenir mm = 37;

## TP 3 : Utiliser les tableaux et les boucles

### 1. Création d'un tableu de taille 10
### 2. Initialisation du tableau avec toutes les premières puissances de 10
### 3. Afficher toutes les valeurs du tableau par ordre croissant
### 4. Afficher toutes les valeurs du tableau par ordre décroissant


## TP 4 : Listes chainées :

### 1. Coder les fonctions suivantes
    void initializeList(LinkedList*)
    void addHead(LinkedList*, void*)
    void addTail(LinkedList*, void*)
    void delete(LinkedList*, Node*)
    Node *getNode(LinkedList*, COMPARE, void*)
    void displayLinkedList(LinkedList*, DISPLAY)

### 2. Ecrire le main :
- Créer une liste
- Créer un employé "Samuel"
- Créer un employé "Sally"
- Initialiser la liste
- Ajouter samuel et sally a la liste
- Chercher un "Sally" dans la liste
- Supprimer "Sally" de la liste

### 1. Afficher la liste

## Annexes

[wiki type c](https://en.wikipedia.org/wiki/C_data_types)


