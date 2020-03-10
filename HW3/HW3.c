/*
 ============================================================================
 Name        : HW3.c
 Author      : Onur
 Version     : Part1
 Copyright   : Your copyright notice
 Description : In the main function, the program respectively request an Integer
 (N), an operation flag, and finally a flag to decide if it is going to work on
 odd / even numbers. The program will support only 2 operations, addition or
 multiplication. According to the selection of the flags, the program will
 calculate the sum/multiplication of the odd/even numbers between the range of
 [1,N]. The addition and the multiplication operations should be done by using
 two different functions. The operation selection should be determined by using
 operation flag with switch-case, after that, the integer and the other flag
 should be used to call the related function. If user enters invalid value for
 the flags, the program should print an error message.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include "Part1.h"
//#include "Part2.h"
#include "Part3.h"

int main(void) {
	//sum_mult_operation();
	//check_prime();
	and_operation();
	return EXIT_SUCCESS;
}
