#ifndef MATRICES_H 
#define MATRICES_H
//nom[nb_ligne][nb_colonne]

unsigned short G_hds[4][16] = {{1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
                    {0,1,0,0,0,0,1,1,1,0,0,0,1,1,1,1},
                    {0,0,1,0,0,1,0,1,1,0,1,1,0,0,1,1},
                    {0,0,0,1,0,1,1,0,1,1,0,1,0,1,0,1}
                    };
/*
G_hds[0] = {1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1};
G_hds[1] = {0,1,0,0,0,0,1,1,1,0,0,0,1,1,1,1};
G_hds[2] = {0,0,1,0,0,1,0,1,1,0,1,1,0,0,1,1};
G_hds[3] = {0,0,0,1,0,1,1,0,1,1,0,1,0,1,0,1};*/

/*Il suffit de transposer la matrice pour avoir H*/
//0000|100000000000
//0011|010000000000
//0101|001000000000
//0110|000100000000
//0111|000010000000
//1001|000001000000
//1010|000000100000
//1011|000000010000
//1100|000000001000
//1101|000000000100
//1110|000000000010
//1111|000000000001
unsigned short H_hds[12][16];



unsigned short Gs[4][15] =  {{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
                    {0,1,0,0,0,1,1,1,0,0,0,1,1,1,1},
                    {0,0,1,0,1,0,1,1,0,1,1,0,0,1,1},
                    {0,0,0,1,1,1,0,1,1,0,1,0,1,0,1}
                    };


//0011|10000000000
//0101|01000000000
//0110|00100000000
//0111|00010000000
//1001|00001000000
//1010|00000100000
//1011|00000010000
//1100|00000001000
//1101|00000000100
//1110|00000000010
//1111|00000000001
int Hs[11][15] = {{0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
                             {0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
                             {0,1,1,0,0,0,1,0,0,0,0,0,0,0,0},
                             {0,1,1,1,0,0,0,1,0,0,0,0,0,0,0},
                             {1,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
                             {1,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
                             {1,0,1,1,0,0,0,0,0,0,1,0,0,0,0},
                             {1,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
                             {1,1,0,1,0,0,0,0,0,0,0,0,1,0,0},
                             {1,1,1,0,0,0,0,0,0,0,0,0,0,1,0},
                             {1,1,1,1,0,0,0,0,0,0,0,0,0,0,1}
                            };

#endif //MATRICES_H