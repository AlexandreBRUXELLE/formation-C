# Outils
<!-- .slide: class="page-title" -->





## Sommaire
<!-- .slide: class="toc" -->

*Outils et solutions pour toutes les étapes de développement*

- Les environnements de développements, du plus léger au plus complet
- CMake (pour générer, tester et packager son soft).
- L'analyse statique avec Clang Static Analizer.
- Debugger efficacement son programme avec gdb/ddd.
- Les "grinds" au complet pour analyser sous toutes les coutures le programme : (Valgrind/Hellgrind/KCacheGrind/...).
- Documenter son code avec Doxygen.





## Les IDE Geany





## Kdevelop!





## Introduction à CMake

    - cmake : création de Makefile et compilation de projets
    - ctest : mise  en place de tests sur vos projets
    - cpack : création de package
    - cdash : une interface web pour les tests soumis sur différentes plateformes.


- Logiciel open source multi plate-forme: http://www.cmake.org
- Outil d’aide au processus de compilation (build) pour des cibles et des compilateurs hétérogènes
- CMake produit makefiles qui peuvent être utilisés avec l'installation make standard.
- Supporte des hiérarchies complexes (plusieurs bibliothèques, nombreux répertoires.
- Produit des fichiers de configuration: capable de générer des makefiles unix, des projets Kdevelop, MVSC, ...
- Dispose de nombreuses commandes permettant de localiser, include, les lib, executable
- Propose de nombreuses extensions pour localiser X, Qt, OpenGL...
- Propose des interfaces de test (CTest) et de packaging (CPack)

## Principe de fonctionnement

- L’utilisateur : Configure son build avec CMake
    + Commentaire, Commande, Liste, Variable, Structure de contrôle
- Cmake chreche les librairies et produit le Makefile

- CMakeLists.txt
    + fichiers texte d'entrée qui paramètres le projet et décrire le processus du build

- *.cmake
    + fichier cmake pour trouver des librairies, les fichiers et les définitions en variables appropriées au build
        * (Par exemple FindJava.cmake)

<!--
    Chaque fichier CMakeLists.txt se compose d'une ou plusieurs commandes.
    Chaque commande a la forme COMMAND (args ...) où commande est le nom de la commande,
    et args est un espace blanc liste d'arguments séparés.
    CMake fournit de nombreuses commandes prédéfinies, mais si vous avez besoin, vous pouvez ajouter vos propres commandes.
    En outre, l'utilisateur avancé peut ajouter d'autres générateurs de makefile pour des combinaisons particulières compilateur / OS.
-->





## Exécuter Cmake

- Mode graphique
```shell
    ccmake .
```

- Pour accélérer les prochains build cmake génére :
    CMakeCache.txt

- Si il a une erreur penser à supprimer le CmakeCache
    rm -f CmakeCache.txt ; cmake .

```cmake
    cmake_minimum_required(VERSION 2.8)

    project(hello_cmake)

    add_executable(hellocmake main.c)

    target_link_libraries(hellocmake ncurses)
```

```cmake
    PROJECT (HELLO)
        SET(HELLO_SRCS Hello.c File2.c File3.c)
    IF (WIN32)
        SET(HELLO_SRCS ${HELLO_SRCS} WinSupport.c)
    ELSE (WIN32)
        SET(HELLO_SRCS ${HELLO_SRCS} UnixSupport.c)
    ENDIF (WIN32)

    ADD_EXECUTABLE (Hello ${HELLO_SRCS})
    # look for the Tcl library
    FIND_LIBRARY(TCL_LIBRARY NAMES tcl tcl84 tcl83 tcl82 tcl80 PATHS /usr/lib /usr/local/lib)
    IF (TCL_LIBRARY)
        TARGET_ADD_LIBRARY (Hello TCL_LIBRARY)
    ENDIF (TCL_LIBRARY)
```





## Les "bugs"
<!-- .slide: class="toc" -->

- Des bugs (cachés ou non) peuvent avoir de conséquences fâcheuses:*
    + plantages (aléatoires), pertes de données
    + "exploitations": porte d'entrée aux problèmes de sécurités

- Si un programme s'exécute sans "bug":
    + cela n'implique pas que vous avez bien programmé !
    + les bugs peuvent être "non déterministes"

- Mieux vaut prévenir que guérir :
    + adopter de bonnes pratiques de programmation
    + tester régulièrement son code
    + détecter les problèmes le plus tôt possible dans le processus de programmations





## Bonnes pratiques
<!-- .slide: class="toc" -->

*Eviter la confusion, améliorer la compréhension entre les différents programmeurs, pour limiter le risque d'erreurs.*

-   commenter le code
-   avoir indentation correcte
-   utiliser des noms de variables/fonction explicites
-   "garder le code simple" (KIS):
-   préférer des fonctions courtes
-   éviter la redondance de code
-   code "modulaire"
-   documentez vos fonctions
-   respectez une convention de nommage
-   utilisez un utilitaire de versionnage




## Pratiques mauvaises/dangereuses/

*Ne pas initialiser les variables*

*Ne pas tester les codes retours*

*L'utilisation de fonctions réputées dangereuses*

- sprintf(), strcpy(), strcat(), vsprintf(), gets() ne vérifient pas si il y a assez de place
- fonctions non ré-entrantes dans un code multithread

<br>
*Ne pas désallouer/fermer ce qui ne sert plus (mémoire, descripteurs de fichiers...)*





<!--

## Tests et assertions

-   "Test unitaire" : vérifier le bon fonctionnement d'une partie (unité, module) du logiciel.
-   Créez et intégrez une batterie de tests qui teste automatiquement chaque partie les unes après les autres
-   Couvrir tous les cas

*Assertion : expression qui doit être évaluée à  vraie à  un moment donné*
3 types d'assertions:
-   pré-conditions
-   post-conditions
-   invariants

*En C/C++: on peut tester une assertion*
-   dans assert.h
-   se déactive avec l'option -DNDEBUG
-   attention: pas pour tester les codes retours dans un vrai programme !

    #define mon_assert(expr) {\
     if(!(expr)) {\
      fprintf(stderr,"assert %s fail %s:%s:%d\n",\
              __STRING(expr), __FILE__,\
              __ASSERT_FUNCTION,__LINE__);\
      abort();\
     }\
    }

