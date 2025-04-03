#include "data_container.h"
#include "indicator_calculator.h"
#include "json_writer.h"

int main() {
    DataContainer container;
    container.loadFromFile("Tab_2_25.csv");

    IndicatorCalculator::calculateMovingAverage(container, 15);
    IndicatorCalculator::calculateCloseDependence(container);

    JSONWriter::saveToJson(container, "Tab_2_26.json");

    return 0;
}
