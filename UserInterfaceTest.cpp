#include <CppUTest/TestHarness.h>
#include <memory>
#include "UserInterface.h"
#include "HotWaterSource.h"
#include "ContainmentVessel.h"
#include "CoffeeMakerApi.h"

class StubCoffeeMaker : public CoffeeMakerAPI {
public:
	virtual ~StubCoffeeMaker() {};
	virtual WarmerPlateStatus GetWarmerPlateStatus() {return WARMER_EMPTY;};
 	virtual BoilerStatus GetBoilerStatus() {return EMPTY;};
	virtual BrewButtonStatus GetBrewButtonStatus() {return PUSHED;};
	virtual void SetBoilerState(BoilerState s) {};
	virtual void SetWarmerState(WarmerState s) {};
	virtual void SetIndicatorState(IndicatorState s) {};
	virtual void SetReliefValveState(ReliefValveState s) {};
};

TEST_GROUP(UserInterface) {

};

TEST(UserInterface, test) {
	auto hws = std::make_shared<HotWaterSource>();
	auto cv = std::make_shared<ContainmentVessel>();

	std::shared_ptr<CoffeeMakerAPI> fakeCoffeeMaker = std::make_shared<StubCoffeeMaker>();

	UserInterface ui(hws, cv);
}
