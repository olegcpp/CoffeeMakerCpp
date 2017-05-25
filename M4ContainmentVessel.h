/*
 * M4ContainmentVessel.h
 *
 *  Created on: May 23, 2017
 *      Author: oleg
 */

#ifndef M4CONTAINMENTVESSEL_H_
#define M4CONTAINMENTVESSEL_H_

#include "CoffeeMakerApi.h"
#include "ContainmentVessel.h"

#include <memory>

class M4ContainmentVessel: public ContainmentVessel {
public:
	M4ContainmentVessel(std::shared_ptr<CoffeeMakerAPI> api)
	: api(api) {
		lastPotStatus = api->GetWarmerPlateStatus();
	};
	virtual ~M4ContainmentVessel();
public:
	virtual bool isReady();
	virtual void start();
private:
	std::shared_ptr<CoffeeMakerAPI> api;
	CoffeeMakerAPI::WarmerPlateStatus lastPotStatus;

};

#endif /* M4CONTAINMENTVESSEL_H_ */
