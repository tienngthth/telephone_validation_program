/*
  RMIT University Vietnam
  Course: EEET2448 Computing Engineering
  Semester: 2019A
  Assessment: Assignment 1
  Author: Nguyen Thi Thuy Tien
  ID: 3757934
  Created date: 20/3/2019
 Acknowledgement: If you use any resources, acknowledge here. Failure to do so will be considered as plagiarism.
*/


#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    //Declare an array of 13 characters to store phone number in string form
    char num[13];
    //Declare an integer variable to store length of the num string (maximm 12 digits)
    int numlen;

    //Infinite loop which will run till a break statement when entered number is negative
    while (1)
    {
        //Enter phonenumber and store its maximum first 12 characters (which is also the first number that is bigger than 11) to num to minimize the memory
        printf("Enter a telephone number to validate: ");
        scanf("%12s", num);
        //Get the string length
        numlen = strlen(num);
        //Use scanf format to exclude the rest of characters of the current entered number to get ready for receiving a new phone number input
        scanf("%*[^\n]");
        //Check the negative condition to exit the loop
        if (num[0] == '-')
        {
            //Announce exitting the program when the telephone number is negative
            printf("Program exits. Goodbye!!!\n");
            //Terminating the loop when the phone number is negative (1st character is '-')
            break;
        }
        //Check the more than 11 digits error
        else if (numlen > 11)
        {
            //Announce the error
            printf("Invalid. More than 11 digits.\n");
        }
        //Check the less than 10 digits error
        else if (numlen < 10)
        {
            //Announce the error
            printf("Invalid. Less than 10 digits.\n");
        }
        //Check the trunk code error
        else if (num[0] != '0')
        {
            //Announce the error
            printf("Invalid trunk code.\n");
        }
        //Check the invalid area number error
        else if ((numlen == 11) && (num[1] != '2'))
        {
            //Announce the error
            printf("Invalid area code.\n");
        }
        //Check the invalid mobile number error
        else if (numlen == 10)
        {
            //Convert from decimal number of the charater in ascii table to integer (as the gap between them is 48) and store it to a new integer variable called mbcode
            int mbcode = (num[1] - 48)*10 + (num[2] - 48);
            //Check whether the mbcode is belonged to one of the invalid cases
            if ((mbcode < 32) ||
                (mbcode == 80) ||
                ((mbcode > 39) && (mbcode < 76) && (mbcode != 52) && (mbcode != 56) && (mbcode != 58) && (mbcode != 59) && (mbcode != 70)))
            {
                //Announce the error
                printf("Invalid mobile code.\n");
            }
            //Announce the valid 10-digit telephone number
            else
            {
                printf("Valid phone number.\n");
            }
        }
        //Announce the valid 11-digit telephone number
        else
        {
            printf("Valid phone number.\n");
        }
    }

return 0;
}
