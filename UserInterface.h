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
	UserInterface(){};

	virtual ~UserInterface(){};
	void Init(std::shared_ptr<HotWaterSource> hws,
			std::shared_ptr<ContainmentVessel> cv) {
		this->hws = hws;
		this->cv = cv;
	}
	virtual void checkButton() = 0;
	void startBrewing();
};

#endif

