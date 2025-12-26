/*

Rex Jiang
Hangman code that compares a char guess to a string and updates a temp until either complete() or lives lost.

Things I could do better: 
- Have a global constant for MAXLIVES.
- Track repetitive guessing

*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool complete(char temp[]) {
    for (int i=0; temp[i] != '\0'; i++) {
        if (temp[i] == '_') {
            return false;
        } 
    } return true;
}

int main() {
    char target[20] = "hello"; 
    char temp[20];
    char guess;
    int length = strlen(target);

    printf("Your word: ");
    


    //printing original temp
    //temp will be a string that has the number of underscores of the strlen of target

    for (int i=0; i < length; i++) {
        temp[i] = '_'; 
    }
    temp[length] = '\0';
    printf("%s", temp);
    printf("\n");


    

    //what must happen after a letter is guessed?
    //we should check if there are any letters of that same char in the target string
    //we should go through the string array with a for loop?

    int lives = 0;
    while (!complete(temp)) {
        
        bool found = false;
        printf("Guess a letter: \n"); //user guesses a letter
        scanf(" %c", &guess);
        for (int i=0; target[i] != '\0'; i++) { //i now know what index each correct letter is in. 
            if (target[i] == guess) {               // 1st h, if h == h, temp = h----,   
                temp[i] = guess;
                found = true;
            }        
        } 
        if (!found) {
            printf("Incorrect\n");
            lives++;
            printf("\n -- Lives left : %d -- \n", 4 - lives);
        }
        
        printf("%s ", temp);
        printf("\n");

        if (complete(temp)) {
            printf("\n -- You win! --\n");
        } else if (lives >= 4) { 
            printf("\n -- Game Over! -- \n");  
            break;
        }
    }
    




   


}