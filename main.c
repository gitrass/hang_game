#include "main.h"

void drawgui(){
    printf("--------------\n");
    printf("  HANG GAME\n");
    printf("--------------\n");
}

void addword(){
    char input;
    printf("Do you want to add a new word to the game? [Y/N]:");
    scanf(" %c", &input);
    if(input == 'Y'){
        char addword[WORD_LENGHT];
        printf("Type the word: ");
        scanf("%s", addword);

        FILE* f;
        f = fopen("words.txt", "r+");
        if(f==0){printf("Error loading file.\n"); exit(1);}

        int words;
        fscanf(f, "%d", &words);
        words++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", words);
        fseek(f, 0, SEEK_END);

        fprintf(f, "\n%s", addword);
        fclose(f);
    }
}

void chooseword(){
    FILE* f;
    f = fopen("words.txt", "r");
    if(f==0){printf("Error loading file."); exit(1);}

    int words;
    fscanf(f, "%d", &words);

    srand(time(NULL));
    int rnumber = rand() % words;

    for(int i = 0; i <= rnumber; i++){fscanf(f, "%s", secretword);}

    fclose(f);
}

int foundcheck(char letter){
    int found = 0;
    for(int j= 0; j < tries; j++){
        if(guesses[j] == letter){
            found = 1;
            break;
                }
            }
        return found;
}

void guessverify() {
    printf("   ");
    for(int i = 0; i < strlen(secretword); i++){
            int found = foundcheck(secretword[i]);
            if(found){
                printf("%c", secretword[i]);
            }
            else{
                printf("_");
            }
        }
    printf("\n");
    printf("--------------\n");
}

void readguess(char guesses[WORD_LENGHT], int* tries){
    char guess;
    printf("Guess: ");
    scanf(" %c", &guess);
    printf("--------------\n");
    guesses[(*tries)] = guess;
    (*tries) ++;
    if(wrongtries == 1){
        printf("Wrong tries [MÁX. 6]: %d\n", wrongtries);
    }
}

int losecheck(){
    wrongtries = 0;
    for(int i = 0; i < tries; i++){
        int check = 0;
        for(int j = 0; j < strlen(secretword); j++){
            if(guesses[i] == secretword[j]){
                check = 1;
                break;
            }
        }
        if(!check) wrongtries++;
    }
    return wrongtries >= 6;
}

int wincheck(){
    for(int i = 0; i < strlen(secretword); i++){
        if(!foundcheck(secretword[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    drawgui();
    chooseword();
    do
    {
        readguess(guesses, &tries);
        guessverify();
    } while (!wincheck() && !losecheck());{
        }
        if(wincheck()){
            printf("Congratulations!");
        } else {
            printf("Try next time!");
        }
        addword();
}
