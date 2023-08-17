#include <stdio.h>

int main() {
    char expression[100];
    printf("Enter a parentheses expression: ");
    scanf("%s", expression);

    int longestSymmetry = 0;
    int currentSymmetry = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            int j = i + 1;
            int count = 1;
            while (expression[j] != '\0' && count > 0) {
                if (expression[j] == '(') {
                    count++;
                } else if (expression[j] == ')') {
                    count--;
                }
                j++;
            }
            if (count == 0) {
                currentSymmetry = j - i;
                if (currentSymmetry > longestSymmetry) {
                    longestSymmetry = currentSymmetry;
                }
            }
        }
    }

    if (longestSymmetry > 0) {
        printf("The longest symmetric substring has length: %d\n", longestSymmetry);
    } else {
        printf("No symmetric substring found.\n");
    }

    return 0;
}