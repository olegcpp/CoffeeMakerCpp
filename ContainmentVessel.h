/*
 * ContainmentVessel.h
 *
 *  Created on: Mar 6, 2017
 *      Author: eric
 */
#ifndef CONTAINMENTVESSEL_H_
#define CONTAINMENTVESSEL_H_

#include <memory>

class HotWaterSource;
class UserInterface;

class ContainmentVessel {
public:
	ContainmentVessel()
	: isBrewing(false), isComplete(true) {}
	virtual ~ContainmentVessel();

	void Init(std::shared_ptr<HotWaterSource> hws,
			std::shared_ptr<UserInterface> ui) {
		this->hws = hws;
		this->ui = ui;
	}
	virtual bool isReady() = 0;
	virtual void start() = 0;

private:
	std::shared_ptr<HotWaterSource> hws;
	std::shared_ptr<UserInterface> ui;

	bool isBrewing;
	bool isComplete;

};

#endif /* CONTAINMENTVESSEL_H_ */
