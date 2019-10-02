# Bases du language
<!-- .slide: class="page-title" -->




## Sommaire
<!-- .slide: class="toc" -->

*Appréhender la syntaxe du language*

- Variables, types de données, et expressions Arithmétiques.
- Les opérateurs bits à bits : pour modifier et/ou tester un ou plusieurs bits d'une donnée.
- Les boucles : "for" "while" "do while".
- La prise de décision avec if, switch, et les booléens.
- Les tableaux, de "caractères", "multidimensionnels"...




## Les variables

*Une variable est un espace mémoire de taille précise, qui permet de stocker une valeur.*

Pour déclaré une variable il faut lui définir en type, un identificateur et une valeur par défaut.

```c
    int    ma_premiere_variable = 0 ;
```




## Les identificateurs

Les identificateurs sont les noms données aux éléments tels que les variables, les fonctions, les types, les structures, etc.

Suite de caractères composée de lettres non accentuées, de chiffres, et du caractère souligné '_'

```c
    int maVariable, ta_variable, saVariable37 = 0 ;
```


> */!\ pas de caractères accentués *<br>
> */!\ pas de chiffre au début*<br>
> */!\ maVariable et mavariable sont deux identificateurs différents !!*



## Les types de données

- Définition:
    + type: manière dont une donnée est représentée en mémoire
- Deux types de types:
    + types simples : la donnée est caractérisée par une seule valeur
    + types agrégés : la donnée est caractérisée par un ensemble de valeurs (tableaux, structure, ...)
- Il faut pouvoir choisir le type le plus approprié pour représenter et manipuler une information:
    + en utilisant les types de base prédéfinis
    + en définissant de nouveaux types à base de types de base et éventuellement de types définis par le programmeur




## Les types de bases

- Des types simples sont prédéfinis et peuvent être utilisés dans tout programme :
    + int, long: types entiers
    + float, double: types flottants
    + char: type caractère
    + void: type vide

- Les types peuvent être précisés par des spécificateurs de types:
    + short: spécifie la taille pour des entiers
    + long: spécifie la taille pour des entiers ou des flottants
    + signed/unsigned: spécifient le signe pour des entiers (et des caractères...)




## Les types entiers
*Valeur pour une machine 32-bit*

| Dénomination | Spécificateurs possibles | Taille | Domaine |
| --- | --- | --- | --- |
| Entier court signé | short, short int, signed short, signed short int |  2 octets | -32 767 à +32 767 |
| Entier court non signé | unsigned short, unsigned short int | 2 octets | 0 à +65 535 |
| Entier signé | int, signed int, signed | 4 octets | -32 767 à +32 767 |
| Entier non signé | unsigned int, unsigned | 4 octets| 0 à +65 535 |
| Entier long signé | long, long int, signed long, signed long int | 4 octets| -2 147 483 647 à +2 147 483 647 |
| Entier long non signé | unsigned long, unsigned long int | 4 octets| 0 à +4 294 967 295 |




## Les types flottants

La norme définit trois types de flottants:

| Spécificateurs de type |  Taille | Domaine |
|--- | --- | --- |
| float | 10e37 à 10e-37 | 6 |
| double | 10e37 à 10e-37 | 10 |
| long double | 10e37 à 10e-37 | 10 |




## Le type caractère 1/2

- Représenter des valeurs caractères prédéfinies (au minimum les caractères du jeu minimal d’exécution)
- Représentation à l’aide d’1 octet:
    + permet de représenter 256 caractères (ex. code ASCII)
    + permet également de représenter et de manipuler de petites valeurs entières (les opérateurs de l’arithmétique entière s’appliquent aux types caractère)

- La norme définit deux types de caractères possibles en général équivalents, mais pas lorsqu’ils sont utilisés pour représenter de petites valeurs entières




## Le type caractère 2/2

- Le code associé à un caractère:
    + est indépendant de l’attribut de signe
    + est dépendant de l’implémentation (ex: é n’existe que pour certaines implémentations, son code pourrait correspondre à un autre caractère graphique)

- Les constantes caractères:
    + se notent entre simples quotes, ex: ‘a’
    + Les constantes non imprimables (i.e. ne disposant pas d’une représentation graphique) sont accessible via une séquence d’échappement introduite par un anti-slash,

ex: ‘\t’ représente la tabulation horizontale




## Écriture formatée de données 1/2

