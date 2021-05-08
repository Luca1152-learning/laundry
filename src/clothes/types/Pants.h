#ifndef LAUNDRY_PANTS_H
#define LAUNDRY_PANTS_H

#include "../Clothing.h"
#include "../../laundry/washing/Washable.h"

class Pants : public Clothing, public Washable {
public:
    explicit Pants(
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

#endif //LAUNDRY_PANTS_H
