/*
 * M4UserInterface.cpp
 *
 *  Created on: May 14, 2017
 *      Author: oleg
 */

#include "M4UserInterface.h"

void M4UserInterface::checkButton() {
	if (PUSHED == api->GetBrewButtonStatus()) {
		startBrewing();
	}
}
