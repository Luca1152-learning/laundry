#ifndef LAUNDRY_SHIRT_H
#define LAUNDRY_SHIRT_H

#include "../Clothing.h"
#include "../../laundry/washing/Washable.h"

class Shirt : public Clothing, public Washable {
public:
    explicit Shirt(
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

#endif //LAUNDRY_SHIRT_H
