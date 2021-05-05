#ifndef LAUNDRY_WASHABLE_H
#define LAUNDRY_WASHABLE_H

#include <stdexcept>

using namespace std;

class Washable {
public:
    // The size of the standard measure of detergent (in grams) used for washing a piece of clothing
    const double STANDARD_DETERGENT_QUANTITY = 80;

    explicit Washable(bool mustBeWringed = true, bool mustBeIroned = true)
            : m_mustBeWringed(mustBeWringed), m_mustBeIroned(mustBeIroned) {}

    virtual double getNecessaryDetergentQuantity() const = 0;

    virtual double getNecessaryIroningTime() const {
        // The default for this function - is overridden in some subclasses
        throw runtime_error("This clothing type can't be ironed.");
    };

    virtual ~Washable() = default;

private:
    bool m_mustBeWringed, m_mustBeIroned;
};

#endif //LAUNDRY_WASHABLE_H
