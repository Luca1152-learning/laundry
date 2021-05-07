#include "Washable.h"

// Public
Washable::Washable(double minWashingTemperature, double maxWashingTemperature, bool mustBeWringed, bool mustBeIroned)
        : m_minWashingTemperature(minWashingTemperature), m_maxWashingTemperature(maxWashingTemperature),
          m_mustBeWringed(mustBeWringed), m_mustBeIroned(mustBeIroned) {}

double Washable::getNecessaryIroningTime() const {
    // The default for this function - is overridden in some subclasses
    throw runtime_error("This clothing type can't be ironed.");
}

bool Washable::mustBeWringed() const {
    return m_mustBeWringed;
}

bool Washable::mustBeIroned() const {
    return m_mustBeIroned;
}

double Washable::getMinWashingTemperature() const {
    return m_minWashingTemperature;
}

double Washable::getMaxWashingTemperature() const {
    return m_maxWashingTemperature;
}

bool Washable::didCompleteWashingCircuit() const {
    return m_didCompleteWashingCircuit;
}

void Washable::markWashingCircuitAsCompleted() {
    if (m_didCompleteWashingCircuit) {
        throw runtime_error("The washing circuit was already marked as completed. That's unexpected.");
    }

    m_didCompleteWashingCircuit = true;
}