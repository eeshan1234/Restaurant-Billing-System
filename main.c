#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[25];
    unsigned long long int phone;
    int credit;
}customer;

typedef struct details
{
    char lname[25];
    int lcredit;
    unsigned long long int lphone;
    struct node *next;
}NODE;

struct node
{
    char foodname[50];
    float foodprice;
    int foodquantity;
    struct node *link;
};

typedef struct node *NODEPTR;
NODEPTR getnode(void)
{
    NODEPTR temp;
    temp=(NODEPTR)malloc(sizeof(struct node));
    return temp;
}
NODEPTR fnInsertRear(NODEPTR first,char fdname[50],float price,int qty)
{
    NODEPTR temp,cur;
    temp=getnode();
    strcpy(temp->foodname,fdname);
    temp->foodprice=price;
    temp->foodquantity=qty;
    temp->link=NULL;
    if(first==NULL)
    {
        first=temp;
        return first;
    }
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}

int searchNum(unsigned long long int);//function to search number in file
float CalculateTotal(NODEPTR,float);//function to calculate total
void updateCredits(int *credits,unsigned long long int numPhone);//function to update new credits in file;

/*void display(NODE* first) //function to display list contents
{
    while(first!=NULL)
    {
        printf("Name:%s ",first->lname);
        printf("Credits:%d   ",first->lcredit);
        printf("Phone no. %llu\n",first->lphone);
        first = first->next;
    }
}*/

//Function to calculate discount

float calculateDiscount(float a,int cusCredits,unsigned long long int numPhone)
{
    char cha[3];
    int *b = &cusCredits;
    float discount;
    int choice;

    printf("\nYour total amount is %0.2f",a);
    for(;;)
    {
    printf("\nDo you wish to use your credits (yes/no) ?:\t");
    scanf("%s",cha);
    if(strcmp(cha,"yes")==0)
    {

        if(*b>=0 && *b<50)
        {
            printf("\nSorry! You have insufficient credits, hence you are not eligible for any discount.\n");
            printf("\nCurrent credits are:%d\n",*b);
            if(a>=200 && a<1000)
            {
                *b=*b+10;
                printf("\nUpdated Credits are %d\n",*b);
                updateCredits(b,numPhone);
            }
            else if(a>=1000 && a<2000)
            {
                *b+=20;
                printf("\nUpdated Credits are %d\n",*b);
                updateCredits(b,numPhone);
            }
            else if(a>=2000 && a<3500)
            {
                *b+=30;
                printf("\nUpdated Credits are %d\n",*b);
                updateCredits(b,numPhone);
            }
            else if(a>=3500)
            {
                *b+=40;
                printf("\nUpdated Credits are %d\n",*b);
                updateCredits(b,numPhone);
            }
            return(0);

        }
        else if(*b>=50 && *b<=100)
        {
            printf("\nCurrent credits are %d\n",*b);
            printf("\nYou are eligible for the following discounts:\n1.  2%% off on payment through SBI Debit/Credit Card\n2.  3%% off on UPI payment\n3.  Not interested in discount\n");
            for(;;)
                {
                    printf("\nPlease select any of the above\n");
                    scanf("%d",&choice);

                    switch(choice)
                        {
                                case 1: discount=0.02*a;
                                        *b=*b-40;
                                        printf("\nUpdated credits are %d\n",*b);
                                        updateCredits(b,numPhone);
                                        return discount;

                                case 2: discount=0.03*a;
                                        *b=*b-50;
                                        printf("\nUpdated credits are %d\n",*b);
                                        updateCredits(b,numPhone);
                                        return discount;

                                case 3: discount=0;
                                        return discount;

                                default: printf("\nINVALID CHOICE\n");
                        }
                }
        }
        else if(*b>100 && *b<=200)
        {
            printf("\nCurrent credits are %d",*b);
            printf("\nYou are eligible for the following discounts:\n1.  4%% off on payment through SBI Debit/Credit Card\n2.  6%% off on UPI payment\n3.  Not interested in discount\n");
            for(;;)
                {
                    printf("\nPlease select any of the above\n");
                    scanf("%d",&choice);

                    switch(choice)
                        {
                                case 1: discount=0.04*a;
                                        *b=*b-80;
                                        printf("\nUpdated credits are %d\n",*b);
                                        updateCredits(b,numPhone);
                                        return discount;

                                case 2: discount=0.06*a;
                                        *b=*b-100;
                                        printf("\nUpdated credits are %d\n",*b);
                                        updateCredits(b,numPhone);
                                        return discount;

                                case 3: discount=0;
                                        return discount;

                                default: printf("\nINVALID CHOICE\n");
                        }
                }
        }
        else
        {
        printf("\nCurrent credits are %d",*b);
        printf("\nYou are eligible for the following discounts:\n1.  8%% off on payment through SBI Debit/Credit Card\n2.  12%% off on UPI payment\n3.  Not interested in discount\n");
            for(;;)
                {
                    printf("Please select any of the above\n");
                    scanf("%d",&choice);

                    switch(choice)
                        {
                                case 1: discount=0.08*a;
                                        *b=*b-160;
                                        printf("\nUpdated credits are %d\n",*b);
                                        updateCredits(b,numPhone);
                                        return discount;

                                case 2: discount=0.12*a;
                                        *b=*b-200;
                                        printf("\nUpdated credits are %d\n",*b);
                                        updateCredits(b,numPhone);
                                        return discount;

                                case 3: discount=0;
                                        return discount;

                                default: printf("\nINVALID CHOICE\n");
                        }
                }
        }

    }
    else if(strcmp(cha,"no")==0)
    {
        discount=0;
        if(a>=200 && a<1000)
            {
                *b=*b+10;
                printf("\nUpdated credits are %d\n",*b);
                updateCredits(b,numPhone);
            }
            else if(a>=1000 && a<2000)
            {
                *b=*b+20;
                printf("\nUpdated credits are %d\n",*b);
                updateCredits(b,numPhone);
            }
            else if(a>=2000 && a<3500)
            {
                *b=*b+30;
                printf("\nUpdated credits are %d\n",*b);
                updateCredits(b,numPhone);
            }
            else if(a>=3500)
            {
                *b=*b+40;
                printf("\nUpdated credits are %d\n",*b);
                updateCredits(b,numPhone);
            }
        return discount;
    }
    else

        printf("\nInvalid Entry!! Enter appropriate response\n");
    }
}

