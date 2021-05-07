#include "Costume.h"

// Public
Costume::Costume(double pantsWeight, bool pantsHaveDarkColor, double pantsMinWashingTemperature,
                 double pantsMaxWashingTemperature, double shirtWeight, bool shirtHasDarkColor,
                 double shirtMinWashingTemperature, double shirtMaxWashingTemperature, double jacketWeight,
                 bool jacketHasDarkColor, double jacketMinWashingTemperature, double jacketMaxWashingTemperature)
        : m_pants(pantsWeight, pantsHaveDarkColor, pantsMinWashingTemperature, pantsMaxWashingTemperature),
          m_shirt(shirtWeight, shirtHasDarkColor, shirtMinWashingTemperature, shirtMaxWashingTemperature),
          m_jacket(jacketWeight, jacketHasDarkColor, jacketMinWashingTemperature, jacketMaxWashingTemperature),
          Washable(10, 100) // TODO - Costume nu ar trebui sa fie Washable
{}

double Costume::getNecessaryDetergentQuantity() const {
    return m_pants.getNecessaryDetergentQuantity() + m_shirt.getNecessaryDetergentQuantity() +
           m_jacket.getNecessaryDetergentQuantity();
}

double Costume::getNecessaryIroningTime() const {
    return m_pants.getNecessaryIroningTime() + m_shirt.getNecessaryIroningTime() +
           m_jacket.getNecessaryIroningTime();
}

