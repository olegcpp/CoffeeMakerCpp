#include <CppUTest/TestHarness.h>
#include <memory>
#include "UserInterface.h"
#include "HotWaterSource.h"
#include "ContainmentVessel.h"
#include "CoffeeMakerApi.h"

class StubCoffeeMaker : public CoffeeMakerAPI {

};

TEST_GROUP(UserInterface) {

};

TEST(UserInterface, test) {
	auto hws = std::make_shared<HotWaterSource>();
	auto cv = std::make_shared<ContainmentVessel>();
	CoffeeMakerApi *fakeCoffeeMaker = std::make_shared<StubCoffeeMaker>();

	UserInterface ui(hws, cv);
}