//function to add file content to list for updating credits

NODE* ins_front(NODE* first,int credit,unsigned long long int phone,char name[])
{
    NODE* newnode;

    newnode = (NODE*)malloc(sizeof(struct node));
    newnode->lcredit= credit;
    newnode->lphone=phone;
    newnode->next = first;
    strcpy(newnode->lname,name);
    return newnode;
}
//END of function to add file content to list for updating credits

void displayBill(float,float,NODEPTR);//function to display bill
void fnWriteFile(NODE* first);//function declaration to write list content in file


int main()
{
    FILE *fp;             //variable declaration for number verification
    customer client;
    unsigned long long int numcheck;
    int choice;

    int countchk=0;

    NODEPTR first=NULL;         //Variable declaration for MENU display
    int itemno,itemqty,c=1;
    char fname[50],ch[5];

    float total=0;  //variable declaration for calculating total

    int credits;//variable declaration for discount calculation
    float discount;

    char tname[50];
    unsigned long long int tphno;
    int tcredits;
    int counter=0;

    printf("Enter phone Number\n");
    scanf("%lld",&numcheck);
    credits = searchNum(numcheck);

    if(credits)
    {

        printf("Press 1 to proceed to MENU:\t");
        scanf("%d",&choice);

    }
    else
    {
        printf("Welcome New Customer\n");
        printf("\nEnter your name\n");
        scanf("%s",client.name);
        client.phone = numcheck;
        client.credit = 0;
        fp = fopen("info.txt","a");
        fprintf(fp,"\n%s\t%llu\t%d",client.name,client.phone,client.credit);
        printf("Press 1 to proceed to MENU");
        scanf("%d",&choice);
    }

    switch(choice)
    {
        case 1:  //MENU
    printf("\n\t\t\t\t\tMENU");
    printf("\n    __________________________________________________________________________\n");
    printf("\n\n\t      ItemNumber\t\tName\t\tPrice");
    printf("\n\t         1\t\t     VEG BURGER\t\t 120");
    printf("\n\t         2\t\t     VEG SANDWICH\t  90");
    printf("\n\t         3\t\t     VEG PIZZA\t\t 140");
    printf("\n\t         4\t\t     FRENCH FRIES\t  70");
    printf("\n\t         5\t\t     SOFT DRINKs\t  65");
    printf("\n\n");
    printf("\n    __________________________________________________________________________\n\n");

   while(c==1)
   {
         printf("\nEnter the Item Number of the food you want to Order:\t");
         scanf("%d",&itemno);
         switch(itemno)
         {
             case 1:printf("Enter the number of VEG BURGER :\t");
                    scanf("%d",&itemqty);
                    strcpy(fname,"VEG BURGER");
                    first=fnInsertRear(first,fname,120,itemqty);
                    countchk++;
                    break;

             case 2:printf("Enter the number of VEG SANDWICH :\t");
                    scanf("%d",&itemqty);
                    strcpy(fname,"VEG SANDWICH");
                    first=fnInsertRear(first,fname,90,itemqty);
                                        countchk++;

                    break;
             case 3:printf("Enter the number of VEG PIZZA :\t");
                    scanf("%d",&itemqty);
                    strcpy(fname,"VEG PIZZA");
                    first=fnInsertRear(first,fname,140,itemqty);
                                        countchk++;

                    break;
             case 4:printf("Enter the number of FRENCH FRIES :\t");
                    scanf("%d",&itemqty);
                    strcpy(fname,"FRENCH FRIES");
                    first=fnInsertRear(first,fname,70,itemqty);
                                        countchk++;

                    break;
             case 5:printf("Enter the number of  SOFT DRINKs :\t");
                    scanf("%d",&itemqty);
                    strcpy(fname,"SOFT DRINKs");
                    first=fnInsertRear(first,fname,65,itemqty);
                                        countchk++;

                    break;
            default:printf("invalid input");
         }
         printf("\nDo you want to order anything else (yes/no) ?:\t");
         scanf("%s",ch);
         if(strcmp(ch,"yes")==0)
            c=1;
         else
            c=0;

   }

    NODEPTR p,q,prev,temp;
    p=q=prev=first;
    q=q->link;

    while(p!=NULL)
    {
        while(q!=NULL &&(strcmp(q->foodname,p->foodname)!=0))
        {
            prev=q;
            q=q->link;
        }
        if(q==NULL)
        {
            p=p->link;
            if(p!=NULL)
                q=p->link;
        }
        else if(strcmp(q->foodname,p->foodname)==0)
        {
            prev->link=q->link;
            temp=q;
            p->foodquantity+=q->foodquantity;
            q=q->link;
            free(temp);
        }
    }


        break;

        default:printf("Invalid input");
    }

     float sumTotal=CalculateTotal(first,total); //function call for calculating total

    discount = calculateDiscount(sumTotal,credits,numcheck);
    displayBill(sumTotal,discount,first);

    return 0;
}

