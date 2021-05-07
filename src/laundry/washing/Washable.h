#ifndef LAUNDRY_WASHABLE_H
#define LAUNDRY_WASHABLE_H

#include <stdexcept>
#include "HistoryObject.h"

using namespace std;

class Washable : public HistoryObject {
public:
    // The normal range for washing temperature
    static constexpr double MIN_WASHING_TEMPERATURE = 10;
    static constexpr double MAX_WASHING_TEMPERATURE = 90;

    explicit Washable(
            double minWashingTemperature, double maxWashingTemperature,
            bool mustBeWringed = true, bool mustBeIroned = true
    );

    virtual double getNecessaryDetergentQuantity() const = 0;

    virtual double getNecessaryIroningTime() const;

    bool mustBeWringed() const;

    bool mustBeIroned() const;

    double getMinWashingTemperature() const;

    double getMaxWashingTemperature() const;

    bool didCompleteWashingCircuit() const;

    void markWashingCircuitAsCompleted();

    virtual ~Washable() = default;

protected:
    // The size of the standard measure of detergent (in grams) used for washing a piece of clothing
    const double STANDARD_DETERGENT_QUANTITY = 80;

private:
    const double m_minWashingTemperature, m_maxWashingTemperature;
    const bool m_mustBeWringed, m_mustBeIroned;
    bool m_didCompleteWashingCircuit = false;
};

#endif //LAUNDRY_WASHABLE_H
