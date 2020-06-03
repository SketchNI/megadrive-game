#include <genesis.h>

const u32 tile[4 * 8] =
    {
        0x00001111,
        0x00001111,

        0x11112222,
        0x11112222,

        0x11110000,
        0x11110000,

        0x22221111,
        0x22221111};

void dnswHandler(u16 joy, u16 changed, u16 state)
{
    VDP_clearText(0, 0, 30);
    if (joy == JOY_1)
    {
        if (state & BUTTON_START)
        {
            VDP_drawText("Player 1 pressed Start", 0, 0);
        }
        else if (changed & BUTTON_START)
        {
            VDP_drawText("Player 1 released Start", 0, 0);
        }

        if (state & BUTTON_A)
        {
            VDP_drawText("Player 1 pressed A", 0, 0);
        }
        else if (changed & BUTTON_A)
        {
            VDP_drawText("Player 1 released A", 0, 0);
        }

        if (state & BUTTON_B)
        {
            VDP_drawText("Player 1 pressed B", 0, 0);
        }
        else if (changed & BUTTON_B)
        {
            VDP_drawText("Player 1 released B", 0, 0);
        }

        if (state & BUTTON_C)
        {
            VDP_drawText("Player 1 pressed C", 0, 0);
        }
        else if (changed & BUTTON_C)
        {
            VDP_drawText("Player 1 released C", 0, 0);
        }
    }
}

void init()
{
    VDP_loadTileData((const u32 *)tile, 1, 4, 0);

    VDP_drawText("Mega Drive Demo", 13, 8);
    VDP_drawText("Cuz I'm learning!", 12, 9);

    VDP_drawText("(C) Copyright Sketch 2020", 2, 26);
}

int main(u16 hard)
{
    if (hard == 0)
    {
        VDP_drawText("Rebooting...", 0, 0);
        waitMs(1000);
        VDP_clearText(0, 0, 13);
    }

    init();
    waitMs(500);
    VDP_clearTextArea(0, 0, 60, 60);

    JOY_init();
    JOY_setEventHandler(&dnswHandler);

    while (TRUE)
    {
        VDP_showFPS(FALSE);
        VDP_showCPULoad();
        VDP_waitVSync();
    }

    return 0;
}