-->



## Avant de débugger

*Commencer par détecter éléments "suspects" :*

- gcc -Wall
    + un code devrait toujours compiler sans warning !

- gcc -fstack-protector-all
    + Vérifier les dépassements de "buffer". Un message d'erreur est affiché.

- Analyse statique
    - clang static analizer



##  Analyse statique

- Généralement utilisé sur un code compilable
- généralement rapide ( temps d'analyse proche de temps donné à la compilation)
- haut niveau d'automatisation

- /!\ ne peut pas couvrir tous les bugs dans le code
- /!\ faux positifs
- /!\ risque de régressions


- Analyse statique est particulièrement bon pour :
    + dépassement de tampon (buffer overflow)
    + erreurs mémoires
    + détection de codes morts
    + détection variables non initialisées non utilisées
    + concurrence critique
    + erreurs *récurrentes* humaines



## Le débogage
*Ce chapitre ENSEIGNE deux techniques que vous pouvez utiliser pour déboguer vos programmes.*

- Utiliser le préprocesseur pour permettre l'inclusion conditionnelle d'instructions de débogage.
- Utiliser le débogueur interactif gdb.





## Le débogage via préprocesseur

*Activé ou désactivé le code de débogage avec les directives de compilation conditionnelle*

```c
    // Lire trois entier et afficher leur somme
    #include <stdio.h>
    #define DEBUG // à dé/commenter ou utiliser "gcc -D DEBUG debug.c"
    int process (int i, int j, int k)
    {
        return i + j + k;
    }

    int main (void)
    {
        int i, j, k, nread;
        nread = scanf ("%d %d %d", &i, &j, &k);
    #ifdef DEBUG
        fprintf (stderr, "Number of integers read = %i\n", nread);
        fprintf (stderr, "i = %i, j = %i, k = %i\n", i, j, k);
    #endif
    }
```

*Notez que la valeur affichée pour k peut être n'importe quoi dans le cas ou sa valeur n'a pas été renseigné lors de l'appel scanf et sachant que cette variable n'a pas été initialisée.*





## Le débogage avec gdb

*"gdb" est un débogueur interactif puissant pour déboguer des programmes compilés avec le compilateur gcc de GNU (acronyme de Gnu DeBugger)*

- Il vous permet d'exécuter votre programme, et :
    + d'arrêter à un endroit, puis de continuer l'exécution.
    + d'afficher et/ou de définir des variables à un endroid prédéterminé
    + d'exécuter le code une ligne à la fois.
- "gdb" dispose également d'une installation pour déterminer où les "core dumps" se produisent.
    + Les "core dumps" se produit en raison d'un événement anormal :
        * une division par zéro
        * tentatives d'accès après la fin d'un tableau.
    + Cela se traduit par la création d'un fichier "core" qui contient un aperçu du contenu de la mémoire du processus au moment où il termine.





## L'option "-g"

- L'option "-g" ( voire "-g3" max info) permet d'ajouter des informations supplémentaires dans le fichier de debug :
    + variables et structure,
    + noms des fichiers,
    + examiner la mémoire et les registres

```c
    // accès un élément en dehors d'un tableau.
    #include <stdio.h>
    int main (void)
    {
        const int data[5] = {1, 2, 3, 4, 5};
        int i, sum;

        for (i = 0; i >= 0; ++i)
            sum += data[i];
        printf ("sum = %i\n", sum);
        return 0;
    }
```





## Démarrer le déboggeur

+ Génération de notre éxecutable avec option de déboggage
> gcc -g bad.c -o bad.o
+ Lancement de gdb
> gdb bad.o
+ Avec **text unit interface** recommandé
> *gdb -tui bad.o* OU gdbtui bad.o


*A tout moment il est possible d'obtenir de l'aide*
> (gdb) help





## Ajouter des points d'arrêts

+ Nous devons arrêter l'exécution et passer en mode pas à pas.
+ Avant de lancer la commande *run*, vous devez définir un point d'arrêt.
+ La commande *break* ou *b* et spécifiez un emplacement, qui peut être
    - un nom de fonction, un numéro de ligne ou un fichier source et un numéro de ligne.

> break Main ---> Break au début de la fonction main ()
> break 5    --->  Break à la ligne 5 du fichier actuel
> break hello.c: 5 --->  Break à la ligne 5 de hello.c

+ Démarrons le programme qui va s'arréter à notre BREAK
> run

+ Puis interrogeons l'états des variables locales
> info locals




## Next Jump Continue

+ *next* exécute la fonction jusqu'à ce qu'elle soit terminée, puis retourne à la ligne suivante dans votre fonction actuelle.
+ *step* fonctionne exactement pareil, sauf que lui passe dans la fonction.
+ Utilisez la commande *continue* (ou c) pour poursuivre l'exécution.
+ Utilisez la commande *jump* pour poursuivre l'exécution vers une destination précise (s'utilise comme break).



