#include "fct.h"
#include "matrices.h"


//Codes

unsigned short set_nth_bit(int n , unsigned short m)
{
    (void) n;
    (void) m;
    int true_n = 15-n;
    return (m |= (1 << true_n));
}


unsigned short get_nth_bit(int n , unsigned short m)
{
    int true_n = 15-n;
    return ((m >> true_n) & 1);
}


unsigned short chg_nth_bit(int n , unsigned short m)
{
    (void) n;
    (void) m;
    int value = ((m << n) & 1);
    int inverse = !value;
    printf("inverse : %d\n",inverse);
    return (m |= (inverse << n)); 
}


void print_word(int k , unsigned short m)
{
    printf("0b");
    for(int i = 0 ; i < k ; i++)
        printf("%d",get_nth_bit(i,m));
    printf("\n");
}

 

unsigned short encode_had_sys(unsigned short m)
{
    (void) m;
    unsigned short resultat = 0b0;
    unsigned short extract_mess = m >> 12;
    resultat |= extract_mess;
    int message_by_G_hds_col = 0;
    for(int i = 11 ; i >= 0; i--) {
        message_by_G_hds_col = 0;
        for(int j = 0 ; j < 4 ; j++) {
            int bon_sens = 3-j;
            int bit = (extract_mess >> bon_sens) & 1;
            int result_bit_a_bit = bit*G_hds[j][15-i];
            message_by_G_hds_col += result_bit_a_bit;
        }
        resultat = (resultat << 1 ) | (message_by_G_hds_col % 2);
    }
    return resultat;
}


int cnt_bits(unsigned short n)
{
    int cpt = 0;
    while(n != 0) {
        cpt++;
        n = n & (n-1);
    }
    return cpt;
}



int dist_code_hds() 
{
   return 8;
}


int * cmp_dist_code_hds(unsigned short m)
{
    (void) m;
    return NULL;
}



unsigned short encode_simplexe(unsigned short m)
{
    unsigned short resultat = 0b0;
    unsigned short extract_mess = m >> 12;
    resultat |= extract_mess;
    int message_by_Gs_col = 0;
    for(int i = 11 ; i >= 0; i--) {
        message_by_Gs_col = 0;
        for(int j = 0 ; j < 4 ; j++) {
            int bon_sens = 3-j;
            int bit = (extract_mess >> bon_sens) & 1;
            int result_bit_a_bit = bit*Gs[j][15-i];
            message_by_Gs_col += result_bit_a_bit;
        }
        resultat = (resultat << 1 ) | (message_by_Gs_col % 2);
    }
    return resultat;
}


unsigned short decode(unsigned short m)
{
    //Hs par m 
    int nb_row_hs = 16;
    int nb_col_hs = 15;
    unsigned short resultat = 0b0;
    unsigned short extract_mess = m;
    int true_colonne = 0;
    int message_by_Hs_col = 0;
    for(int i = 0 ; i < nb_row_hs ; i++) {
        message_by_Hs_col = 0;
        true_colonne = 0;
        for(int j = nb_col_hs ; j >= 0 ; j--) {
            int bon_sens = j;
            int bit = (extract_mess >> (bon_sens)) & 1;
            int result_bit_a_bit = bit*Hs[i][true_colonne];
            true_colonne++;
            message_by_Hs_col += result_bit_a_bit;
        }
        resultat = (resultat << 1)  | (message_by_Hs_col % 2);
    }
    return resultat;
}


unsigned short mod_poly_simplex(unsigned short m)
{
    (void) m;
    int true_depart = 0;
    for(int i = 14; i >= 0; i--) {
        int bit = (m >> i) & 1;
        if(bit == 1) {
            true_depart = i;
            i = 0;
        }
    }
    unsigned short G_x = 0b000111101011001;
    int nb_0_in_div = true_depart-11;//le nombre de 0 qui ne sont baisser car on 
                                    //fait un X**15 sur un X**1 en ôtant le dernier
                                    //bit donc sur 15 bit

    int stop_search_1 = 0;
    unsigned short resultat = 0b0;
    int cpt = 0;
    int goon = 1;
    int fin = 0;
    int decalage = 0;
    while(goon) {
        stop_search_1 = 0;
        cpt++;
        unsigned short copie_m = m;
        if(cpt > 1) {
            copie_m = resultat;
            resultat = 0b0;
            int vrai_depart = 0;
            for(int i = 14 ; i >= 0; i--) {
                int bit = (copie_m >> i) & 1;
                if(bit == 1) {
                    vrai_depart = i;
                    i = -1;
                }    
            }
            true_depart = vrai_depart;
        }
        else if(cpt == 1){
            copie_m = m;
        }
        decalage = 0;
        int true_fin = (true_depart-11);
        for(int i = true_depart; i >= true_fin ; i--) {
            int bit_p = (copie_m >> (i)) & 1;
            int bit_g = G_x >> (i-true_fin) & 1;
            int bit_diff = (bit_p + bit_g) %2;
            if((bit_diff == 1) && (stop_search_1==0)) {
                decalage = true_depart-i;
                nb_0_in_div -= true_depart-i;
                stop_search_1 = 1;
            }
            resultat = (resultat << 1) | bit_diff;
        }
        print_word(16,resultat);
        if(nb_0_in_div > 0) {
            for(int i = 0 ; i < (decalage); i++)
                resultat = (resultat << 1) | 0;
        }
        if((cpt == 1) && (nb_0_in_div < 0))//cas particulier de P et G de même taille
            goon = 0;
        if(fin == 1)
            goon = 0;
        if(nb_0_in_div <= 0)
            fin = 1;
        
    }
    //ajout des zéros
    int first_one = -1;
    for(int i = 15; i >= 0 ;i--) {
        int bit = (resultat >> i) & 1;
        if(bit == 1) 
            if(first_one == -1)
                first_one = i;
    }

    int decal = 15-first_one;
    for(int i = 0 ; i < decal; i++)
        resultat = (resultat << 1) | 0;
    return resultat;
}



unsigned short decode_poly(unsigned short m)
{
    (void) m;
    int decal_bit = 0;
    unsigned short copie_m = m;
    int nb_decalage = 0;
    while(1) {
        if(cnt_bits(copie_m) < 3)
            break;
        else {
            decal_bit = get_nth_bit(0,copie_m);//((copie_m>>14) & 1);
            copie_m = (copie_m << 1);
            copie_m |= decal_bit;
            copie_m = (copie_m << 1);
            nb_decalage++;
        }
        copie_m = mod_poly_simplex(copie_m);
    }
    copie_m = copie_m >> nb_decalage;
    return copie_m;
}




/*****************************************BONUS PERSO*************************/

struct multi_syndrome syndromes_erreurs()
{
    struct multi_syndrome m_s;
    for(int i = 15 ; i >= 1 ; i--) {
        unsigned short mess_error = 0b1;
        m_s.m_shorts[i-1] = decode((mess_error << i));
        printf("i : %d \t erreur : ",15-(i));
        print_word(11,m_s.m_shorts[i-1]);
    }
    return m_s;
}

struct multi_erreur erreurs()
{
    struct multi_erreur m_e;
    for(int i = 0 ; i < 15; i++) {
        unsigned short mess_error = 0b1;
        m_e.m_shorts[i] = mess_error << i;
    }
    return m_e;
}
