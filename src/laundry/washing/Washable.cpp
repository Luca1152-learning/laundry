#include "Washable.h"

// Public
Washable::Washable(double minWashingTemperature, double maxWashingTemperature, bool mustBeWringed, bool mustBeIroned)
        : m_minWashingTemperature(minWashingTemperature), m_maxWashingTemperature(maxWashingTemperature),
          m_mustBeWringed(mustBeWringed), m_mustBeIroned(mustBeIroned) {}

double Washable::getNecessaryIroningTime() const {
    // The default for this function - is overridden in some subclasses
    throw runtime_error("This clothing type can't be ironed.");
}

void Washable::addHistoryEvent(const string &historyEvent) {
    m_history.addHistoryEvent(historyEvent);
}

void Washable::printHistory() {
    m_history.printHistory();
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