#include "indicator_calculator.h"

void IndicatorCalculator::calculateMovingAverage(DataContainer& container, int period) {
    std::vector<DataRow>& data = container.getData();
    std::mutex mtx;

    std::thread movingAverageThread([&]() {
        for (size_t i = period - 1; i < data.size(); ++i) {
            double sum = 0;
            for (size_t j = i - period + 1; j <= i; ++j) {
                sum += data[j].Close;
            }
            std::lock_guard<std::mutex> lock(mtx);
            data[i].RSI = sum / period;
        }
    });

    movingAverageThread.join();
}

void IndicatorCalculator::calculateCloseDependence(DataContainer& container) {
    std::vector<DataRow>& data = container.getData();
    std::mutex mtx;

    std::thread closeThread([&]() {
        for (auto& row : data) {
            std::lock_guard<std::mutex> lock(mtx);
            row.Bull = row.Close / row.Bollindg_h_h;
            row.Bear = row.Close / row.Bollindg_l_l;
        }
    });

    closeThread.join();
}
