#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int card;
    int option;
    float value, balance = 1000;

    printf("Welcome to our bank.\n");
    printf("Type your card number to continue: \n");
    scanf("%lu", &card);

    if (card < 40000000)
    {
        printf("Sorry... Invalid card, try again.");
        system("cls");
        main();
    }
    else
    {
        printf("Type the option you want: \n");
        printf("1 withdrawal 2 Deposit 3 View balance \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the amount to be withdrawn: Ex: 2000: \n");
            scanf("%f", &value);
            if (balance - value < 0)
            {
                printf("Invalid operation, try again.");
                system("pause");
                system("cls");
                main();
            }
            else
            {
                balance = balance - value;
                printf("OK, your balance is \n");
                printf("%f\n", balance);
                option = 1;
            }
            break;

        case 2:
            printf("Enter the amount to be deposited: Ex; 2000");
            scanf("%f", &value);
            balance = balance + value;
            printf("OK, your balance is \n");
            printf("%f\n", balance);
            break;

        case 3:
            printf("OK, your balance is \n");
            printf("%f\n", balance);
            break;
        }
    }
    system("pause");
    system("cls");
    main();
    return 0;
}
