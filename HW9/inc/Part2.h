/*
 * Part2.h
 *
 *  Created on: May 3, 2020
 *      Author: onur
 */

#ifndef INC_PART2_H_
#define INC_PART2_H_

#define N_CITIES 6
#define N_LOCATIONS 4

struct Hospital
{
char* name;
char citiesServed[3];
};

void hospital_coverage_calculator();

int canOfferCovidCoverage(char _cities[6], char _locations[4][4], int
		_numHospitals, struct Hospital results[4]);

int check_results(char _cities[6], char _locations[N_LOCATIONS][4], int index);

#endif /* INC_PART2_H_ */
