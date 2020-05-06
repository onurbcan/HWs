/*
 * Part2.c
 *
 *  Created on: May 3, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Part1.h"
#include "Part2.h"



void combinationUtil(char arr[], char data[], int start, int end,
                     int index, int r);
void printCombination(char arr[], int n, int r);

void hospital_coverage_calculator() {
	int i;
	int num_hospitals = 3;
    // A temporary array to store all combination one by one
    char data[3], temp[15];
	char cities[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	char locations[4][4] = { {'A', 'B', 'C'}, {'A', 'C', 'D'}, {'B', 'F'}, {'C', 'E', 'F'} };
	struct Hospital results[4];
	for (i = 0; i < 4; ++i) {
		sprintf(temp, "Hospital-%d", i);
		results[i].name = temp;
		strcpy(results[i].citiesServed, locations[i]);
	}




	canOfferCovidCoverage(cities, locations, num_hospitals, results);
}

int canOfferCovidCoverage(char _cities[6], char _locations[4][4], int
		_numHospitals, struct Hospital results[4]) {
	int i;
	for (i = 0; i < 4; ++i) {
		printf("%s\n", results[i].name);
		printf("%s\n", results[i].citiesServed);
	}
	return 0;
}






	/*
	//printCombination(cities, 6, 3);
	combinationUtil(cities, data, 0, 6-1, 0, 3);



}




// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(char arr[], int n, int r)
{


    // Print all combination using temprary array 'data[]'

}

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
/*
void combinationUtil(char arr[], char data[], int start, int end,
                     int index, int r) {
	int i;

    // Current combination is ready to be printed, print it
    if (index == r) {
        for (int j=0; j<r; j++)
            printf("%c ", data[j]);
        printf("\n");
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (i=start; i<=end && end-i+1 >= r-index; i++) {

        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
*/

