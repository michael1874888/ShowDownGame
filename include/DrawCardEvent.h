#ifndef DRAWCARDEVENT_H
#define DRAWCARDEVENT_H

#pragma once

class DrawCardEvent
{
public:
    DrawCardEvent();

    ~DrawCardEvent();

private:
    Hand *m_pHand;
};

#endif