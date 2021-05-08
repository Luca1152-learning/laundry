#ifndef LAUNDRY_JACKET_H
#define LAUNDRY_JACKET_H

#include "../Clothing.h"
#include "../../laundry/washing/Washable.h"

// Sacou
class Jacket : public Clothing, public Washable {
public:
    explicit Jacket(
            double weight, bool hasDarkColor,
            double minWashingTemperature, double maxWashingTemperature,
            bool isSuitPiece = false
    );

    double getNecessaryDetergentQuantity() const override;

    double getNecessaryIroningTime() const override;

    bool isSuitPiece() const;

private:
    const bool m_isSuitPiece;
};

#endif //LAUNDRY_JACKET_H
