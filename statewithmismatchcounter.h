#ifndef STATEWITHMISMATCHCOUNTER_H
#define STATEWITHMISMATCHCOUNTER_H


#include "baseregister.h"

class StateWithMismatchCounter : public BaseRegister
{
public:
    StateWithMismatchCounter();
    StateWithMismatchCounter(const PosInt& stateSize);
    StateWithMismatchCounter(const PosInt& stateSize, const QString& initialState, const PosInt &rootStateIndex);
    StateWithMismatchCounter(const PosInt& stateSize, const BitArray& initialState, const PosInt &rootStateIndex);
    void setInitialState( const BitArray& initialState);

    void addToMismatch( const Real& value);
    void setMismatchValue( const Real& value);
    Real mismatchCount() const;

    bool suggestedValueExists() const;
    Bit getSuggestedValue() const;
    void setSuggestedValue( const Bit& bit);
    void clearSuggestedValue();

    StateWithMismatchCounter *clone() const;

    BitArray getRootState() const;
    void setRootState(const BitArray &RootState);

    PosInt getRootStateIndex() const;
    void setRootStateIndex(const PosInt &rootStateIndex);

    void resetToOrigin();
    PosInt getRegisterSize() const;

    Real getSuggestedValueCount() const;//NEW!
    void setSuggestedValueCount(const Real &suggestedValueCount);//NEW!
    void incrementSuggestedValueCount();

    #if defined(CLOCK_DEBUG)
    PosInt getClockCount() const;
    void incrementClockCount();
    void setClockCount(const PosInt &clockCount);
    #endif

    #if defined(SIEVE_MODE)
    PosInt getStoredClock() const;
    void setStoredClock(const PosInt &storedClock);
    #endif

private:
    PosInt m_rootStateIndex = 0;
    Real m_mismatchCount = 0;
    Real m_suggestedValueCount = 0;//NEW!
    #if defined(CLOCK_DEBUG)
    PosInt m_clockCount = 0; //NEW!!
    #endif
    #if defined(SIEVE_MODE)
    PosInt m_storedClock = 0;
    #endif
    bool m_suggestedValueExists = false;
    Bit m_suggestedValue = 0;
    BitArray m_RootState;

};

#endif // STATEWITHMISMATCHCOUNTER_H
