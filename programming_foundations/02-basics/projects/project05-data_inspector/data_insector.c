#include <stdio.h>

int main() 
{
    int integer_value;
    char char_value;

    printf("enter a integer (e.g. 1, 89, 302, etc.): ");
    scanf("%d", &integer_value);
    printf("enter a symbol (e.g. 1, 6, H, j, !, etc.): ");
    scanf(" %c", &char_value);

    printf("--- INSPECTION REPORT --- \n");
    printf("Symbol: %c -> ASCII code: %d\n", char_value, char_value);
    printf("Next Symbol: %c\n", char_value + 1);
    printf("                                   \n");
    printf("Integer: %d\n", integer_value);
    printf("Hex View: %x\n", integer_value);
    printf("Last Digit: %d\n", integer_value % 10);
    printf("                                   \n");
    printf("Storage Check: \n");
    printf("Char takes %lu byte(s)\n", sizeof(char_value));
    printf("Integer takes %lu byte(s)\n", sizeof(integer_value));

    return 0;
}