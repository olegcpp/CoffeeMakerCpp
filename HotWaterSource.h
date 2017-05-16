#ifndef HOTWATERSOURCE_H_
#define HOTWATERSOURCE_H_

class HotWaterSource {
public:
	HotWaterSource();
	virtual ~HotWaterSource();
	virtual bool isReady() = 0;
	virtual void start() = 0;
};

#endif
