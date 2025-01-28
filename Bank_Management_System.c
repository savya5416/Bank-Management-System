#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

char name[20];
int dip_amt,amt=100000,acc_no,with_amt,trans_amt;
int i;
int count =0;

void menu();
void deposit_money();
void withraw_money();
void transfer_money();
void account_details();
void transaction_details();
void last_details();


int main()
{
    int choice;
    printf("Enter Your name: ");
   fgets(name, sizeof(name), stdin);
    printf("Enter the account Number: ");
    scanf("%d",&acc_no);

   while(1)
   {
        menu();
    
 printf("Enter Your Choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
   
       deposit_money();
        break;
    case 2:
 
       withraw_money();
        break;
    case 3:
    
       transfer_money();
        break;   
      
    case 4:
    
       account_details();
        break;
    case 5:
   
      transaction_details();
        break;  
    case 6:
  
     last_details();
      exit(0);
    
        break;
             

    default:
      printf("INVALID CHOICE!\n");
        break;
    }

   }


    return 0;
}
void menu()
{
  printf("----------------------------\n");
 printf("**** MAIN MENU ****\n");
printf("----------------------------");
  printf("\n1.Deposit Money\n");
  printf("2.Withraw Money\n");
  printf("3.Transfer Money\n");
  printf("4.Account Details\n");
  printf("5.Transaction Details\n");
  printf("6.Exit\n");   
  printf("----------------------------\n");
}

void deposit_money()
{
  time_t tm;
  time(&tm);
  FILE *ptr= fopen("Account.txt","a");
   printf("----------------------------\n");
  printf("**** DEPOSIT MONEY ****\n");
  printf("----------------------------\n");
  printf("\nEnter The Deposit Ammount: ");
  scanf("%d",&dip_amt);

  amt += dip_amt;

  printf("MONEY DEPOSITED!\n");
  printf("Current_Balance: %d\n",amt);
  fprintf(ptr,"Rs%d has been diposited to your Bank Account\n", dip_amt);
  fprintf(ptr,"Date/Time of Transcation: %s\n",ctime(&tm));
   printf("----------------------------\n");
  printf("Press any key...\n");
  getch();
  count++;
}

void withraw_money()
{
   time_t tm;
  time(&tm);
  FILE *ptr= fopen("Account.txt","a");
   printf("----------------------------\n");
  printf("**** WITHRAW MONEY ****\n");
   printf("----------------------------\n");
  printf("\nEnter the amount: ");
  scanf("%d",&with_amt);
  if (amt < trans_amt)
  {
    printf("Insufficent Balacnce!\n");

  }
  else{

  amt -= with_amt;
  printf("MONEY WITHRAWN!\n");
  printf("Current Balance: %d\n",amt);
  fprintf(ptr,"Rs%d has been withrawn from  your Bank Account\n", dip_amt);
  fprintf(ptr,"Date/Time of Transcation: %s\n",ctime(&tm));

   count++;
  }
  fclose(ptr);
 printf("----------------------------\n");
  printf("Press any key...\n");
    getch();
 
}

void transfer_money()
{
  int ac;

    time_t tm;
  time(&tm);
  FILE *ptr= fopen("Account.txt","a");

 printf("----------------------------\n");
  printf("**** TRANSFERING MONEY ****\n");
   printf("----------------------------\n");
  printf("\nEnter the amount: ");
  scanf("%d",&trans_amt);
  printf("Enter the account number in which you want to transfer your money: ");
  scanf("%d",&ac);
 
  if (amt < trans_amt)
  {
    printf("Insufficent Balacnce!\n");

  }
  else{
    amt -= trans_amt;
    printf("Money is transfered Succesfully!\n");
    printf("Current Balalnce!: %d\n",amt);
    fprintf(ptr,"Rs %d has been transferd from your account to %d\n",trans_amt,ac);
    fprintf(ptr,"Date/Time of Transcation: %s\n",ctime(&tm));
    count++;
  }
  
  fclose(ptr);
  printf("----------------------------\n");
  printf("Press any key to Continue.....\n");


  getch();
   
}

void account_details()
{
   printf("----------------------------\n");
  printf("**** ACCOUNT DETAILS ****\n");
  printf("----------------------------");
  printf("\nName: %s\n",name);
  printf("Account No. :%d\n",acc_no);
  printf("Total Balance: %d\n",amt);
  printf("Number of transactions made through your account: %d\n",count);
  printf("----------------------------\n");
  printf("Press any Key....\n");
  getch();
}

void transaction_details()
{
   printf("----------------------------\n");
   printf("\n**** TRANSACTION DETAILS ****\n");
   printf("----------------------------\n");
    FILE *ptr = fopen("Account.txt", "r");
    if (!ptr)
    {
        printf("No recent transactions found!\n");
        printf("----------------------------\n");
        return;
    }

    char c;
    while ((c = fgetc(ptr)) != EOF)
    {
        putchar(c);
    }
    fclose(ptr);
  printf("----------------------------\n");
}

void last_details()
{
   printf("----------------------------\n");
   printf("**** LAST DETAILS ****\n");
    printf("----------------------------\n");
   printf("\nName: %s\n",name);
  printf("Account No. :%d\n",acc_no);
  printf("Current Balance: %d\n",amt);
 printf("----------------------------\n");
  printf("Press any Key....\n");
  

  getch();
}