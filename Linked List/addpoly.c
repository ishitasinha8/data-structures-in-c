#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff;
    int expo;
    struct term *link;
};

void add(struct term *pH, struct term *qH, struct term **sumH);
void insertSort(int c, int e, struct term **head);
void display(struct term *head);

int main()
{
    struct term *pHead = NULL;
    struct term *qHead = NULL;
    struct term *rHead = (struct term*)malloc(sizeof(struct term));
    int ch=0, coef = 0, expon = 0, prevExpon = 100;
    
    printf("Enter elements in p\n");      //take terms of p from user
    do
    {
        printf("Coefficient = ");
        scanf("%d",&coef);
        printf("Exponent = ");
        scanf("%d",&expon);
    
        insertSort(coef,expon,&pHead);
        printf("p = ");
        display(pHead);
        printf("Press 1 to enter more elements. Press any other letter to exit. Choice = ");
        scanf("%d", &ch);
        
    }while(ch==1);
    
    printf("\nEnter elements in q\n");      //take terms of q from user
    do
    {
        printf("Coefficient = ");
        scanf("%d",&coef);
        printf("Exponent = ");
        scanf("%d",&expon);
    
        insertSort(coef,expon,&qHead);
        printf("q = ");
        display(qHead);
        printf("Press 1 to enter more elements. Press any other letter to exit. Choice = ");
        scanf("%d", &ch);
        
    }while(ch==1);
    
    add(pHead,qHead,&rHead);            //add p and q
    printf("\nr = ");
    display(rHead);
    
    return 0;
}
void add(struct term *pH, struct term *qH, struct term **sumH)  //Adding two polynomials
{
    struct term *pTemp = pH, *qTemp = qH;
    struct term *sumTemp = *sumH;
    while((pTemp!=NULL)&&(qTemp!=NULL))     //If temp of both do not reach null, compare each term and copy into sum
    {
        if(pTemp->expo > qTemp->expo)
        {
            sumTemp->coeff = pTemp->coeff;
            sumTemp->expo = pTemp->expo;
            pTemp = pTemp->link;
        }
        else if(pTemp->expo < qTemp->expo)
        {
            sumTemp->coeff = qTemp->coeff;
            sumTemp->expo = qTemp->expo;
            qTemp = qTemp->link;
        }
        else
        {
            sumTemp->coeff = pTemp->coeff + qTemp->coeff;
            sumTemp->expo = pTemp->expo;
            pTemp = pTemp->link;
            qTemp = qTemp->link;
        }
        if((pTemp!=NULL)&&(qTemp!=NULL))
        {
            sumTemp->link = (struct term*)malloc(sizeof(struct term));
            sumTemp = sumTemp->link;
            sumTemp->link=NULL;
        }
    }
    while((pTemp!=NULL)||(qTemp!=NULL))     //if temp of any one reaches null, copy the other without comparison
    {
        sumTemp->link = (struct term*)malloc(sizeof(struct term));
        sumTemp = sumTemp->link;
        sumTemp->link=NULL;
        if(pTemp!=NULL)
        {
            sumTemp->coeff = pTemp->coeff;
            sumTemp->expo = pTemp->expo;
            pTemp = pTemp->link;
        }
        else
        {
            sumTemp->coeff = qTemp->coeff;
            sumTemp->expo = qTemp->expo;
            qTemp = qTemp->link;
        }
    }
}
void insertSort(int c, int e, struct term **head)       //Insertion sort
{
    struct term *new = (struct term*)malloc(sizeof(struct term));
    struct term *temp = *head, *prev = temp;
    new->link = NULL;
    new->coeff = c;
    new->expo = e;
    if(*head==NULL)     //If there are no existing terms
    {
        *head = new;
    }
    else                //If there are pre-existing terms
    {
        
        while(temp->expo>e)     //If temp->expo is greater than the e
        {
            prev = temp;
            if(temp->link==NULL)
                break;
            temp = temp->link;
        }
        
        if(temp==*head)     //If there is only 1 pre-existing term (head)
        {
            if(temp->expo>e)    //If *head's exponent is greater than e
            {
                temp->link = new;
            }
            else                //If head's exponent is smaller than e
            {
                new->link = *head;
                *head = new;
            }
        }
        else if(temp==NULL) //If the new term has the smallest exponent than all pre-existing terms
        {
            prev->link = new;
        }
        else                //For all other cases
        {
            new->link = prev->link;
            prev->link = new;
        }
    }
}
void display(struct term *head)     //display polynomial
{
    struct term *temp = head;
    while(temp!=NULL)
    {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->link;
        if(temp!=NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}