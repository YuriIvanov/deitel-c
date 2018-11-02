#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int getData(void) {
    int data = 0;

    // We need only four-digit values.
    while (data < 1000 || data > 9999) {
        printf("Enter data to encrypt (four-digit integer): ");
        scanf("%d", &data);

        if (data < 1000 || data > 9999) {
            puts("You've entered wrong data. Try, again.");
        }
    }

    return data;
}

static int add7AndRemainderEncryptionStep(const int data) {
    int encryptedData = 0;

    // From leftmost digit to rightmost.
    encryptedData += abs((((data / 1000) + 7) % 10) * 1000);
    encryptedData += abs((((data / 100 % 10) + 7) % 10) * 100);
    encryptedData += abs((((data / 10 % 10) + 7) % 10) * 10);
    encryptedData += abs((((data % 10) + 7) % 10));

    return encryptedData;
}

static int swapEncryptionStep(const int data) {
    int encryptedData = 0;

    const int firstDigit = data / 1000;
    const int secondDigit = data / 100 % 10;
    const int thirdDigit = data / 10 % 10;
    const int fourthDigit = data % 10;

    // Swap digits.
    encryptedData += thirdDigit * 1000; // First to third.
    encryptedData += fourthDigit * 100; // Second to fourth.
    encryptedData += firstDigit * 10;   // Third to first.
    encryptedData += secondDigit;       // Fourth to second.

    return encryptedData;
}

static int encrypt(const int data) {
    return
        swapEncryptionStep(
            add7AndRemainderEncryptionStep(data));
}

static int substract7AndMultiplyDencryptionStep(const int data) {
    int dencryptedData = 0;

    // From leftmost digit to rightmost.
    dencryptedData += abs((((data / 1000) - 7) % 10) * 1000);
    dencryptedData += abs((((data / 100) - 7) % 10) * 100);
    dencryptedData += abs((((data / 10) - 7) % 10) * 10);
    dencryptedData += abs((((data % 10 + 10) - 7) % 10));

    return dencryptedData;
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

void printResults(const int encryptedData, const int decryptedData) {
    printf(
        "Encrypted data: %d\n"
        "Decrypted data: %d\n",
        encryptedData,
        decryptedData);
}

int main(void) {
    const int data = getData();
    const int encryptedData = encrypt(data);
    const int decryptedData = decrypt(encryptedData);

    printResults(encryptedData, decryptedData);

    return EXIT_SUCCESS;
}
