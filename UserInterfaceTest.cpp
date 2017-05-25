#include <CppUTest/TestHarness.h>
#include <memory>
#include "UserInterface.h"
#include "HotWaterSource.h"
#include "ContainmentVessel.h"
#include "CoffeeMakerApi.h"
#include "StubCoffeeMakerAPI.h"
#include "M4HotWaterSource.h"
#include "M4ContainmentVessel.h"


// UI -> Used "TestableUserInterterface" so you wouldn't mock out the CoffeeMaker,
// with mocks for HotWaterSource and ContainmentVessel
// HotWaterSource -> Use a "real" M4HotWaterSource and mocks for the CoffeMakerAPI,
// ContainmentVessel and UI
// ContainmentVessel -> Use a real M4ContainmentVessel in your tests, use the StubCoffeeMakerApi,
// but use real version of M4HotWaterSource and M4UI

class TestableUserInterface : public UserInterface {
public:
	TestableUserInterface(
			std::shared_ptr<HotWaterSource> hws,
			std::shared_ptr<ContainmentVessel> cv,
			bool pushed = false, bool isBrewing = false)
	: UserInterface(), pushed(pushed), isBrewing(isBrewing) {
		UserInterface::Init(hws, cv);
	}
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

class StubUserInterface : public UserInterface {
public:
	StubUserInterface(bool ready = true, bool isBrewing = false)
	: ready(ready), isBrewing(isBrewing) {};
	virtual ~StubUserInterface(){};

	virtual void start() {isBrewing = true;}
	virtual bool isReady() {return ready; }
	virtual void checkButton() {
		startBrewing();
	}

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

TEST_GROUP(HotWaterSource) {

};

TEST(HotWaterSource, checkIfReadyWhenBoilerEmpty)
{
	auto stubAPI = std::make_shared<StubCoffeeMakerAPI>();
	stubAPI->bs = CoffeeMakerAPI::EMPTY;
	std::shared_ptr<HotWaterSource> hws =
			std::make_shared<M4HotWaterSource>(M4HotWaterSource(stubAPI));

	std::shared_ptr<UserInterface> stubUI = std::make_shared<StubUserInterface>();
	std::shared_ptr<ContainmentVessel> stubCV = std::make_shared<StubContainmentVessel>();
	hws->Init(stubUI, stubCV);
	CHECK_FALSE(hws->isReady());
}

TEST_GROUP(ContainmentVessel) {

};

TEST(ContainmentVessel, checkIfReadyWhenPotNotEmpty)
{
	auto stubAPI = std::make_shared<StubCoffeeMakerAPI>();
	stubAPI->wps = CoffeeMakerAPI::POT_NOT_EMPTY;
	std::shared_ptr<ContainmentVessel> cv =
			std::make_shared<M4ContainmentVessel>(M4ContainmentVessel(stubAPI));

	std::shared_ptr<UserInterface> stubUI = std::make_shared<StubUserInterface>();
	std::shared_ptr<HotWaterSource> stubHWS = std::make_shared<StubHotWaterSource>();
	cv->Init(stubHWS, stubUI);
	CHECK_FALSE(cv->isReady());
}