<p style="text-align: center;">*La fonction printf est utilisée pour transférer du texte,<br> des valeurs de variables ou des résultats d'expressions <br> vers le fichier de sortie standard stdout (par défaut l'écran).*</p>

exemple 1 :

```c
    printf("La valeur min du type char est %i, le max : %d \n", SCHAR_MIN, SCHAR_MAX);
```

| Type| Symbole |
|--- | --- |
| char, signed char <br>unsigned char | %c <small>(or %hhi for numerical output)</small> <br> %c <small>(or %hhu for numerical output)</small> |
| short, short int<br>signed short, signed short int | %hi |
| unsigned short, unsigned short int | %hu |
| int<br>signed int | %i or %d |
| unsigned int | %u |

<p style="text-align: center;">** TP 1 **</p>




## La sortie standard printf 2/2


| Type| Symbole |
|--- | --- |
| long<br>long int<br>signed long<br>signed long int | %li |
| unsigned long<br>unsigned long int | %lu |
| long long<br>long long int<br>signed long long<br>signed long long int | %lli |
| unsigned long long<br>unsigned long long int | %llu |
| float | %f <small>(promoted automatically to <code>double</code> for <code>printf()</code>)</small> |
| double | %f (%F) |
| long double | %Lf  %LF   %Lg  %LG  %Le  %LE <ref name=uplowcase/> |




## Introduction aux structures de données de C

- Le C propose plusieurs structures de données utiles,
    + Les tableaux: permettent de représenter une collection de données d’un même type.
    + Les structures: permettent de représenter une collection de données de divers types.
    + Les chaînes de caractères: cas particuliers de tableaux.




## Introduction aux tableaux
- Définition:
    + Tableau: ensemble de données d’un même type, désignées par un identificateur unique.
    + Un élément est repéré dans le tableau par une valeur entière nommée indice:
        * l’indice indique la position d’un élément dans le tableau
        * par convention, le premier élément est à l’indice 0, et donc le dernier à l’indice (tailleTableau – 1)
    +  Il est possible d’avoir des tableaux dont les éléments sont des tableaux, et donc d’obtenir des tableaux à plusieurs dimensions.





## Déclaration et initialisation de tableaux

- Déclaration:
    + similaire à la déclaration de variable de type de base, mais en spécifiant la taille du tableau (i.e. le nombre de données contenues),
```c
    int tableauEntiers[10]; /* tableauEntiers contient 10 entiers */
```
    + il est impératif pour le compilateur de préciser une valeur constante pour la taille du tableau afin de pourvoir réserver l’espace mémoire correspondant

- Initialisation:
    + les éléments peuvent être initialisés lors de la déclaration du tableau,
```c
    int tableauEntiers[3] = {1, 2, 3};
```

    + les éléments peuvent être initialisés individuellement après la déclaration du tableau,
```c
    int tableauEntier[0] = 1;
```





## Déclaration et initialisation des chaînes de caractères

- Déclaration: comme pour celle d’un tableau de caractères:
    + Prévoir un élément de plus que la taille maximale pour le terminateur de chaîne,
```c
    char prenom[9];
```

- Initialisation:
    + Initialisation individuelle des éléments du tableau:
```c
    char prenom[9] = {‘a’,‘l’,‘p’,‘h’,‘o’,‘n’,‘s’, ‘e’,‘\0’};
    /* modification de la première lettre */
    prenom[0] = ‘A’;
```
    + Initialisation abrégée pour les chaînes de caractères:

```c
    /* le terminateur de chaîne est ajouté par le compilateur */
    char prenom[9] = « alphonse »;
    /* la taille nécessaire est calculée par le compilateur */
    char prenom[] = « alphonse »;
```




## Les opérateurs

- Le C dispose d’une large gamme d’opérateurs:
    + Opérateurs arithmétiques
    + Opérateurs d’affectation
    + Opérateurs relationnels
    + Opérateurs logiques
    + Opérateurs de changement de type
    + Opérateurs de manipulation de bits




## Les opérateurs bits à bits

|type| symblole |opération|
|---|---|---|
| masquage | & <br> &#124; <br> ^  | ET bit à bit <br> OU bit à bit <br> XOR bit à bit |
| décalage | >> <br> << | vers la droite<br> vers la gauche|

> Le décalage de n à droite revient à une division par 2n, tandis qu’un décalage à gauche de n revient à une multiplication par 2n

