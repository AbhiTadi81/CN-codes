#include <stdio.h>

int main()
{
    int data[7], recv[7];
    int p1, p2, p3, c1, c2, c3, error;

    // Step 1: Input 4 data bits
    printf("Enter 4 data bits (D1 D2 D3 D4): ");
    scanf("%d %d %d %d", &data[2], &data[4], &data[5], &data[6]);

    // Step 2: Calculate parity bits (even parity)
    data[0] = data[2] ^ data[4] ^ data[6]; // P1
    data[1] = data[2] ^ data[5] ^ data[6]; // P2
    data[3] = data[4] ^ data[5] ^ data[6]; // P3

    // Step 3: Display encoded data
    printf("\nEncoded bits (P1 P2 D1 P3 D2 D3 D4): ");
    for (int i = 0; i < 7; i++)
        printf("%d ", data[i]);

    // Step 4: Input received bits
    printf("\n\nEnter received 7 bits: ");
    for (int i = 0; i < 7; i++)
        scanf("%d", &recv[i]);

    // Step 5: Recalculate parity
    c1 = recv[0] ^ recv[2] ^ recv[4] ^ recv[6];
    c2 = recv[1] ^ recv[2] ^ recv[5] ^ recv[6];
    c3 = recv[3] ^ recv[4] ^ recv[5] ^ recv[6];

    // Step 6: Find error position
    error = c3 * 4 + c2 * 2 + c1 * 1;

    if (error == 0)
        printf("\nNo error detected!");
    else
    {
        printf("\nError detected at position: %d", error);
        recv[error - 1] = recv[error - 1] ^ 1; // Correct the bit
        printf("\nCorrected data: ");
        for (int i = 0; i < 7; i++)
            printf("%d ", recv[i]);
    }

    return 0;
}