

#pragma GCC diagnostic ignored "-Wformat-zero-length"
int		main()
{
	int chars_returned;

/* -----------------------------------------------------------------------------
** 						NO SPECIFIERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 		NO SPECIFIERS TESTS		 **\n");
	printf("***************************************************\n\n\n");

// [1]
	printf("\033[0;37m"); // White
	printf("[ 1 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("Hello, World!");
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


// [2]
	printf("\033[0;37m"); // White
	printf("[ 2 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("");
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

/* -----------------------------------------------------------------------------
** 						%% PERCENTAGE TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
/*
	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 		%% PERCENTAGE TESTS		 **\n");
	printf("***************************************************\n\n\n");


// [3]
	printf("\033[0;37m"); // White
	printf("[ 3 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%%");
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [4]
	printf("\033[0;37m"); // White
	printf("[ 4 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%5%");
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

*/
/* -----------------------------------------------------------------------------
** 						%c CHARS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 		  %%c CHARS TESTS		 **\n");
	printf("***************************************************\n\n\n");

// [5]
	printf("\033[0;37m"); // White
	printf("[ 5 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",'#','!','"',' ','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						%s STRING TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 		  %%s STRING TESTS		 **\n");
	printf("***************************************************\n\n\n");

// [6]
	printf("\033[0;37m"); // White
	printf("[ 6 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%s%s", "Hello, ", "World!");
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [7]
	printf("\033[0;37m"); // White
	printf("[ 7 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %s is %s", "hello", "");
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						%p POINTER TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 		  %%p POINTERS TESTS		 **\n");
	printf("***************************************************\n\n\n");

// [9]
	printf("\033[0;37m"); // White
	printf("[ 9 ]\n\n");
	printf("\033[0;33m"); // Yellow

	unsigned long long aa = 252525;
	unsigned long long *bb = &aa;

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%p", bb);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [10]
	printf("\033[0;37m"); // White
	printf("[ 10 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%p", 0);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						%d INTEGERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 		  %%d INTEGERS TESTS		 **\n");
	printf("***************************************************\n\n\n");

// [11]
	printf("\033[0;37m"); // White
	printf("[ 11 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%d",  2147483647);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [12]
	printf("\033[0;37m"); // White
	printf("[ 12 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%d", (int)(-2147483678));
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						%i INTEGERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 		  %%i INTEGERS TESTS		 **\n");
	printf("***************************************************\n\n\n");

// [13]
	printf("\033[0;37m"); // White
	printf("[ 13 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %i and %i are intergers i.", -267, 99);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						%u UNSIGNED INTEGERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	    %%u UNSIGNED INTEGERS TESTS		 **\n");
	printf("***************************************************\n\n\n");

// [14]
	printf("\033[0;37m"); // White
	printf("[ 14 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %u is an Unsigned Integer.", 55);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [15]
	printf("\033[0;37m"); // White
	printf("[ 15 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %u is an Unsigned Integer.", 0);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						%x HEXADECIMAL LOWERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	    %%x HEXADECIMAL LOWERS TESTS		 **\n");
	printf("***************************************************\n\n\n");

// [16]
	printf("\033[0;37m"); // White
	printf("[ 16 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %x is Hexadecimal for 11.", 11);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [17]
	printf("\033[0;37m"); // White
	printf("[ 17 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %x is Hexadecimal for 35.", 35);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// 0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f      -> 16 (Como começas 0, o f é 15(decimal))
// 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f     -> 32 (1f é 31 em decimal)
// 20 21 22 23 24 25 26 27 28 29 2a 2b 2c 2d 2e 2f     -> 48 (2f é 47 em decimal)


/* -----------------------------------------------------------------------------
** 						%X HEXADECIMAL UPPER TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	    %%X HEXADECIMAL UPPER TESTS		 **\n");
	printf("***************************************************\n\n\n");

// [18]
	printf("\033[0;37m"); // White
	printf("[ 18 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %X is Hexadecimal for 11.", 11);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [19]
	printf("\033[0;37m"); // White
	printf("[ 19 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %X is Hexadecimal for 35.", 35);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F      -> 16 (Como começas 0, o F é 15(decimal))
// 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F     -> 32 (1F é 31 em decimal)
// 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F     -> 48 (2F é 47 em decimal)


/* -----------------------------------------------------------------------------
** 						 %*STAR TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	    	   %%*STAR TESTS			 **\n");
	printf("***************************************************\n\n\n");

// [20]
	printf("\033[0;37m"); // White
	printf("[ 20 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%*s", 25, "abc");
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [21]
	printf("\033[0;37m"); // White
	printf("[ 21 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%*i", 14, 94827);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

/* -----------------------------------------------------------------------------
** 						'+' FLAG (ALLSIGN) TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	  '+' FLAG (ALLSIGN) TESTS (BONUS)	 **\n");
	printf("***************************************************\n\n\n");

// [22]
	printf("\033[0;37m"); // White
	printf("[ 22 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%+d", 5);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [23]
	printf("\033[0;37m"); // White
	printf("[ 23 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%+04d", 0);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						' ' FLAG (SPACE) TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	  ' ' FLAG (SPACE) TESTS (BONUS)	 **\n");
	printf("***************************************************\n\n\n");

// [24]
	printf("\033[0;37m"); // White
	printf("[ 24 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This % d is number.", 17);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [25]
	printf("\033[0;37m"); // White
	printf("[ 25 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("% 8.5i", 34);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						'#' FLAG (ALTFORM) TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	  '#' FLAG (ALTFORM) TESTS (BONUS)	 **\n");
	printf("***************************************************\n\n\n");

// [26]
	printf("\033[0;37m"); // White
	printf("[ 26 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %#9x is number.", 52625);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [27]
	printf("\033[0;37m"); // White
	printf("[ 27 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%#-8.3x", 8375);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						'l ll h hh' FLAGS TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	     'l ll h hh' FLAGS (BONUS) 		 **\n");
	printf("***************************************************\n");

	printf("\nl = long int / long unsigned int\n");
	printf("ll = long long int / long long unsigned int\n");
	printf("h = short int / short unsigned int\n");
	printf("hh = char / unsigned char\n\n\n");

// [28]
	printf("\033[0;37m"); // White
	printf("[ 28 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%hhd", (char)45);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [29]
	printf("\033[0;37m"); // White
	printf("[ 29 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%hd", (short)385);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [30]
	printf("\033[0;37m"); // White
	printf("[ 30 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%lld", 522337203685470ll);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


// [31]
	printf("\033[0;37m"); // White
	printf("[ 31 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%ld", 9223372036854775807l);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						%f FLOATS TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	     %%f FLOATS TESTS (BONUS) 		 **\n");
	printf("***************************************************\n\n\n");

// [32]
	printf("\033[0;37m"); // White
	printf("[ 32 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("This %f is Float.", 1.5);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [33]
	printf("\033[0;37m"); // White
	printf("[ 33 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%f", -99.999999);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [34]
	printf("\033[0;37m"); // White
	printf("[ 34 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%.8f", 23.00041);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						%g GENERAL FORMAT TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	   %%g GENERAL FORMAT TESTS (BONUS) 	 **\n");
	printf("***************************************************\n\n\n");

// [35]
	printf("\033[0;37m"); // White
	printf("[ 35 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%g", -985.765426499);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [36]
	printf("\033[0;37m"); // White
	printf("[ 36 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%g", -0.99999949);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

/* -----------------------------------------------------------------------------
** 						%e SCIENTIFIC NOTATION TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	 %%e SCIENTIFIC NOTATION TESTS (BONUS) 	 **\n");
	printf("***************************************************\n\n\n");

// [37]
	printf("\033[0;37m"); // White
	printf("[ 37 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("this %e scientific notation.", 1.5);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [38]
	printf("\033[0;37m"); // White
	printf("[ 38 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%e", 0.999999);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						%n POINTER TO INTEGER TESTS (BONUS)
** ---------------------------------------------------------------------------*/


	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	 %%n POINTER TO INTEGER TESTS (BONUS) 	 **\n");
	printf("***************************************************\n\n\n");

int n;

// [39]
	printf("\033[0;37m"); // White
	printf("[ 39 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("Add value to n %n", &n);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

// [40]
	printf("\033[0;37m"); // White
	printf("[ 40 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("The value of n, is now %d.", n);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						'-' FLAG (ALLSIGN) TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	  '-' FLAG (ALLSIGN) TESTS (BONUS)	 **\n");
	printf("***************************************************\n\n\n");


// [41]
	printf("\033[0;37m"); // White
	printf("[ 41 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%-23i", 52625);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

/* -----------------------------------------------------------------------------
** 						'0' FLAG (ALLSIGN) TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	  '0' FLAG (ALLSIGN) TESTS (BONUS)	 **\n");
	printf("***************************************************\n\n\n");


// [42]
	printf("\033[0;37m"); // White
	printf("[ 42 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%09d", 5231);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

/* -----------------------------------------------------------------------------
** 						'.' FLAG (ALLSIGN) TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	  '.' FLAG (ALLSIGN) TESTS (BONUS)	 **\n");
	printf("***************************************************\n\n\n");

// [43]
	printf("\033[0;37m"); // White
	printf("[ 43 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%.5f", 1.025978541136587568);
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //


/* -----------------------------------------------------------------------------
** 						WIDTH FLAG (ALLSIGN) TESTS (BONUS)
** ---------------------------------------------------------------------------*/

	printf("\033[0;33m"); // Yellow
	printf("\n***************************************************");
	printf("\n** 	  	WIDTH TESTS (BONUS)		**\n");
	printf("***************************************************\n\n\n");

// [44]
	printf("\033[0;37m"); // White
	printf("[ 44 ]\n\n");
	printf("\033[0;33m"); // Yellow

	printf("printf = ");
	printf("\033[0;34m"); // Blue
	// ************** //
	chars_returned = printf("%20s", "abc");
	printf("\n");
	printf("	 [%d]\n\n", chars_returned);
	// ************** //

}
#pragma GCC diagnostic warning "-Wformat-zero-length"
