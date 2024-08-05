#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 /*this function takes string represent it as a credit card number as a input
    and return a value in boolean it can be (TRUE or FALSE)
    */
bool validateCreditCard(const char* cardNumber) {
    int length = strlen(cardNumber);
    int sum = 0;
    bool isSecondDigit=false ;
      for (int i = length - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (isSecondDigit) {
            digit *= 2;

            if (digit > 9) {
                digit = (digit % 10) + 1;
            }
        }

        sum += digit;
        isSecondDigit = !isSecondDigit;
    }

    return (sum % 10) == 0;
}

const char* getCardType(const char* cardNumber) {
    int length = strlen(cardNumber);

    if (length >= 13 && length <= 16) {
        if (cardNumber[0] == '4') {
            return "Visa";
        } else if (cardNumber[0] == '5' && cardNumber[1] >= '1' && cardNumber[1] <= '5') {
            return "Mastercard";
        } else if (cardNumber[0] == '3' && (cardNumber[1] == '4' || cardNumber[1] == '7')) {
            return "American Express";
            } else if (cardNumber[0] == '6' && cardNumber[1] == '0' && cardNumber[2] == '1' && cardNumber[3] == '1') {
            return "Discover";
        }
    }

    return "Unknown";
}
int main()
{
    char cardNumber[20];
    printf("Enter credit card number: ");
    scanf("%s", cardNumber);

    if (validateCreditCard(cardNumber)) {
        const char* cardType = getCardType(cardNumber);
        printf("Credit card number is valid.\n");
        printf("Card type: %s\n", cardType);
    } else {
        printf("Credit card number is invalid.\n");
    }

    return 0;
}
//4263982640269299
//5425233430109903
//374245455400126

