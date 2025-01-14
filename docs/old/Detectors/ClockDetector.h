#include "Detector.h"
#include "ev3api.h"
#include "Clock.h"

using namespace ev3api;

#ifndef CLOCKDETECTER_H
#define CLOCKDETECTER_H

class ClockDetector : public Detector
{
private:
  Clock *clock;
  unsigned int threshold;
  int prev_clock;

public:
  ClockDetector(int threshold);

  void init();
  /**
     * detect - 時間の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
  bool detect();
  virtual ~ClockDetector();
};

#endif