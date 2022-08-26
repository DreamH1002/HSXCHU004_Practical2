#include <stdio.h>
#include <math.h>

//initialise header variables
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Venny Hsiao"
#define YEAR 2022

void Dec2RadixI(int decValue, int radValue, char * str, int size)
{
    int rem;
    int div = decValue;
    char match[] = "0123456789ABCDEF";  //character array used to match the remainder with the correct character
    
    if(decValue==0)
    {
        rem = 0;
        div = div/radValue;
        printf("The integer result of the number divided by %d is %d\n",radValue,div);
        printf("The remainder is %d\n",rem);
        printf("The radix-%d value is 0",radValue);

    }
    else
    {
        for (int i = 0; i<=size; i++) //iterates size times to find the next remainder for the bit
        {
            rem = div%radValue; //finds remainder
            div = div - rem;    //finds the new value to divide by
            div = div/radValue; //divides the new value
            
            printf("The integer result of the number divided by %d is %d\n",radValue,div);
            printf("The remainder is %d\n",rem);

            //matches the correct char for the remainder and puts the bit result in the correct array position
            str[size-i] = match[rem];
        }

        printf("The radix-%d value is ",radValue);
    
        //prints the converted result
        for (int j = 0; j<=size;j++)
        {
            printf("%c",str[j]);
        }
    }//end else
   
    printf("\n\n"); //line skip for next decimal entry
} //end Dec2RadI function

int main()
{
    //header
    printf("****************************\n");
    printf("%s\nWritten by: %s\nDate: %d\n",TITLE,AUTHOR,YEAR);
    printf("****************************\n");
    
    int dec, radix, n;
    
    do
    {
        printf("Enter a decimal number: ");
        scanf("%d",&dec); //input decimal
        if(dec>=0) //if possitive number, run converter, else exit
        {
            printf("The number you have entered is %d\n",dec);
            printf("Enter a radix for the converter between 2 and 16: ");
            scanf("%d",&radix); //input radix
            printf("The radix you have entered is %d\n",radix);
            if(dec==0) //special case for decimal number 0 entered
            {
                n = 1;  // used for loop in Dec2RadixI function
                printf("The log2 of the number is undefined, but the length will be 1 bit.\n",radix);
            }
            else //normal case
            {
                float two = log(dec)/log(2); //used to display the log2 of the number
                printf("The log2 of the number is %0.2f\n",two);
                n = (log(dec)/log(radix));      // used for loop in Dec2RadixI function instead of the log2 of the number
            }
                  

            char * string;  //used for the Dec2RadixI function
            Dec2RadixI(dec,radix,string,n); //function to output converted result
        } //end if
            
    }while (dec >= 0);
    
    printf("EXIT");

    return 0;
} // end main
