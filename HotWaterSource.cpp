/*
 * HotWaterSource.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: eric
 */

#include "HotWaterSource.h"

// UI -> Used "TestableUserInterterface" so you wouldn't mock out the CoffeeMaker,
// with mocks for HotWaterSource and ContainmentVessel
// HotWaterSource -> Use a "real" M4HotWaterSource and mocks for the CoffeMakerAPI,
// ContainmentVessel and UI
// ContainmentVessel -> Use a real M4ContainmentVessel in your tests, use the StubCoffeeMakerApi,
// but use real version of M4HotWaterSource and M4UI


HotWaterSource::HotWaterSource() {
	// TODO Auto-generated constructor stub

}

HotWaterSource::~HotWaterSource() {
	// TODO Auto-generated destructor stub
}

