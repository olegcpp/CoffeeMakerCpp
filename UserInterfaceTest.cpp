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

class TestableUserInterface : public UserInterface {
public:
	TestableUserInterface(
			std::shared_ptr<HotWaterSource> hws,
			std::shared_ptr<ContainmentVessel> cv,
			bool pushed = false, bool isBrewing = false)
	: UserInterface(hws, cv), pushed(pushed), isBrewing(isBrewing) {}
	virtual ~TestableUserInterface() {}
	virtual void checkButton() {
		startBrewing();
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

TEST(UserInterface, brewingNotStartIfHwsAndCVareNotReady) {
	auto hws = std::make_shared<StubHotWaterSource>();
	hws->ready = false;
	auto cv = std::make_shared<StubContainmentVessel>();
	cv->ready = false;

	TestableUserInterface ui(hws, cv);
	ui.checkButton();
	CHECK_FALSE(hws->isBrewing);
}

TEST(UserInterface, brewingStartsIfHwsAndCVAreReady) {
	auto hws = std::make_shared<StubHotWaterSource>();
	hws->ready = true;
	auto cv = std::make_shared<StubContainmentVessel>();
	cv->ready = true;

	TestableUserInterface ui(hws, cv);
	ui.checkButton();
	CHECK(hws->isBrewing);
}

TEST(UserInterface, brewingDoesNotStartIfCvIsNotReady) {
	auto hws = std::make_shared<StubHotWaterSource>();
	hws->ready = true;
	auto cv = std::make_shared<StubContainmentVessel>();
	cv->ready = false;

	TestableUserInterface ui(hws, cv);
	ui.checkButton();
	CHECK_FALSE(cv->isBrewing);
}

TEST(UserInterface, brewingDoesNotStartIfHwsIsNotReady) {
	auto hws = std::make_shared<StubHotWaterSource>();
	hws->ready = false;
	auto cv = std::make_shared<StubContainmentVessel>();
	cv->ready = true;

	TestableUserInterface ui(hws, cv);
	ui.checkButton();
	CHECK_FALSE(cv->isBrewing);
}
