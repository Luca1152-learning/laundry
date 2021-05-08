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
    if (not m_wasWashed) {
        return false;
    }

    if (not m_wasWringed and m_mustBeWringed) {
        return false;
    }

    if (not m_wasDried) {
        return false;
    }

    if (not m_wasIroned and m_mustBeIroned) {
        return false;
    }

    return true;
}

void Washable::markAsWashed() {
    if (m_wasWashed) {
        throw runtime_error("This item was already marked as having been washed. That's unexpected.");
    }

    m_wasWashed = true;
}

void Washable::markAsWringed() {
    if (m_wasWringed) {
        throw runtime_error("This item was already marked as having been wringed. That's unexpected.");
    }

    m_wasWringed = true;
}

void Washable::markAsDried() {
    if (m_wasDried) {
        throw runtime_error("This item was already marked as having been dried. That's unexpected.");
    }

    m_wasDried = true;
}

void Washable::markAsIroned() {
    if (m_wasIroned) {
        throw runtime_error("This item was already marked as having been ironed. That's unexpected.");
    }

    m_wasIroned = true;
}

bool Washable::wasWashed() const {
    return m_wasWashed;
}

bool Washable::wasWringed() const {
    return m_wasWringed;
}

bool Washable::wasDried() const {
    return m_wasDried;
}

bool Washable::wasIroned() const {
    return m_wasIroned;
}