<p style="text-align: center;">** TP 2 **</p>




## Opérateurs arithmétiques
| Opérateur     | Résultat                              | Contraintes opérandes     |
|---            |---                                    |---                        |
| +val          | Valeur de val                         | N/A                       |
| -val          | Opposé de val                         | N/A                       |
| val1 / val2   | Quotient exact de val1 par val2       | Flottants                 |
| val1 / val2   | Quotient entier de val1 par val2      | Entiers                   |
| val1 % val2   | Reste de la division de val1 par val2 | Entiers                   |
| val1 * val2   | Produit de val1 par val2              | N/A                       |
| val1 + val2   | Somme de val1 et val2                 | N/A                       |
| val1 - val2   | Différence de val1 et val2            | N/A                       |


> *Il n’existe pas d’opérateur d’élévation à la puissance (cf. la fonction pow dans le module math.h de la librairie standard)*





## Opérateur d’affectation
L’opérande de gauche doit nécessairement pouvoir être modifiable !

- On parle de **lvalue**:
    + Variables modifiables (donc pas les constantes),

- Associativité de droite à gauche, ex:
    + a = b = c affecte tout d’abord la valeur de c à b, puis la nouvelle valeur de b à a

- Des conversions implicites peuvent avoir lieu lors d’affectations

> */!\ Attention cependant à ne pas affecter n’importe quel type de valeur à une lvalue au risque de perdre de la précision*





## Opérateurs d’affectation élargie et d’incrémentation
- Les opérateurs d’affectation élargie permettent de condenser certaines affectations:
    + Ex: a = a + c peut être réécrit en a += c

- Les opérateurs d’incrémentation condensent les affectations de type:
    + Ex: a = a + 1 peut être réécrit en a++





## Opérateur de transtypage
Permet de provoquer explicitement des conversions à l’aide d’un opérateur unaire:

```c
    // (type-voulu) expression
```

convertit le résultat de expression en type-voulu, exemple :

```c
    (double) (n / p)
```

si n et p sont des entiers, alors le résultat de la division est d’abord calculé comme résultat entier, puis converti en flottant





## Opérateur de condition

- Opérateur ternaire qui permet de retourner la valeur d’une expression ou d’une autre en fonction d’une condition :

```c
    // condition ? exp1 : exp2 ;
    // max = a > b ? a : b
```

- peut se réécrire à l’aide de l’instruction if:
```c
    if (a > b)
        max = a;
    else
        max = b;
```



## Opérateurs logiques
- Utilisés pour combiner des expressions logiques (et, ou et non logiques)

- Pas de type logique en C:
    + 0 correspond à faux
    + autres correspond à vrai

| Opérateur | Signification |
|---|---|
| !exp | Négation logique de exp : 1 si exp nul, 0 sinon |
| exp1 && exp2 | Et logique de exp1 et exp2 : 1 si exp1 et exp2 sont tous deux non nuls, 0 sinon |
| exp1 &#124;&#124; exp2 | Ou logique de exp1 et exp2 : 0 si exp1 et exp2 sont tous deux nuls, 1 sinon |





## Opérateurs relationnels

- Utilisés pour effectuer des comparaisons.

- Il n’existe pas de type booléen en C (_Bool est un unsigneed int), le résultat d’une comparaison est donc un entier qui vaut:
    + 0 si le résultat de la comparaison est faux
    + conséquence : on peut utiliser le résultat d’une comparaison dans un calcul, ex. res = (a < b)

| Opérateur | Signification |
| --- | --- |
| < <br> <= <br> > <br> >= |Inférieur <br> Inférieur ou égal <br> Supérieur <br> Supérieur ou égal |
| == <br> !=  |Égal <br> différent |





## C propose deux instructions de condition:

- L’instruction if permet de choisir entre plusieurs instructions (éventuellement composées) en fonction de la valeur d’expressions numériques jouant le rôle de conditions.

- L’instruction switch permet d’effectuer un choix entre plusieurs possibilités correspondant à des instructions (éventuellement composées) en fonction d’une valeur numérique entière constante.





## L’instruction if
- Syntaxe:
```c
    if (expression-condition)
        instruction1
    else
        instruction2
```

- Si expression-condition est non nulle, alors instruction1 est exécutée; sinon, instruction2 est exécutée si la partie else est présente.
- Dans tous les cas, le flot du programme continue après l’instruction if.





