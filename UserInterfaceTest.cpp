#include <CppUTest/TestHarness.h>
#include <memory>
#include "UserInterface.h"
#include "HotWaterSource.h"
#include "ContainmentVessel.h"
#include "CoffeeMakerApi.h"

class StubCoffeeMaker : public CoffeeMakerAPI {
public:
	StubCoffeeMaker(
			WarmerPlateStatus wps = POT_EMPTY,
			BoilerStatus bs = NOT_EMPTY,
			BrewButtonStatus bbs = PUSHED)
	: wps(wps), bs(bs), bbs(bbs) {}

	virtual ~StubCoffeeMaker() {};

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

class StubUserInterface : public UserInterface {
public:
	StubUserInterface(
			std::shared_ptr<HotWaterSource> hws,
			std::shared_ptr<ContainmentVessel> cv,
			bool pushed = false, bool isBrewing = false)
	: UserInterface(hws, cv), pushed(pushed), isBrewing(isBrewing) {}
	virtual ~StubUserInterface() {}
	virtual void checkButton() {
		if (pushed) {
			startBrewing();
		}
	}
public:
	bool pushed;
	bool isBrewing;
};

class StubHotWaterSource : public HotWaterSource {
public:
	StubHotWaterSource(bool ready = true, bool isBrewing = false)
	: ready(ready), isBrewing(isBrewing) {};
	virtual ~StubHotWaterSource() {};
	virtual bool isReady() {return ready; }
	virtual void start() {isBrewing = true;}
public:
	bool ready;
	bool isBrewing;
};

class StubContainmentVessel : public ContainmentVessel {
public:
	StubContainmentVessel(bool ready = true, bool isBrewing = false)
	: ready(ready), isBrewing(isBrewing) {};
	virtual ~StubContainmentVessel(){};

	virtual void start() {isBrewing = true;}
	virtual bool isReady() {return ready; }

public:
	bool ready;
	bool isBrewing;
};

TEST_GROUP(UserInterface) {

};

TEST(UserInterface, buttonNotPushedCheckIfHwsBrewing) {
	auto hws = std::make_shared<StubHotWaterSource>();
	auto cv = std::make_shared<StubContainmentVessel>();

	std::shared_ptr<CoffeeMakerAPI> fakeCoffeeMaker = std::make_shared<StubCoffeeMaker>();

	StubUserInterface ui(hws, cv);
	ui.pushed = false;
	ui.checkButton();
	CHECK_FALSE(hws->isBrewing);
}

TEST(UserInterface, buttonPushedCheckIfHwsBrewing) {
	auto hws = std::make_shared<StubHotWaterSource>();
	auto cv = std::make_shared<StubContainmentVessel>();

	std::shared_ptr<CoffeeMakerAPI> fakeCoffeeMaker = std::make_shared<StubCoffeeMaker>();

	StubUserInterface ui(hws, cv);
	ui.pushed = true;
	ui.checkButton();
	CHECK(hws->isBrewing);
}

TEST(UserInterface, buttonPushedCheckIfCVBrewing) {
	auto hws = std::make_shared<StubHotWaterSource>();
	auto cv = std::make_shared<StubContainmentVessel>();

	std::shared_ptr<CoffeeMakerAPI> fakeCoffeeMaker = std::make_shared<StubCoffeeMaker>();

	StubUserInterface ui(hws, cv);
	ui.pushed = true;
	ui.checkButton();
	CHECK(cv->isBrewing);
}
