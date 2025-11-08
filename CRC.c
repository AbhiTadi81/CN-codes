#include <stdio.h>
#include <string.h>

int main() {
    char data[50], key[50], temp[50];
    int datalen, keylen, i, j;

    printf("Enter data bits: ");
    scanf("%s", data);
    printf("Enter generator bits: ");
    scanf("%s", key);

    datalen = strlen(data);
    keylen = strlen(key);

    // Append zeros
    strcpy(temp, data);
    for (i = 0; i < keylen - 1; i++)
        strcat(temp, "0");

    // Division using XOR
    char rem[50];
    strcpy(rem, temp);

    for (i = 0; i < datalen; i++) {
        if (rem[i] == '1') {
            for (j = 0; j < keylen; j++)
                rem[i + j] = (rem[i + j] == key[j]) ? '0' : '1';
        }
    }

    // Get remainder
    char crc[20];
    for (i = datalen; i < datalen + keylen - 1; i++)
        crc[i - datalen] = rem[i];
    crc[i - datalen] = '\0';

    printf("\nCRC bits: %s", crc);
    printf("\nTransmitted codeword: %s%s\n", data, crc);

    return 0;
}
