/*
 * Part2.h
 *
 *  Created on: May 3, 2020
 *      Author: onur
 */

#ifndef INC_PART2_H_
#define INC_PART2_H_

struct Hospital
{
char* name;
char citiesServed[3];
};

void hospital_coverage_calculator();

int canOfferCovidCoverage(char _cities[6], char _locations[4][4], int
		_numHospitals, struct Hospital results[4]);

#endif /* INC_PART2_H_ */
