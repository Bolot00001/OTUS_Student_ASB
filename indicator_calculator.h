#ifndef INDICATOR_CALCULATOR_H
#define INDICATOR_CALCULATOR_H

#include "data_container.h"
#include <vector>
#include <thread>
#include <mutex>

class IndicatorCalculator {
public:
    static void calculateMovingAverage(DataContainer& container, int period);
    static void calculateCloseDependence(DataContainer& container);
};

#endif
