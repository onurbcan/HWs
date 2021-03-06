/*
 ============================================================================
 Name        : HW8.c
 Author      : Onur
 Version     :
 Copyright   :
 Description : HW8
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"
#include "Part2.h"
#include "Part3.h"
#include "Part4.h"

/*! \mainpage HW8 Documentation
 *
 * This project is the implementation of various functions and operations.
 */

int main(void) {
	/*! 1.1.0) Hofstadter's Q-Sequence */
	hofstadters_q_sequence();
	/*! 2.1.0) L-shaped Pipe Orientation */
	l_shaped_pipe_orientation();
	/*! 3.1.0) Text Duplicate Letter Cleaner */
	text_duplicate_letter_cleaner();
	/*! 4.1.0) Menu Screen */
	menu();
	return EXIT_SUCCESS;
}
