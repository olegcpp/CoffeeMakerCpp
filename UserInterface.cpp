/*
 * UserInterface.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: eric
 */

#include "UserInterface.h"
#include "ContainmentVessel.h"
#include "HotWaterSource.h"

void UserInterface::startBrewing() {
	if (hws->isReady() && cv->isReady()) {
		hws->start();
		cv->start();
	}
}