## Jouer avec  les variables

- Afficher l'état des variables
> (gdb) print sum
> (gdb) print i
> (gdb) print data[0]
> (gdb) quit

- Affecter des valeurs aux variables

> (gdb) set var i=5
> (gdb) print i

> (gdb) set var i=i*2
> (gdb) print i



##  Wathpoint

+ Ce sont des points d'arrêt spéciaux qui se déclenchent chaque fois qu'une expression change.
+ *watch* prend une expression comme un argument, vous pouvez mettre un nom de variable, ou quelque chose comme *(p+5).
+ *info break* ou *info watch* liste les (break/watch)point et vous pouvez les supprimer à l'aide de la commande *delete*.
+ Enfin, vous pouvez utiliser *rwatch* pour détecter quand une variable est lue, et *awatch* pour détecter quand une variable est lue ou écrite.



##  Replacer le context

- gdb démarrer avec un "core" se positionne au moment du crash.
- gdb démarrer sans core se positionne à l'entré du "main"

Il est possible de préciser le contexte par exemple au sein d'une fonction (il n'est pas possible d'affecter une vairable d'un contexte non actif):
    (gdb) print main::i

Le variable global sont référencés par 'file’::var.

- Afficher les variables d'une fonction
> (gdb) list foo
- afficher le fichier source courant (+10 pour afficher les 10 premières lignes, (-10) ... ):
> (gdb )info source +10





##  Valgrind

- Détecter les errors mémoires
- Le *profilage du code* et les fuites mémoires
- Les dépassements de tableaux
- Compiler avec l'option -g (rajout des symboles de débogage dans le fichier binaire)
- Exécuter la commande, précédée de valgrind





## Optimiser son code

