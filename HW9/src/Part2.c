/*
 * Part2.c
 *
 *  Created on: May 3, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"
#include "Part2.h"

void hospital_coverage_calculator() {
	int num_hospitals;
	char cities = { "A", "B", "C", "D", "E", "F" };
	char locations = { {"A", "B", "C"}, {"A", "C", "D"}, {"B", "F"}, {"C", "E", "F"} };
	struct Hospital results;

	canOfferCovidCoverage(cities, locations, num_hospitals, results);
}

int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int
		_numHospitals, struct Hospital results[4]) {

	return 0;
}
