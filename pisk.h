#ifndef PISK_H_INCLUDED
#define PISK_H_INCLUDED

char pole[26][26];
int body[26][26];
int player, pocit;

void vypis();
int hrac(char *sour, char zn);
void comp(char hr, char pc);
int  cont(char hr, char pc);
void points (char hr, char pc, int i, int j);

#endif // PISK_H_INCLUDED
