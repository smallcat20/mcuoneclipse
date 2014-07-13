/*
 * Application.c
 *
 *  Created on: 07.07.2014
 *      Author: tastyger
 */

#include "Application.h"
#include "NeoPixel.h"
#include "NeoLine.h"
#include "WAIT1.h"
#include "Cpu.h"

static void APP_Run(void) {
  (void)NEO_ClearAllPixel();
  (void)NEO_TransferPixels();

  NEO_SetPixelRGB(0, 1, 1, 1);
  NEO_SetPixelRGB(1, 2, 2, 3);
  NEO_SetPixelRGB(2, 3, 3, 3);
  NEO_SetPixelRGB(3, 4, 4, 4);
  (void)NEO_TransferPixels();
  WAIT1_Waitms(500);
  for (;;) {
    (void)NEOL_PixelTrail(0xff, 0x00, 0x00, NEO_PIXEL_FIRST, NEO_PIXEL_LAST,  8, 25, 80);
    (void)NEOL_PixelTrail(0x00, 0xff, 0x00, NEO_PIXEL_FIRST, NEO_PIXEL_LAST, 10, 25, 30);
    (void)NEOL_PixelTrail(0x00, 0x00, 0xff, NEO_PIXEL_FIRST, NEO_PIXEL_LAST,  8, 25, 30);
    (void)NEOL_PixelTrail(0x7F, 0x00, 0x7F, NEO_PIXEL_FIRST, NEO_PIXEL_LAST,  8, 25, 20);
    (void)NEOL_PixelTrail(0x00, 0xff, 0xff, NEO_PIXEL_FIRST, NEO_PIXEL_LAST,  8, 30, 20);
    (void)NEOL_PixelTrail(0xff, 0xff, 0xff, NEO_PIXEL_FIRST, NEO_PIXEL_LAST,  8, 40, 20);
    (void)NEOL_PixelTrail(0x20, 0x40, 0x60, NEO_PIXEL_FIRST, NEO_PIXEL_LAST,  8, 50, 10);
  }
  /* at the end, clear all */
  (void)NEO_ClearAllPixel();
  (void)NEO_TransferPixels();
}

void APP_Start(void) {
  NEO_Init();
  Cpu_EnableInt(); /* enable interrupts */
  APP_Run();
}
