/*
 ============================================================================
 Name        : HW11.c
 Author      : Onur
 Version     :
 Copyright   :
 Description : Array vs Linked List performance measurement
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"
#include "Part2.h"

int main(int argc, char **argv) {
	array_vs_linkedlist(argv[1]);
	compare_two_arguments(argv[1], argv[2]);
	return EXIT_SUCCESS;
}
