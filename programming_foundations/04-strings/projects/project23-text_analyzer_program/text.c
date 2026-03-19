#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char user_para[1024];

    printf("enter a paragraph: ");
    fgets(user_para, sizeof(user_para), stdin);

    user_para[strcspn(user_para, "\n")] = '\0';

    int length = strlen(user_para); 
    int total_words = 0;
    int total_sentences = 0;
    int in_word = 0;

    for (int i = 0; user_para[i] != '\0'; i++) {

        //if we are not in a space and we are not in a word either
        if (isspace(user_para[i]) == 0 && in_word == 0) {
            in_word = 1; //tell the computer we are now in a word
            total_words++;
        }

        //if the current byte is a space and we are currently inside a word.
        else if (isspace(user_para[i]) != 0 && in_word == 1) {
            in_word = 0; //tell the computer we are no longer inside a word.

        }

        if (user_para[i] == '.' || user_para[i] == '!' || user_para[i] == '?') {
            total_sentences++;
        }

    }

    printf("total words:     \t%d\n", total_words);
    printf("total characters:\t%d\n", length);
    printf("total sentences: \t%d\n", total_sentences);

    return 0;
}