- Options de gcc:
    + \-Ox
        * \-O0 : pas d'optimisation
        * \-O1 : optimisations modérées
        * \-O2 : pleines optimisations
        * \-O3 : comme -O2, en encore plus agressif
        * \-Os : optimisation en mémoire (taille de d'exécutable)

- \-march=native : compile pour le processeur de la machine
- \-ffastmath : active certaines optimisations sur les flottants (ne respecte plus la norme IEEE 754)
-   ...

*Optimisations de gcc: passer des variables en registres, rendre des fonctions *inline*, dérécursiver, déboucler, réorganisation des instructions...*





## A savoir:

- Les malloc/free, c'est plutôt lent. Préférer d'autres méthodes d'allocations en cas de grosse demande
- Les realloc peuvent être très lents (déplacement en mémoire)
- Les appels systèmes, c'est très lent





## Outils de profilage

*Profilage : analyse dynamique de l'exécution d'un code.*

- Outils:
    + gprof
    + gcov et lcov





## gprof
- Calcule le temps passé dans chaque fonction, et le graphe d'appel.
- Le compilateur rajoute du code, qui va générer un fichier contenant les informations de profilage.
- Inconvénient: le code ne doit pas être optimisé (-Ox)

<br><br>
*Note: le code devient notablement plus lent*

- Compiler avec l'option -pg
- Lancer le programme normalement. Il va générer le fichier
- Une fois terminé, lancer ```gprof executable```
- L'affichage est en 2 parties
    + Le temps passé dans chaque fonction
    + Le graphe d'appel





## gcov et lcov
-   Teste la "couverture". Pour chaque ligne, affiche le nombre de fois que la ligne a été exécutée
-   Compiler avec -fprofile-arcs -ftest-coverage
-   Exécuter le code.
-   Exécuter ``` gcov fichier\_source```
-   Il va générer un fichier texte *fichier\_source.gcov*





## Introduction à Doxygen

- Documenter du code :
    + C, C++,
    + Java, Objective-C, Python, IDL, Fortran, VHDL, PHP, C#, ...
- Générer une doc en :
    + HTML, compressed HTML
    + latex, hyperlinked PDF
    + RTF (MS-Word)
    + Postscript
    + man pages (Unix) ...
+ Open-source (GNU General Public License)
+ Portable (Linux, MacOS X, Windows, most Unix’es)





## Installation de Doxygen

- Doxygen :
        ```shell
            sudo apt-get install doxygen doxygen-gui
        ```

- Graphviz, génération de graphes (graphes d'appel, de dépendances, ...).
        ```shell
            sudo apt-get install graphviz
        ```





## Documentation du code avec Doxygen

- Principe :
    + Ecrire des commentaires, différenciés de ceux qui ne sont pas à prendre en compte par norme

```c
    /*!
    * Commentaire multiligne compris par Doxygen.
    * Une convention pour le C
    */

    /* Les commentaires conventionnelles */
    // ne sont pas pris en compte par Doxygen.
```





## Utilisation de balises

*Plus on utilise de balise plus la doc sera claire.*
- Voici un exemple de commentaire d'en-tête de fichier
- L'ordre des balises n'a pas d'importance.

```c
    /*!
    * \file      main.c
    * \author    Alex
    * \version   1.0
    * \date      26 Juillet 2016
    * \brief     Un petit résumé
    * \details   Encore plus de détails
    *
    */
 ```





## Documenter une fonction

- L'ordre des balises n'a pas d'importance
- mais les balises \param ne peuvent être omises.

```c
    /*!
    * \brief      Calcule la distance entre deux points
    * \details    La distance entre les \a point1 et \a point2 est calculée par l'intermédiaire
    *                  des coordonnées des points. (cf #Point)
    * \param      point1         Point 1 pour le calcul de distance.
    * \param      point2         Point 2 pour le calcul de distance.
    * \return     Un \e float représentant la distance calculée.
    */
 ```





## Documenter une structure, une union, ou un enum.

- l'opération < permettant d'insérer un commentaire pour un membre d'une structure d'une union, d'un énum.

```c
    /*!
    * \brief      Couleur possible pour un Point.
    * \details    La table de correspondance de couleurs est disponible en modification par les accesseurs.
    */

    typedef enum
    {
        COLOR_BLUE,              /*!< Couleur bleu (0,0,255)                 */
        COLOR_DARK_RED,          /*!< Couleur rouge sombre (64,0,0)          */
        COLOR_OLIVE              /*!< Couleur olive (51,51,0)                */
    }

```






## Générer la documentation

- Pour cela lancer la commande :
    ```shell
        doxywizard.
    ```

- Etape 1: Entrer un répertoire de travail.
- Etape 2: Remplir les 4 parties de l'onglets Wizard (mode simplifié).

    + Project : Project name, Project version, Source code directory, Scan recursively, Destination directory
    + Mode : Documented all entities, Include cross-referenced, Select programming language.
    + Output: HTML (with search function )
    + Diagrams: use GraphViz ( coché les 4 derniers )

- Etape 3 : Onglet Run

>example  : http://axiomcafe.fr/chibiosVF/index.html
>Il s'agit de la traduction effectuée par AxiomCafe de la documentation du noyau ChibiOS v1.0





<!-- A passer vite !-->
## Utilisation du mode expert
- Quelques fonctions intéressantes du mode Expert.

- Build :
    + EXTRACT_STATIC :          Permet d'afficher la documentation pour les fonctions/méthodes/membres ayant le qualificateur static.

- Source Browser :
    + INLINE_SOURCES :          Permet d'insérer le corps des fonctions/méthodes/structures/... extraites dans la documentation.

- Dot :
    + DOT_TRANSPARENT :         Permet de générer des graphes sur fond transparent.

