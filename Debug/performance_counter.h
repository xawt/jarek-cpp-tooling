#ifndef _JAREK_PERFORMANCE_COUNTER_
#define _JAREK_PERFORMANCE_COUNTER_

#include <iostream>

//! \brief CPU performance counter based time measurement.
//!
//! Performance counter of the CPU enables reliable sub-microsecond measurements of time.
//! When an object of this class is created it stores the value of the counter and subsequent 
//! calls to ReadCounter return the difference between start and the readout. 
//! The time delta is read out in microseconds but include fractional part.
//! \note Only for Windows XP and above.
class PerformanceCounter {

    public:

        PerformanceCounter();

        /// \brief Resets the start point.
        void Reset();

        /// \brief Read out the time delta.
        double ReadCounter();

    //Not possible!
    /*enum TimeResolution {
        milisecond = 1000.0,
        microsecond = 1000000.0, 
        
    };*/

    private:    
        double PCfrequency {0};
        std::int64_t start {0};

        constexpr static double resolution = 1000000.0;  //microseconds
};

#endif