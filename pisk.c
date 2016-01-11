#include <stdio.h>
#include <stdlib.h>
#include "pisk.h"

void vypis (){
    int i, j, k=1;

    printf("\n   A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
    for(i=0;i<26;i++){
        printf("%2d ",k++);
        for(j=0;j<26;j++){
            printf("%c ",pole[i][j]);
        }
        printf("\n");
    }
}

int hrac(char *sour, char zn){
    char ctver=254;
    int srow, spill;
    if((sour[0]>='A' && sour[0]<="Z") && (sour[1]>='1' && sour[1]<="9") && (sour[2]<7 || sour[2]>9) && sour[3]==NULL){
        spill=sour[0]-65;
        if(sour[2]<'0' || sour[2]>'9')
            srow=sour[1]-48;
        else
            srow=(sour[1]-48)*10+(sour[2]-48);

        if(pole[srow-1][spill]!=ctver){
            printf("\nPolicko jiz obsazeno.");
            return 1;
        }
        else{
            pole[srow-1][spill]=zn;
        }
    }else{
        printf("\nZadal jsi spatne souradice... Nutno zadat ve tvaru CHARnum, pr:A10");
        return 1;
    }
    return 0;
}

void points (char hr, char pc, int i, int j){
    if(pole[i][j]==hr){
        player++;
        pocit=0;
    }else if(pole[i][j]==pc){
        pocit++;
        player=0;
    }else{
        if(pocit!=0){
            switch(pocit){
                case 1: body[i][j]+=10; break;
                case 2: body[i][j]+=20; break;
                case 3: body[i][j]+=50; break;
                case 4: body[i][j]+=1000; break;
            }
        }else if(player!=0){
            switch(player){
                case 1: body[i][j]+=5; break;
                case 2: body[i][j]+=15; break;
                case 3: body[i][j]+=40; break;
                case 4: body[i][j]+=500; break;
            }
        }else{
            body[i][j]+=0;
        }
        player=0;
        pocit=0;
    }
}

void comp(char hr, char pc){
    int i, j, k=25, l=0, high=1, m=0, n=0;
    player=0;
    pocit=0;

    for(i=0;i<26;i++){                              //radky ->
        for(j=0;j<26;j++){
            points(hr, pc, i, j);
        }
        player=0;
        pocit=0;
    }


    for(i=25;i>=0;i--){                              //radky <-
        for(j=25;j>=0;j--){
            points(hr, pc, i, j);
        }
        player=0;
        pocit=0;
    }

    for(j=0;j<26;j++){                              //sloupce down
        for(i=0;i<26;i++){
            points(hr, pc, i, j);
        }
        player=0;
        pocit=0;
    }

    for(j=25;j>=0;j--){                              //sloupce up
        for(i=25;i>=0;i--){
            points(hr, pc, i, j);
        }
        player=0;
        pocit=0;
    }


    while(l<26){

        for(i=l, j=k; i<26 && i>=0 && j<26 && j>=0; i++, j++){         //uhlopricky ->down
            points(hr, pc, i, j);
            }
        player=0;
        pocit=0;
        for(i=25-l, j=k; i<26 && i>=0 && j<26 && j>=0; i--, j++){      //uhlopricky ->up
            points(hr, pc, i, j);
            }
        player=0;
        pocit=0;
        for(i=k, j=25-l; i<26 && i>=0 && j<26 && j>=0; i++, j--){            //uhlopricky <-down
            points(hr, pc, i, j);
            }
        player=0;
        pocit=0;
        for(i=25-k, j=25-l; i<26 && i>=0 && j<26 && j>=0; i--, j--){         //uhlopricky <-up
            points(hr, pc, i, j);
            }
        player=0;
        pocit=0;
        if(k>0)
            k--;
        else
            l++;
    }

    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            if(body[i][j]>high){
                high=body[i][j];
                m=i;
                n=j;
            }
        }
    }
    pole[m][n]=pc;

    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            body[i][j]=0;
        }
    }
}

int  cont(char hr, char pc){
    int i, j;
    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            if((pole[i][j]==hr && pole[i][j+1]==hr && pole[i][j+2]==hr && pole[i][j+3]==hr && pole[i][j+4]==hr)
                || (pole[i][j]==hr && pole[i+1][j]==hr && pole[i+2][j]==hr && pole[i+3][j]==hr && pole[i+4][j]==hr)
                || (pole[i][j]==hr && pole[i+1][j+1]==hr && pole[i+2][j+2]==hr && pole[i+3][j+3]==hr && pole[i+4][j+4]==hr)
                || (pole[i][j]==hr && pole[i+1][j-1]==hr && pole[i+2][j-2]==hr && pole[i+3][j-3]==hr && pole[i+4][j-4]==hr)){
                vypis();
                printf("\nVyraj jsi!!!");
                return 1;
            }
            if((pole[i][j]==pc && pole[i][j+1]==pc && pole[i][j+2]==pc && pole[i][j+3]==pc && pole[i][j+4]==pc)
                || (pole[i][j]==pc && pole[i+1][j]==pc && pole[i+2][j]==pc && pole[i+3][j]==pc && pole[i+4][j]==pc)
                || (pole[i][j]==pc && pole[i+1][j+1]==pc && pole[i+2][j+2]==pc && pole[i+3][j+3]==pc && pole[i+4][j+4]==pc)
                || (pole[i][j]==pc && pole[i+1][j-1]==pc && pole[i+2][j-2]==pc && pole[i+3][j-3]==pc && pole[i+4][j-4]==pc)){
                vypis();
                printf("\nProhraj jsi :(");
                return 1;
            }
        }
    }
    return 0;
}



