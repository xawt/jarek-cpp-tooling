
#include "performance_counter.h"
#include <windows.h>

//! Basic constructor that reads out the frequency of the counter 
//! and sets the start time.
PerformanceCounter::PerformanceCounter() {
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        throw("Counter Failed");
    PCfrequency = double(li.QuadPart)/resolution;   //we need micro-seconds
    Reset();
}

//! Sets the start time to the current time.
void PerformanceCounter::Reset() {
    LARGE_INTEGER li;               
    QueryPerformanceCounter(&li);
    start = li.QuadPart;
}

//! Returns the difference between the current time and the start time in microseconds.
//! @return Time delta in microseconds.
double PerformanceCounter::ReadCounter() {
    LARGE_INTEGER li;               //Q: how this line will affect the performance?
    QueryPerformanceCounter(&li);   //This always work on OS with WinXP and above
    return static_cast<double>(li.QuadPart-start)/PCfrequency;
}