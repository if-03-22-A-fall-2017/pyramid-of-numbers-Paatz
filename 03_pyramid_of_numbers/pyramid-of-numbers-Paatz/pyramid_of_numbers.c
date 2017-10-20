/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 3
 * Title:			Pyramid of Numbers
 * Author:			Patrick Spisak
 * ----------------------------------------------------------
 * Description:
 * Calculates a pyramid of numbers, i.e., it multiplies a big
 * integer by the number 2, its result by 3, etc. and then
 * returns to the original value by subsequently dividing,
 * again starting by 2, 3, etc.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>


/// The maximum number of digits allowed in a big int.
#define MAX_DIGITS 80

/** BigInt represents an integer number which can have MAX_DIGITS digits
*** @see MAX_DIGITS
*/
struct BigInt {
	/** number of digits of the big int. */
	int digits_count;

	/** array of digits of big int. */
	unsigned int the_int[MAX_DIGITS];
};

/** strtobig_int converts a string into a BigInt. If strtobig_int runs
*** against a character not between '0' and '9' t
*** @return The number of characters converted.
***he conversion stops
*** at this point.
*** @param *str The string to be converted.
*** @param len Number of characters in string to be converted.
*** @param *big_int The converted string now as BigInt.
*** @return The number of characters converted.
**/
int strtobig_int(const char *str, int len, struct BigInt *big_int)
{
	if(len <= 80)
	{
		int count = 0;
		for(int i = 0; i < len ; i++)
		{
				if(str[i] >= '0' && str[i] <= '9')
				{
					big_int -> the_int[count] = str[i] -'0';
					big_int-> digits_count++;
					count++;
				}
				else
				{
					printf("Error \n");
					return -2;
				}
		}

		int number = 0 ;
		int counter2 = 1 ;
		for(int r = len-1; r > -1 ; r--)
		{
				number = number + (big_int -> the_int[r] * counter2 );
			  counter2 = counter2 * 10;
		}

		return number;				/**Iint end = 0;st falsch **/
  }

	else
	{
		printf("Error \n");
		return -1;
	}

}

/** print_big_int() prints a BigInt.
*** @param *big_int The BigInt to be printed.
*/
void print_big_int(const struct BigInt *big_int)
{

}

/** multiply() multiplies a BigInt by an int.
*** @param big_int The BigInt to be multiplied.
*** @param factor The int value which is multiplied by BigInt.
*** @param *big_result The result of the multiplication.
*/
int multiply(const struct BigInt *big_int ,int factor ,struct BigInt *big_result,int number)
{
	long int result2 = number * factor ;
	double result = number * factor;
	int stop = 0 ;

	for(int i = 1; 0 ;i++)
	{
		result = result /10;

		if(result < 0 )
		{
			stop = 1;
			big_result -> digits_count = i;

		}
	}

	for(int i = 0 ; i < big_result -> digits_count ; i++)
	{
		int the_number = 1;
		for(int r = big_result -> digits_count-1 ;r > 0 ;r--)
		{
				 the_number = the_number * 10;
		}
		  big_result -> the_int[i] = result2 / the_number;

	}

	printf("%d * %d = %d \n",number ,factor ,result2 );

	return result2;
}

/** divide() multiplies a BigInt by an int.
*** @param big_int The BigInt to be divided.
*** @param divisor The int value by which we want to devide big_int.
*** @param *big_result The result of the division.
*/
int divide(const struct BigInt *big_int, int divisor, struct BigInt *big_result ,int number)
{
	int result = number / divisor;
	int stop = 0;
	for(int i = 1; 0 ;i++)
	{
		result = result /10;

		if(result < 0 )
		{
			stop = 1;
			big_result -> digits_count = i;

		}
	}



	for(int i = 0 ; i < big_result -> digits_count ; i++)
	{
		int the_number = 1;
		for(int r = big_result -> digits_count-1 ;r > 0 ;r--)
		{
				 the_number = the_number * 10;
		}
			big_result -> the_int[i] = result / the_number;
	}

	printf("%d / %d = %d \n",number ,divisor ,result );

	return result;
}

/** copy_big_int() copies a BigInt to another BigInt.
*** @param from The source where we want to copy from.
*** @param *to The target where we want to copy to.
*/
void copy_big_int(const struct BigInt *from, struct BigInt *to);

/**
*** main() reads the base number from which the pyramid has to be calculated
*** into an array ofinput char. The max. length of this number is MAX_DIGITS.
*** The number is checked to contain only digits. If not the program exits.
*** Then the inputted number is converted into a big int by calling the
*** function strtobig_int().
*** After the conversion the tower is calculated by calling the functions
*** multiply(), print_big_int(), and copy_big_int() consecutively from 2 to
*** 9 and then again with divide() instead of multiply() from 2 to 9.ITS];
	struct BigInt big_result;
***
*/
int main(int argc, char *argv[])
{
	char string_input[MAX_DIGITS];
	struct BigInt big_int [MAX_DIGITS];
	struct BigInt big_result;


	printf("Pyramid Of Numbers\n");
	printf("\n");
	printf("Please enter a number [max digits = 80] \n");
	scanf("%s",string_input);

  int len = strlen(string_input);

	int number = strtobig_int(string_input, len, &big_int); /** Ist noch falsch**/

	for(int i = 2; i < 10;i++)
	{
		number = multiply(&big_int ,i ,&big_result ,number);
	}

	for(int r = 2 ;r < 10 ;r++)
	{
		number = divide(&big_int ,r ,&big_result ,number);
	}

	return 0;
}
