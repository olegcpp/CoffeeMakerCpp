/*
 * ContainmentVessel.h
 *
 *  Created on: Mar 6, 2017
 *      Author: eric
 */

#ifndef CONTAINMENTVESSEL_H_
#define CONTAINMENTVESSEL_H_

class ContainmentVessel {
public:
	ContainmentVessel();
	virtual ~ContainmentVessel();
	virtual bool isReady() = 0;
	virtual void start() = 0;
};

#endif /* CONTAINMENTVESSEL_H_ */
