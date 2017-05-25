/*
 * StubCoffeeMakerAPI.h
 *
 *  Created on: May 23, 2017
 *      Author: oleg
 */

#ifndef STUBCOFFEEMAKERAPI_H_
#define STUBCOFFEEMAKERAPI_H_

#include "CoffeeMakerApi.h"

class StubCoffeeMakerAPI : public CoffeeMakerAPI {
public:
	StubCoffeeMakerAPI(
			WarmerPlateStatus wps = POT_EMPTY,
			BoilerStatus bs = NOT_EMPTY,
			BrewButtonStatus bbs = PUSHED)
	: wps(wps), bs(bs), bbs(bbs) {}

	virtual ~StubCoffeeMakerAPI() {};

	virtual WarmerPlateStatus GetWarmerPlateStatus() {return wps;};
 	virtual BoilerStatus GetBoilerStatus() {return bs;};
	virtual BrewButtonStatus GetBrewButtonStatus() {return bbs;};
	virtual void SetBoilerState(BoilerState s) {};
	virtual void SetWarmerState(WarmerState s) {};
	virtual void SetIndicatorState(IndicatorState s) {};
	virtual void SetReliefValveState(ReliefValveState s) {};

public:
	WarmerPlateStatus wps;
	BoilerStatus bs;
	BrewButtonStatus bbs;
};

#endif /* STUBCOFFEEMAKERAPI_H_ */
