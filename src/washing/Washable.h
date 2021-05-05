#ifndef LAUNDRY_WASHABLE_H
#define LAUNDRY_WASHABLE_H

class Washable {
public:
    explicit Washable(bool mustBeWringed = true, bool mustBeIroned = true)
            : m_mustBeWringed(mustBeWringed), m_mustBeIroned(mustBeIroned) {}

private:
    bool m_mustBeWringed, m_mustBeIroned;
};

#endif //LAUNDRY_WASHABLE_H
