/*
 * M4ContainmentVessel.cpp
 *
 *  Created on: May 23, 2017
 *      Author: oleg
 */

#include "M4ContainmentVessel.h"

M4ContainmentVessel::~M4ContainmentVessel() {
	// TODO Auto-generated destructor stub
}

bool M4ContainmentVessel::isReady()
{
	CoffeeMakerAPI::WarmerPlateStatus status = api->GetWarmerPlateStatus();
	return status == CoffeeMakerAPI::POT_EMPTY;
}

void M4ContainmentVessel::start()
{

}
