#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pisk.h"

int main()
{

    int i, j, p, win, s=0;
    char sour[4], hr, pc;

    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            body[i][j]=0;
        }
    }
    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            pole[i][j]=254;
        }
    }

    vypis();

    do{
        printf("\nVyber si sve poradi (1/2):");
        scanf("%d",&p);
        while (getchar() != '\n');
    }while(p<1 || p>2);
    if(p==1){
        hr='o';
        pc='x';
    }else{
        hr='x';
        pc='o';
        pole[12][12]=pc;
        vypis();
    }

    while(1){
        printf("\nZadej souradnice tveho tahu:");
        gets(sour);
        while (getchar() != '\n');
        s=hrac(sour, hr);
        if(s==1)
            continue;
        win=cont(hr,pc);
        if(win==1)
            break;
        comp(hr, pc);
        vypis();
        win=cont(hr,pc);
        if(win==1)
            break;
    }

    // 1=49 A=65
    scanf("%c", &hr);

    return 0;
}
