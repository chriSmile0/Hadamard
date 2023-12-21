#include "fct.h"


int main() {
    unsigned short message = 0b0111000000000000;
    message = set_nth_bit(15,message);
    printf("get : %d\n",get_nth_bit(3,message));
    printf("chg : %d\n",chg_nth_bit(1,message));
    print_word(16,message);


    unsigned short encode_had = encode_had_sys(message);
    printf("Encode had: %d\n",encode_had);//ok
    print_word(16,encode_had);

    printf("Nb bits 1 in message : %d\n",cnt_bits(message));
    unsigned short encode_simplex = encode_simplexe(message);
    printf("Encode simplexe : %d\n",encode_simplex);
    print_word(15,encode_simplex);


    unsigned short simplex_message = 0b1010101010101010;
    unsigned short decode_simplex = decode(simplex_message);
    printf("decode simplex :");
    print_word(11,decode_simplex);


    
    unsigned short test_1 = 0b00000000000000;//fait partit des message qui fonctionne, mais un message de 0 c'est un ridicule 
    unsigned short decode_simplex2 = decode(test_1);
    print_word(11,decode_simplex2);


    //verification du decodage avec l'encodage
    unsigned short decode_encode_simplex = decode(encode_simplex);
    print_word(11,decode_encode_simplex);//oui donc ok 



    struct multi_syndrome s_m;
    s_m = syndromes_erreurs();  
    printf("%d\n",s_m.m_shorts[1]);



    printf("*************************ERREURS***********************\n");
    printf("************************Exemple 1**********************\n");
    unsigned short message_error = 0b0000000000000100;//16 bits d'erreurs possible
                                                    //déplacé le 1 pour voir qu'elle erreur représente quoi
    /*unsigned short resultat_add_mess1_err = add_error_and_message(message_test,s_m.m_shorts[1]);//add_error_and_message(simplex_message,s_m.m_shorts[10]);*/
    unsigned short decode_message_error = decode(message_error);
    printf("error : ");
    print_word(11,decode_message_error);
    
    unsigned short message_test_error = 0b0100000000000000;//15 bits
    message_test_error |= message_error;
    printf("message + error : ");
    print_word(15,message_test_error);
    unsigned short decode_message_test_error = decode(message_test_error);
    print_word(11,decode_message_test_error);

    printf("************************Exemple 2**********************\n");
    unsigned short message_error2 = 0b0000000010000000;//16 bits d'erreurs possible
                                                    //déplacé le 1 pour voir qu'elle erreur représente quoi
    /*unsigned short resultat_add_mess1_err = add_error_and_message(message_test,s_m.m_shorts[1]);//add_error_and_message(simplex_message,s_m.m_shorts[10]);*/
    unsigned short decode_message_error2 = decode(message_error2);
    printf("error 2: ");
    print_word(11,decode_message_error2);
    
    unsigned short message_test_error2 = 0b0100100000000000;//15 bits
    message_test_error2 |= message_error2;
    printf("message + error 2: ");
    print_word(15,message_test_error2);
    unsigned short decode_message_test_error2 = decode(message_test_error2);
    print_word(11,decode_message_test_error2);

    /** @version 10.2 !!!!!!!!!!!!*****10.2******!!!!!!!!!!!!!!!!!
     * @brief :
     * Pour celui ci on a une erreur à l'arrière donc on peut déjà la retirer 
     * pour voir plus claire il s'agit donc du 8ème bit d'erreur 
     * on cherche donc le syndrome correspondant on trouve 0b00001000000 donc on retire celui
     * ci au syndrome on trouve le syndrome : 0b111101001111
     * 
     * Il faut donc maintenant trouver les erreurs suivantes :
     *      On peut voir que la fin de ce syndrome ressemble 
     *      beaucoup a celui de l'erreur sur le bit 1 (comme avant)
     *      On en déduit que on a bien une erreur la dessus
     *      et donc on fait le syndrome - cette erreur
     *      on trouve 0b10001000000 , on sait donc qu'il reste l'erreur
     *      sur le bit 4 et celle sur le bit 8
     * 
     *      Donc au final le message corrigé ressemblera a à l'inverse 
     *      du message reçu sur les bits correspondants 
     *      mais comme on peut thériquement que corriger 4 erreurs 
     *      on se pose la question de la pertinence de cette réfléxion
     *      
     * 
     *      
     * 
     * 
    */

    printf("************************Exemple 3 : 0b00010011001**********************\n");
    unsigned short message_entree = 0b1010101010101010;
    unsigned short syndrome_retour = 0b0001001100100000;//est ce que l'on peut le corriger ?
    printf("message entree : ");
    print_word(11,message_entree);
    printf("syndrome : ");
    print_word(11,syndrome_retour);

    s_m = syndromes_erreurs();

    /**
     * Comme on le sais on peut corriger que 4 erreurs 
     * donc la théorie serais que le bit 0 n'est pas en erreur 
     * 
     * 
     * 
    */

   printf("************************Exemple 4 : 0b0011101001001010**********************\n");
    unsigned short message_entree4 = 0b0011101001001010;



    unsigned short renvoie_demander = 0b1101101001001010;//est ce que l'on peut le corriger ?
    printf("message entree : ");
    print_word(16,message_entree4);
    printf("syndrome calculer par ma fonction decode: ");
    unsigned short my_decode_entree4 = decode(message_entree4);
    print_word(11,my_decode_entree4);
    unsigned short decode_again = decode(my_decode_entree4);
    print_word(11,decode_again);
    unsigned short decode_again_again = decode(decode_again);
    print_word(11,decode_again_again);

    printf("syndrome demander : ");
    print_word(16,renvoie_demander);

    //faire une version de decode qui decode déchiffre les 3 erreurs qui se cache dans le message entree 4

    s_m = syndromes_erreurs();

    /**
     * Comme on le sais on peut corriger que 3 erreurs 
     * donc la théorie serais que le bit 0 n'est pas en erreur 
     * 
     * 
     * 
    */

    printf("**********************POLYNOME*******************\n");
    //Q12
    unsigned short P_x = 0b111000000000000;//15 bits , //fonctionne
    unsigned short question_12 = mod_poly_simplex(P_x);
    print_word(15,question_12);
    //unsigned short other_px = 0b110110000000000;//test pour voir si notre fonction est juste //fonctionne
    /*unsigned short other_other_px = 0b000110000000000; //fonctionne
    //unsigned short other_2_px = 0b010110000000000;//fonctionne
    unsigned short question_12_other = mod_poly_simplex(other_other_px);
    print_word(15,question_12_other);*/

    //Q13
    //Utilisation du résultat q12 du pdf 
    //unsigned short rep_Q12 = 0b101100100010000;
    unsigned short exemple_q13 = 0b101110010111010;
    unsigned short decode_polynome = decode_poly(exemple_q13);//fonctionnera si Q12 juste
    printf("polynome decode : \n");
    print_word(15,decode_polynome);

    //Q14
    
    return 0;
}