## Nature des instructions de l’instruction if

- Les instructions de l’instruction if sont des instructions quelconques:
```c
    if (valeur <= VALEUR_MAX)
        printf(“tout va bien“); /* instruction simple */
    else
    { /* instruction composée */
        printf(“rien ne va plus!”);
        valeur = VALEUR_MAX;
    }
```
- Attention à la bonne utilisation des accolades





## L’instruction switch
- Syntaxe usuelle:
```c
    switch(expression) {
        case constante1: [instructions1]
        case constante2: [instructions2]
        ...
        case constanteN: [instructionsN]
        default: [instructions] /* cas par défaut */
    }
```

- Contraintes sur les éléments du switch:
    + expression est de type entier
    + constanteX sont des expressions constantes entières:

- doivent être évaluables au moment de la compilation

- pas de possibilité de spécifier un intervalle
    + instructionsX sont des suites d’instructions (pas nécessairement des blocs)





## Les instructions de boucle
- Le C propose 3 instructions de boucle:
- while : permet de répéter des instructions tant qu’une condition est vraie; cette condition est évaluée avant chaque itération.
- do...while : permet d’exécuter un groupe d’instructions puis de le répéter tant qu’une condition est vraie; cette condition est évaluée après chaque itération.

- for : permet de répéter des instructions en précisant:
    + les actions à réaliser avant de rentrer dans la boucle
    + la condition de poursuite de la boucle
    + les actions à réaliser après chaque itération





## L’instruction while
- Syntaxe:
```c
    while (condition) {
        instruction
    }
```
- condition est une expression quelconque de type numérique.
- instruction est une instruction quelconque.


- Exemple d’utilisation:

```c
    char initiale = ‘A’ - 1;
    while (initiale < ‘A’ || initiale > ‘Z’) {
        printf(“Veuillez saisir votre initiale: ”);
        scanf(“%c”, &initiale); /* saisie au clavier de la valeur
        de initiale */
    }
```




## L’instruction do...while
- Syntaxe:

```c
    do {
        instruction
    } while (condition);
```

- condition est une expression quelconque de type numérique.
- instruction est une instruction quelconque.

- Exemple d’utilisation:
```c
    char initiale;
    do {
        printf(“Veuillez saisir votre initiale: “);
        scanf(“%c”, &initiale); /* saisie au clavier de la valeur
        de initiale */
    } while (initiale < ‘A’ || initiale > ‘Z’); /* /!\ au point virgule */
```




## L’instruction for
- Syntaxe:
```c
    for ([exp1]; [exp2]; [exp3]) { 
        instruction 
    }
```
- exp1 est une expression quelconque qui permet d’initialiser la boucle
- exp2 est une expression numérique qui définit une condition qui permet de passer à l’itération suivante; si absente, est évaluée à vrai
- exp3 est une expression quelconque évaluée après chaque itération

```c
    for ( c = 0 ; c < n ; c++ ){
        if ( c <= 1 )
            next = c;
        else{
            next = first + second;
            first = second; second = next;
        }
        printf("%d\n",next);
    }
```

<p style="text-align: center;">** TP 3 **</p>




## Régles d'utilisation des instructions de boucle

- En général, on peut appliquer les régles suivantes:
  + Si la boucle est définie à l'avance (i.e. on connaît le nombre d'itérations avant de rentrer dans la boucle)
    ++ Utilisation une instruction for
  + Si la boucle n'est pas définie à l'avance
    ++ Si la condition de passage à l'itération suivante dépend d'informations modifiées en cours de boucle, utilisation d'une instruction do...while
    ++ Sinon, utilisation d'une instruction while
- En pratique, il faut favoriser avant tout la lisibilité des programmes.



## Retour sur les tableaux : les tableaux "multidimensionnels"


```c
    int M[4][5];
```

```c
    int M[4][5] = {
                    { 10,  5, -3, 17, 82 },
                    {  9,  0,  0,  8, -7 },
                    { 32, 20,  1,  0, 14 },
                    {  0,  0,  8,  7,  6 }
                  };
```

```c
    int M[4][5] = { 10, 5, -3, 17, 82, 9, 0, 0, 8, -7, 32, 20, 1, 0, 14, 0, 0, 8, 7, 6 };
```

```c
    int matrix[4][3] = { [0][0] = 10, [0][1] = 5, [0][2] = 9 };
```

