#include "quiz.h"
 
/*Function to validate a mobile number
  ---Only Numerical characters are allowed
  ---Mobile Number should contain 10 digits
  ---First digit should be a non zero value*/
   
int validate_number(char *str)
{
	int len = strlen(str);
	int i = 0;

	if(len==10)
	{
		if(str[0] != '0')
		{
			while(i<len)
			{
				if((str[i]>='0') && (str[i]<='9'))
				{
					i++;
					continue;
				} 
				else
				{
					printf("Only Numerical digits should be entered\n");
					return 0;
				}
				
			}
			return 1;
		}
		else
		{
			printf("First digit should not be 0\n ");
			return 0;
		}	
	}
	else
	{
		printf("Mobile Number should contain 10 digits\n: ");
		return 0;		
	}
}


/*Function to validate an email id
  ---First letter of email should be an alphabet
  ---should contain one '@' character
  ---should contain one '.' character
  ---'@' should come before '.'*/
int validate_email(char *str)
{
	int at = -1;
	int dot = -1;
	int len = strlen(str);
	if((str[0]>=97 && str[0]<=122) || (str[0]>=65 && str[0]<=90) )
	{
		for(int i=0; i<len; i++)
		{
			if(str[i] == '@')
			{
				at = i;
			}
			else if(str[i] == '.')
			{
				dot = i;
			}
			else
			{
				continue;
			}
		}
		
		if((at==-1) || (dot==-1) || (at>dot) || (dot==len-1))
		{
			printf("Invalid Email ID\n");
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		printf("Invalid Email ID\n");
		return 0;
	}
}
