#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool isFourDigitPositiveInteger(const int value) {
    return (value >= 1000 && value <= 9999);
}

static int getData(void) {
    int data = 0;

    while (!isFourDigitPositiveInteger(data)) {
        printf("Enter data to encrypt (four-digit integer): ");
        scanf("%d", &data);

        if (!isFourDigitPositiveInteger(data)) {
            puts("You've entered wrong data. Try, again.");
        }
    }

    return data;
}

static int add7AndRemainderEncryptionStep(const int data) {
    // From leftmost digit to rightmost.
    const int thousands = ((data / 1000) + 7) % 10;
    const int hundreds = ((data / 100 % 10) + 7) % 10;
    const int tens = ((data / 10 % 10) + 7) % 10;
    const int ones = ((data % 10) + 7) % 10;

    return (thousands * 1000) + (hundreds * 100) + (tens * 10) + ones;
}

static int swapEncryptionStep(const int data) {
    const int firstDigit = data / 1000;
    const int secondDigit = data / 100 % 10;
    const int thirdDigit = data / 10 % 10;
    const int fourthDigit = data % 10;

    return (thirdDigit * 1000) + (fourthDigit * 100) + (firstDigit * 10) + secondDigit;
}

static int encrypt(const int data) {
    return
        swapEncryptionStep(
            add7AndRemainderEncryptionStep(data));
}

static int substract7AndMultiplyDencryptionStep(const int data) {
    // From leftmost digit to rightmost.
    const int thousands = (((data / 1000) + 10) - 7) % 10;
    const int hundreds = (((data / 100) + 10) - 7) % 10;
    const int tens = (((data / 10) + 10) - 7) % 10;
    const int ones = (((data % 10) + 10) - 7) % 10;

    return (thousands * 1000) + (hundreds * 100) + (tens * 10) + ones;
}

static int swapDecryptionStep(const int data) {
    int dencryptedData = 0;

    const int firstDigit = data / 1000;
    const int secondDigit = data / 100 % 10;
    const int thirdDigit = data / 10 % 10;
    const int fourthDigit = data % 10;

    // Swap digits.
    dencryptedData += thirdDigit * 1000; // Third to first.
    dencryptedData += fourthDigit * 100; // Fourth to second.
    dencryptedData += firstDigit * 10;   // first to third.
    dencryptedData += secondDigit;       // second to fourth.

    return dencryptedData;
}

static int decrypt(const int data) {
    return
        substract7AndMultiplyDencryptionStep(
            swapDecryptionStep(data));
}

static void printResults(const int encryptedData, const int decryptedData) {
    printf(
        "Encrypted data: %d\n"
        "Decrypted data: %d\n",
        encryptedData,
        decryptedData);
}

// Encrypt and decrypt positive four-digit numbers.
int main(void) {
    const int data = getData();
    const int encryptedData = encrypt(data);
    const int decryptedData = decrypt(encryptedData);

    printResults(encryptedData, decryptedData);

    return EXIT_SUCCESS;
}
