#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include <memory>
class HotWaterSource;
class ContainmentVessel;

class UserInterface {
private:
	std::shared_ptr<HotWaterSource> hws;
	std::shared_ptr<ContainmentVessel> cv;
public:
	UserInterface(
			std::shared_ptr<HotWaterSource> hws,
			std::shared_ptr<ContainmentVessel> cv)
	: hws(hws), cv(cv){};

	virtual ~UserInterface(){};

	virtual void checkButton() = 0;
	void startBrewing();
};

#endif

