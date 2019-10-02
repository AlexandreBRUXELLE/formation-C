# Librairies et des algorithmes incontournables.
<!-- .slide: class="page-title" -->



## Plan
<!-- .slide: class="toc" -->

 *Concepts plus avancés*

- Manipulation des flux de fichiers.
- Faire du Multithreading avec la librairie pthreads, POSIX.
- Un client/serveur TCP (la sérialisation).
- Une librairie tierce pour du rendu graphique : la SDL.




## Les bibliothèque statique et dynamiques



## Manipulation des flux de fichiers.
*Pour communiquer vers l'extérieur un programme utilise un flux de données, pour lire et écrire des octets.*

- Vous avez utilisé des flux de données qui sont connectés aux fichiers ou des entrées et sorties standard.




## Un serveur tcp
*Pour communiquer vers l'extérieur un programme utilise un flux de données, pour lire et écrire des octets.*

- Un nouveau type de flux de données appelé socket :
- Avant qu'un serveur puisse utiliser un socket pour parler à un programme client:
    + il doit passer par quatre étapes, vous pouvez vous en rappeler avec l'acronyme BLAB:
        * Bind,
        * Listen,
        * Accept,
        * Begin.




## socket()
<br>
```c
    int listener_d = socket(AF_INET,SOCK_STREAM,0);
    if(listener_d )
        error("Can't open socket...");
```




## bind()
<br>
``` c
    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_port = (in_port_t)htons(30000); // htons cf. "1."
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    int c = bind (listener_d, (struct sockaddr_in *) &name, sizeof(name));
    if (c == -1)
        error("Can't bind to socket");
```

- "1." Juste pour nous emm*, les différents type de machines utilisent différents ordres d'octets internes pour leurs entiers multi-octets.
- Ainsi en envoyant un short, il se peut qu'un ordinateur pense recevoir "1", alors que le premier pense avoir envoyé "256" ...

``` c
    htons(); // --> host to network short
    htonl(); // --> host to network long
    ntohs(); // --> network to host short
    ntohl(); // --> network to host long
```




## listen()
<br>
- Si votre serveur devient populaire, vous obtiendrez beaucoup de clients.  
- Souhaitez-vous que les clients attendent dans une file d'attente pour une connexion ?

```c
    // Le 11ème client indiquera au server qu'il est busy
    if (listen(listener_d, 10) == -1)
        error("Can't listen");
```




## accept()
<br>
    - *accept()* attend jusqu'à ce qu'un client contacte le serveur, puis il renvoie un descripteur socket.

```c
    struct sockaddr_storage client_addr;
    unsigned int addresse_size = sizeof(client_addr);
    int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &addresse_size);
    if(connect_d == -1)
        error("Can't connect open secondary socket");
```

    - La discussion est possible !




## send() et close()
<br>
```c
    char msg[] = " - BlahBlah Blah \n - ...\n - Goood bye ! \n";
    send(connect_d, msg, strlen(msg), 0);
    close(connect_d);
```




## Faire du Multithreading avec la librairie pthreads, POSIX.

- Les threads POSIX peuvent rendre votre code plus réactif !
    + Le principe est d'exécuter "plusieurs morceaux de code" en parallèle.
- Mais fais attention !
    + Vous ne voulez pas qu'ils "s'écrasent" les uns dans les autres.




## Des threads... un exemple svp...
- Imaginons que l'on écrive quelque chose de complexe comme un jeu en C.
- Le code devra exécuter plusieurs tâches différentes en même temps :
    + lire les inforamtions du joystick,
    + calculer la nouvelle position des objets qui bougent,
    + mettre à jour l'écran,
    + communiquer avec un server.




## pthread_create()

- On souhaite démarrer deux tâches en parrallèle.
```c
    #include <pthread.h>
    void* task_A(){}
    void* task_B(){}

    int main() {
        pthread_t tA, tB;
        if (pthread_create(&tA, NULL, task_A, NULL) == -1 )  error("Can't create thread tA");
        if (pthread_create(&tB, NULL, task_B, NULL) == -1 )  error("Can't create thread tB");
        ...
    }
```

> gcc ex_Thread.c -lpthread -o ex_Thread.o




## pthread_join()

Ce code exécutera vos deux fonctions dans des threads distincts.
Mais vous n'avez pas encore fini.
Si votre programme a juste exécuté ceci et puis fini, les fils seraient tués quand le programme a fini.
Vous devez donc attendre que vos fils terminent:
    Pthread_join () reçoit également la valeur de retour de votre fonction thread et la stocke dans une variable void pointer.
    Une fois les deux fils terminés, votre programme peut sortir sans problème.
```c
    void* result; // le pointeur void de chaque fonctions (non utilisé ici)
    if (pthread_join(&tA, &result) == -1 )  error("Can't join thread tA");
    if (pthread_join(&tB, &result) == -1 )  error("Can't join thread tB");

```




## Partager une même donnée
*Mettre en place des une signalisation par sémaphores*

<pre>

    __o°o____|___            _______
                 \          /
                  \        /
                   --------
                  /        \
    __o°o____|___/          \_______


</pre>

- La signalistion de trafic qui empêchent les threads de s'écraser les uns contre les autres sont des semaphore,
- Nous utiliserons ici les *mutex* (un type de sémaphore permettant de gérer le partage d'une donnée entre 2 thread).

*MUTEX = MUTually EXclusive.*




## MUTEX de posix

Pour protéger une section de code, vous devez créer un verrou de type mutex de la façon suivante:
pthread_mutex_t a_lock = PTHREAD_MUTEX_INITIALIZER;
Le mutex doit être visible pour tous les threads qui pourraient s'écraser les uns les autres, ce qui signifie que vous voudrez probablement, le créer comme une variable globale.
PTHREAD_MUTEX_INITIALIZER est en fait une macro.
Lorsque le compilateur voit cela, il va insérer tout le code de votre programme a besoin de créer le verrou mutex correctement.
Red signifie arrêter.
Au début de votre section de code sensible, vous devez placer votre premier signal de trafic.
Le pthread_mutex_lock () laissera passer un seul thread.
Tous les autres threads devront attendre quand ils arrivent à it.
Green signifie go.
Quand le thread obtient à la fin du code sensible, il fait un appel à pthread_mutex_unlock ().
Cela remet le signal de trafic en vert et un autre thread est autorisé sur le code sensible:
/ * ... Fin du code sensible * / pthread_mutex_unlock (& ​​a_lock);
Maintenant que vous savez comment créer des verrous dans votre code,
vous avez un beaucoup de contrôle sur exactement comment vos fils fonctionnera.




## MUTEX exemple : 99 bouteilles de bières

*99 bottles of beer on the wall, 99 bottles of beer.*
*Take one down and pass it around, 98 bottles of beer on the wall.*

- 99 bouteilles, 1 Mur et 2 consomateurs (Bob et Dylan).
- Soit une variable a partager et deux tâches réalisant l'opération :

```c
    beer = beer - 1 ;
```

## lock / unlock


## Une librairie tierce pour du rendu graphique : la SDL.

<!--
    - Appels systèmes (+ getenv)
    - Communication par "pipes"
    - Sérialization : protoc-c
-->





