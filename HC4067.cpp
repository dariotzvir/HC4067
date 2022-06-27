#include "HC4067.h"

void HC4067::init()
{
    for(int i=0; i<POS_S; i++)
    {
        gpio_reset_pin(_s[i]);
        gpio_set_direction(_s[i], GPIO_MODE_OUTPUT);
    }

    gpio_reset_pin(_sig);
    gpio_set_direction(_sig, GPIO_MODE_OUTPUT);
    _mode = WRITE;
}

void HC4067::change_mode(mux_mode mode)
{
    _mode = mode;

    gpio_reset_pin(_sig);

    if(_mode == READ)
    {
        gpio_set_direction(_sig, GPIO_MODE_INPUT);
        gpio_set_pull_mode(_sig, GPIO_PULLUP_ONLY);
    }
    else if(_mode == WRITE)
    {
        gpio_set_direction(_sig, GPIO_MODE_OUTPUT);
    }
}

void HC4067::selec_s(uint8_t pos)
{
    if(_mode == WRITE) gpio_set_level(_sig, 0);
    for(int i=0; i<POS_S; i++)
    {
        bool n = (pos&(1<<i));
        gpio_set_level(_s[i], n);
    }

}

bool HC4067::read(uint8_t pos)
{
    if(_mode != READ) cambiar_mode(READ);

    selec_s(pos);

    return gpio_get_level(_sig);
}

void HC4067::write(uint8_t pos, bool val)
{
    if(_mode != WRITE) cambiar_mode(WRITE);
    selec_s(pos);

    gpio_set_level(_sig, val);
}