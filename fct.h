#ifndef FCT_H 
#define FCT_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//structs
struct multi_syndrome {
    unsigned short m_shorts[16];
};

struct multi_erreur {
    unsigned short m_shorts[15];
};


//PROTOTYPES

/**
 * @Question : 1 (s-g-c-p)
 * @version : 1 
 * 
 * @brief : Prend en argument un entier n et met le n_ieme bit du mot
 *          m a 1
 *          N'oublions pas que l'on va de la droite vers la gauche 
 *          pour le ieme bit donc sur un message de 16 bits le 2eme bit est
 *          le 2eme en partant de la droite
 * 
 * @param[:n] : un entier = ième bit 
 * @param[:m] : le message
 * 
 * @return le message modifie
*/
unsigned short set_nth_bit(int n , unsigned short m);

/**
 * @version : 1 
 * 
 * @brief : Retourne la valeur du bit a la n-ieme position du mot m
 *          Ici on part du poids fort vers le poids faible 
 *          donc si on veut le 2eme bit de poids faible on prend le 14eme bit 
 *          de poids pour fort dans cette fonction pour un message de 16 bits
 * 
 * @param[:n] : un entier = ieme bit
 * @param[:m] : le message
 * 
 * @return 0 ou 1
*/
unsigned short get_nth_bit(int n , unsigned short m);

/**
 * @version : 1 
 * 
 * @brief Change la valeur n-ieme bit du message
 * 
 * @param[:n] : un entier = ieme bit
 * @param[:m] : le message
 * 
 * @return le message modifie
*/
unsigned short chg_nth_bit(int n , unsigned short m);

/**
 * @version : 1 
 * 
 * @brief : Print les k premiers bits du message m 
 * 
 * @param[:k] : 
 * @param[;m] : le message 
 * 
 * @return /
*/
void print_word(int k , unsigned short m);

 
/**
 * @Question : 3
 * @version : 1 
 * 
 * @brief : Encodage du systeme d'Hadamard
 * 
 * @param[:m] : le message 
 * 
 * @return le message coder
*/
unsigned short encode_had_sys(unsigned short m);

/**
 * @Question : 4.1
 * @version : 1 
 * 
 * @brief : Compte le nombre de bits a 1 dans n 
 *          Suivre Brain-Kernighan
 * 
 * @param[:n] : le message 
 * 
 * @return le nombre de 1 dans le message >= 0
*/
int cnt_bits(unsigned short n);

/**
 * @Question : 4.2
 * @version : 1 
 * 
 * @brief : Calcul la distance de Haming du code 
 * 
 * @param[/]
 * 
 * @return la distance de Haming >= 1
*/
int dist_code_hds();


/**
 * @Question : 4.3
 * @version : 1 
 * 
 * @brief : Comparer les distances entre toutes les paires de mots du code 
 *          valide
 * 
 * @param[:m] : le message
 * 
 * @return un tableau de distance en fonction du nombre de mot valide
*/
int * cmp_dist_code_hds(unsigned short m);

/**
 * @Question : 6
 * @version : 1 
 * 
 * @brief : Encode un message selon la matrice Generatrice
 * 
 * @param[:m] : le message m 
 * 
 * @return Encodage via simplexe
*/
unsigned short encode_simplexe(unsigned short m);


/**
 * @Question : 9
 * @version : 1 -> 2 :  Q10.2
 * 
 * @brief v1: Renvoie du syndrome du message par H 
 * 
 * @brief v2: 
 * 
 * @param[:m] : le message m  
 * 
 * @return retourne le syndrome (1..0) (taille = 12)
*/
unsigned short decode(unsigned short m);

/**
 * 10.1 suite 
 * 
 * @brief : Donner une erreur a un message valide
 * 
 * 
 * 
*/

unsigned short add_error_and_message(unsigned short message, 
                                        unsigned short error);


/**
 * @Question : 12
 * @version : 1 
 * 
 * @brief : Implementez le registre a decalage de la Q11
 * 
 * @param[:m] : le message m 
 * 
 * @return Renvoies des bits de contrôle (P%G)
*/
unsigned short mod_poly_simplex(unsigned short m);

/**
 * @Question : 13
 * @version : 1 
 * 
 * @brief : Correction du message m en entrant par codage polynomial
 * 
 * @param[:m] : le message ù 
 * 
 * @return le message decoder
*/
unsigned short decode_poly(unsigned short m);




/***************************************BONUS PERSO***************************/
/**
 * @Question : QB 1 
 * @version : 1 
 * 
 * @brief : Creation de tout les syndromes pour 1 bit d'erreur
 * 
 * @param[:/] 
 * 
 * @return matrice des syndromes en fonction du bit d'erreur
*/
struct multi_syndrome syndromes_erreurs();

/**
 * @Question : QB 2 
 * @version : 1 
 * 
 * @brief : Création de tout les bits d'erreurs : 
 *          0b100.000 , 0b0100..000 ,....., 0b0000000000000001 
 * 
 * @param[:/] 
 * 
 * @return matrice qui contient toutes les erreurs sur chaque bit
*/

struct multi_erreur erreurs();


/*****************************************BONUS*******************************/


/***************************************FIN BONUS*****************************/

#endif //FCT_H