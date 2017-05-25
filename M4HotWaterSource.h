/*
 * M4HotWaterSource.h
 *
 *  Created on: May 23, 2017
 *      Author: oleg
 */

#ifndef M4HOTWATERSOURCE_H_
#define M4HOTWATERSOURCE_H_

#include "CoffeeMakerApi.h"
#include "HotWaterSource.h"

#include <memory>
class M4HotWaterSource: public HotWaterSource {
public:
	M4HotWaterSource(std::shared_ptr<CoffeeMakerAPI> api)
	: api(api) {};
	virtual ~M4HotWaterSource();

public:
	virtual bool isReady();
	virtual void start();

private:
	std::shared_ptr<CoffeeMakerAPI> api;
};

#endif /* M4HOTWATERSOURCE_H_ */
