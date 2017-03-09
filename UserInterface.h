#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_
#include <memory>
class HotWaterSource;
class ContainmentVessel;

class UserInterface {
private:

public:
	UserInterface(std::shared_ptr<HotWaterSource>, std::shared_ptr<ContainmentVessel>);
	virtual ~UserInterface();
};

#endif

