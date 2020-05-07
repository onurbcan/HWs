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
    //char data[3];
	char cities[N_CITIES] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	char locations[N_LOCATIONS][4] = { {'A', 'B', 'C'}, {'A', 'C', 'D'}, {'B', 'F'}, {'C', 'E', 'F'} };
	struct Hospital results[N_LOCATIONS];


	for (i = 0; i < 4; ++i) {
		results[i].name = "Hospital-";
		strcpy(results[i].citiesServed, locations[i]);
	}

	/*
	for (i = 0; i < 4; ++i) {
		printf("%s\n", results[i].name);
	}
	*/

	canOfferCovidCoverage(cities, locations, num_hospitals, results);
}

int canOfferCovidCoverage(char _cities[6], char _locations[N_LOCATIONS][4], int
		_numHospitals, struct Hospital results[4]) {
	int result;
	result = check_results(_cities, _locations, 0);
	printf("%d\n", result);
	/*
	int i;
	for (i = 0; i < 4; ++i) {
		printf("%s\n", results[i].name);
		printf("%s\n", results[i].citiesServed);
	}
	*/
	return 0;
}

int check_results(char _cities[6], char _locations[N_LOCATIONS][4], int index) {
	int j, y, x;
	char temp[6];
	strcpy(temp, _cities);

	if (index < N_LOCATIONS) {
		//i = 0;
		//while (i < N_LOCATIONS) {
			for (y = 0; y < N_LOCATIONS; ++y) {
				if (y != index) {
					for (x = 0; x < N_LOCATIONS - 1; ++x) {
						j = 0;
						while (j < N_CITIES) {
							if (_locations[y][x] == temp[j])
								temp[j] = '0';
							++j;
						}
					}
				}
			}
			j = 0;
			while (j < N_CITIES) {
				if (temp[j] != '0')
					break;
				++j;
			}
			if (j == N_CITIES)
				return (index);
			//++i;
		//}
		check_results(_cities, _locations, index + 1);
	}
	return (-1);
}

/*
 * call func using: combinationUtil(cities, data, 0, 6-1, 0, 3);

	//arr[]  ---> Input Array
	//data[] ---> Temporary array to store current combination
	//start & end ---> Staring and Ending indexes in arr[]
	//index  ---> Current index in data[]
	//r ---> Size of a combination to be printed

void combinationUtil(char arr[], char data[], int start, int end,
                     int index, int r) {
	int i, j;

    // Current combination is ready to be printed, print it
    if (index == r) {
        for (j = 0; j < r; j++)
            printf("%c ", data[j]);
        printf("\n");
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
*/
