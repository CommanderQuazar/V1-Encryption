//
// Created by Tobey Ragain on 1/11/20.
//
/* This program will will encrypt and decrypt strings. First it will scan an input to verify the access key.
 * Then it will prompt the user to enter a string to be encrypted and vise versa with the decryption.
 */


#include <stdio.h>
#include <string.h>
#define MAX 500

int userInputKey;
char gMessage[MAX];
char gEncryptMessage[MAX];
int userKey = 17683459;
//Alpha library
char gKeyAlpha[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                            'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                            's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};

//Cipher library
char gKeySymbol[27] = {'!', '@', '#', '$', '%', '^', '&', '*', '(',
                            '?', '/', ',', '>', ')', '<', '-', '_', ']',
                            '|', '`', '~', '.', '=', '6', '+', 's', 't'};


long linear_search(char a[], long n, char find) {           // Function to get index points of library character location
    long c;

    for (c = 0 ;c < n ; c++ ) {
        if (a[c] == find)
            return c;
    }

    return -1;
}


char encrypt(char userMessage[])            // encrypts the input
{
    char alphaArr[99];
    char encryptedMessage[99];
    int i;
    int j;

    if (userMessage == 00) {            //checks if user wants to continue

        return 0;
    }

    printf("Your encrypted message is : ");
    for (i = 0; i < strlen(userMessage); i++) {         // assembles a list of index locations
        alphaArr[i] = linear_search(gKeyAlpha, strlen(gKeyAlpha), userMessage[i]);
    }

    for (j = 0; j < strlen(userMessage) ; j++) {            // matches index locations of user message with points of the symbol library
        encryptedMessage[j] = gKeySymbol[alphaArr[j]];
        printf("%c", encryptedMessage[j]);
    }
    printf("\n");
    return 0;
}



char decrypt(char encryptedMessage[])           // decrypts the input
{
    char symbolArr[99];
    char decryptedMessage[99];
    int i;
    int j;


    if (encryptedMessage == 0) {            //checks if user wants to continue
        return 0;
    }

    printf("Your decrypted message is : ");
    for (i = 0; i < strlen(encryptedMessage); i++) {            // assembles a list of index locations of symbols
        symbolArr[i] = linear_search(gKeySymbol, strlen(gKeySymbol), encryptedMessage[i]);
    }

    for (j = 0; j < strlen(encryptedMessage) ; j++) {           // finds the indexes that match to the alpha library
        decryptedMessage[j] = gKeyAlpha[symbolArr[j]];
        printf("%c", decryptedMessage[j]);
    }

    printf("\n");
    return  0;
}



int main(void)
{

    printf("Enter the encryption key to access this program\n");            //gets user input for the access key
    scanf("%d", &userInputKey);

    if (userKey != userInputKey) {
        printf("Incorrect key, try again\n");
        return 0;
    }


    printf("Enter the message you would like to encrypt. (All lower case)\n");
    scanf("%d", &userInputKey);          /*
 *                                        Maybe balances the userInputKey and UserInput vars to work together, but essential to the overall function of program??
                                        */


    scanf("%[^\n]%*c", gMessage);
    encrypt(gMessage);

    printf("Enter the message you would like to decrypt.\n");
    scanf("%[^\n]%*c", gEncryptMessage);
    decrypt(gEncryptMessage);

    return 0;

}


