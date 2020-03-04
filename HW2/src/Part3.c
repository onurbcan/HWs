/*
 * Part3.c
 *
 *  Created on: Feb 28, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Part3.h"

void currency_converter(){
	float amount; //amount to be converted
	int fcurrency, tcurrency; //from currency, to currency

	printf("*****Welcome to ABC Exchange Office*****\n");
	printf("Enter your amount: ");
	scanf("%f",&amount);

	printf("Please select your currency\n");
	printf("%d. Turkish Lira\n", Try);
	printf("%d. Euro\n", Eur);
	printf("%d. US Dollar\n", Usd);
	scanf("%d", &fcurrency);

	if(fcurrency == Try)
		printf("You have %.2f Turkish Liras\n", amount);
	if(fcurrency == Eur)
		printf("You have %.2f Euros\n", amount);
	if(fcurrency == Usd)
		printf("You have %.2f US Dollars\n", amount);

	printf("Choose which currency you want to convert: ");
	scanf("%d", &tcurrency);

	switch(tcurrency){
		case 1:
			if(fcurrency == Try)
				printf("Same currency! No exchange needed.");
			if(fcurrency == Eur)
				printf("You have %.2f Turkish Liras", amount * EUR_TRY);
			if(fcurrency == Usd)
				printf("You have %.2f Turkish Liras", amount * USD_TRY);
			break;

		case 2:
			if(fcurrency == Try)
				printf("You have %.2f Euros", amount / EUR_TRY);
			if(fcurrency == Eur)
				printf("Same currency! No exchange needed.");
			if(fcurrency == Usd)
				printf("You have %.2f Euros", amount / EUR_USD);
			break;

		case 3:
			if(fcurrency == Try)
				printf("You have %.2f US Dollars", amount / USD_TRY);
			if(fcurrency == Eur)
				printf("You have %.2f US Dollars", amount * EUR_USD);
			if(fcurrency == Usd)
				printf("Same currency! No exchange needed.");
			break;

		default:
			printf("Your selection is invalid!");
	}
}
