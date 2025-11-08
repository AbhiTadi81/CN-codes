#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of frames to send: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nSending Frame %d...", i);
        printf("\nFrame %d sent successfully.", i);
        printf("\nWaiting for ACK...\n");
        printf("ACK %d received.\n", i);
    }

    printf("\nAll frames sent successfully!\n");

    return 0;
}