int searchNum(unsigned long long int numcheck)
{
   customer client;
   FILE *fp;
   fp = fopen("info.txt","r");
   int cusCredits;
    while(fscanf(fp,"%s%llu%d",client.name,&client.phone,&client.credit)!=EOF)
    {
        if(numcheck == client.phone)
        {
            printf("WELCOME BACK %s\n",client.name);
            printf("Credits Earned: %d\n",client.credit);
            cusCredits = client.credit;
            return cusCredits;
        }

    }
    fclose(fp);
    return 0;
}

float CalculateTotal(NODEPTR x, float tot)
{
    NODEPTR cur;
    cur=x;
    while(cur!=NULL)
    {

        tot=tot + (cur->foodprice*cur->foodquantity);
        cur=cur->link;

    }
    return tot;

}

void updateCredits(int *credits,unsigned long long int numPhone)
{
    NODE *first =NULL;
    FILE *fp;
    customer client;
    fp = fopen("info.txt","r");

        while(fscanf(fp,"%s%llu%d",client.name,&client.phone,&client.credit)!=EOF)
        {
            if(numPhone == client.phone)
            {
                client.credit = *credits;
            }
            first= ins_front(first,client.credit,client.phone,client.name);
        }

    fclose(fp);
    fnWriteFile(first);

    return;
}

void fnWriteFile(NODE*first)
{
    FILE*fp;
    fp = fopen("info.txt","w");

    while(first!=NULL)
    {
        fprintf(fp,"\n%s\t%llu\t%d",first->lname,first->lphone,first->lcredit);
        first = first->next;
    }
    return;
}
void displayBill(float total,float discount,NODEPTR first)
{
    float finalAmt;
    printf("\n\t\t\t\t******************************************************\n");
    printf("\n\t\t\t\t\tITEM ORDERED\tQUANTITY\tPRICE\n");
    while(first!=NULL)
    {
        printf("\n\t\t\t\t\t%s\t%d\t\t%0.2f\n",first->foodname,first->foodquantity,first->foodprice);
        first = first->link;
    }
    printf("\n\t\t\t\t-------------------------------------------------------\n\n");
    printf("\t\t\t\t\tSubTotal Amount is :\t\t%0.2f\n",total);
    printf("\t\t\t\t\tDiscount Availed   :\t\t%0.2f\n",discount);
    finalAmt = total - discount;
    printf("\t\t\t\t\tFinal Amount is    :\t\t%0.2f\n",finalAmt);
    printf("\n\t\t\t\t******************************************************");



    return;
}
