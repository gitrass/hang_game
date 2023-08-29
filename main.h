#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_LENGHT 26

char secretword[WORD_LENGHT];
char guesses[WORD_LENGHT];
int tries = 0;

void drawgui();
void chooseword();
void guessverify();
void readguess();
void addword();
int losecheck();
int wincheck();
