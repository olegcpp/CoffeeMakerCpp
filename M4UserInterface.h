/*
 * M4UserInterface.h
 *
 *  Created on: May 14, 2017
 *      Author: oleg
 */

#ifndef M4USERINTERFACE_H_
#define M4USERINTERFACE_H_
#include <memory>

#include "CoffeeMakerApi.h"
#include "UserInterface.h"

class M4UserInterface: public UserInterface {
public:
	M4UserInterface(std::shared_ptr<CoffeeMakerAPI> api,
					std::shared_ptr<HotWaterSource> hws,
					std::shared_ptr<ContainmentVessel> cv)
	: UserInterface(hws, cv), api(api) {};
	virtual ~M4UserInterface() {};

	void checkButton();
private:
	std::shared_ptr<CoffeeMakerAPI> api;
};

#endif /* M4USERINTERFACE_H_ */
