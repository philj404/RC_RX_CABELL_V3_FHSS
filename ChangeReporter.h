// ChangeReporter.h
// Reports changes of a value if logged value goes beyond a threshold.
// Phil Jansen 3nov2021
//
#ifndef ChangeReporter_h
#define ChangeReporter_h

#include <Arduino.h>
#include <Streaming.h>

class ChangeReporter {
    public:
        ChangeReporter(long initValue, const char * msg, long delta = 0, bool allowDrift = true)
            : lastValue(initValue),
              delta(delta),
              message(msg),
              numHits(0),
              allowDrift(allowDrift)
        { };

        bool log(long newValue) {
	    bool bigChange = (abs(newValue - lastValue) > delta);
            if (bigChange) {
                Serial
                        << message << F(" ")
                        << numHits << F("hits at about ")
                        << lastValue << F("; but now: ") << newValue
                        << endl;
                numHits = 1;
            } else {
                numHits++;
            }
            if (allowDrift) {
                lastValue = newValue; // allows for drift
            }
	    return bigChange;
        };

        long lastValue;
        long delta;
        const char * message;
        long numHits;
        bool allowDrift;
};

#endif
