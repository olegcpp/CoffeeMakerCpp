#ifndef HOTWATERSOURCE_H_
#define HOTWATERSOURCE_H_
#include <memory>

class UserInterface;
class ContainmentVessel;

class HotWaterSource {
public:
	HotWaterSource();
	virtual ~HotWaterSource();
	virtual bool isReady() = 0;
	virtual void start() = 0;
	void Init(std::shared_ptr<UserInterface> ui,
			std::shared_ptr<ContainmentVessel> cv) {
		this->ui = ui;
		this->cv = cv;
	}
private:
	std::shared_ptr<UserInterface> ui;
	std::shared_ptr<ContainmentVessel> cv;
};

#endif
