/*
 * M4HotWaterSource.cpp
 *
 *  Created on: May 23, 2017
 *      Author: oleg
 */

#include "M4HotWaterSource.h"
#include "CoffeeMakerApi.h"

M4HotWaterSource::~M4HotWaterSource() {
	// TODO Auto-generated destructor stub
}

bool M4HotWaterSource::isReady() {
	CoffeeMakerAPI::BoilerStatus status = api->GetBoilerStatus();
	return status == CoffeeMakerAPI::NOT_EMPTY;
}

void M4HotWaterSource::start() {
	api->SetReliefValveState(CoffeeMakerAPI::CLOSED);
	api->SetBoilerState(CoffeeMakerAPI::BOILER_ON);
}
