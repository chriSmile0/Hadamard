**//                ME LIRE C'EST IMPORTANT!**

1. Créer une branche : nom_feature_branch
2. Utiliser les merge requests
3. Rebase les commits si il y'a des commits de retards par 
3. (suite) rapport a master
4. Vérification que tout fonctionne et que la nouvelle 
4. fonctionnalité ne perturbe pas le fonctionnement initial
5. Lancement automatique des pipes avant la merge sur master


**//                Etapes de développement!**
1. Makefile
2. Pipe
3. gitignore
4. Prototype de toutes les fonctionnalités demandées
5. Commentaires d'une fonctionnalité avant implémentation 
6. Ajout des matrices G et H dans un fichier annexe



**//                Reponses aux questions!**   
1. Systématique ? Car on a une matrice Identité I devant une matrice A 
1.  de tel sorte que G = (I|A)
1. bits de donnees ? : 4
1. taille des mots du code ? : 16
1. Rendement ? on a un code de longueur 16 , 4 bits de donnees, 12 de contrôle 
1.  On a donc un rendement de [_log2(17)_]+1 = 5.1

42. Distance de Haming = (12,4), donc distance de 8 donc on peut corriger 3 erreurs
5. Cette colonne renvoie tout le temps 0 , mais le soucis c'est qu'elle ne 
    produira pas le même encodage que celui de Hadamard si on l'enlève 
    car cela causera un decalage et on ne sais pas où , du coup on 
    pourrais ne pas decoder correctement le code 
6. 

8. /*
    0011|10000000000
    0101|01000000000
    0110|00100000000
    0111|00010000000
    1001|00001000000
    1010|00000100000
    1011|00000010000
    1100|00000001000
    1101|00000000100
    1110|00000000010
    1111|00000000001
*/
Il s'agit du code de Hamming()

9. Oui un mot encode renvoie bien un syndrome nul si on le decode avec notre fonction decode

10. 1. On peut d'abord créer toutes les erreurs pour savoir ce que donne le syndrome en cas d'erreur sur un 
    bit précis 
    Quand on multiplie H*E on se rend compte que cela renvoie le bit a l'opposé de l'erreur
    Exemple pour l'erreur 0b0100000000000000 decode renvoie 00000000001 donc erreur sur le bit 1
        idem pour 0b0010000000000000 decode renvoie  00000000010 et pour l'erreur 3 cela renvoie 
            000000000100
    On en déduit donc que le reçoit la colonne correspondant a l'erreur mais a l'envers 
    donc pour erreur 0 on reçoit la colonne 14 , et pour erreur 14 la colonne 0 de la matrice H
10. 2. 

12. On cherche d'abord le resultat à la main 
    111000000000000|_111101011001
  - 111101011001   |
  = 000101011001000|
  -    111101011001|
  =    010110010001|
                   |
  On a donc bien un modulo sur 11 bits de 10110010001 , et donc on complète pour arriver sur 15 bits
  ce qui donne 101100100010000 ce qui bien le résultat que l'on voulait 


**//                Fin**

