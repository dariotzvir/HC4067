#pragma once

#ifndef _HC4067_H_
#define _HC4067_H_

#include <driver/gpio.h>
#include "config_global.h"
#include "esp_log.h"
#include "esp_timer.h"


typedef enum
{
    READ,
    WRITE
} 
mux_mode;


class HC4067
{
    const gpio_num_t _sig;
    const gpio_num_t *_s;
    mux_mode _mode;
    
    void selec_s     (uint8_t pos);
    void change_mode (mux_mode mode);

public:
    HC4067(const gpio_num_t sig, const gpio_num_t *s):
    _sig(sig), _s(s)
    {};

    void init  ();
    bool read  (uint8_t pos);
    void write (uint8_t pos, bool val);    
};


#endif