/* vim: set ai et ts=4 sw=4: */
#ifndef __FONTS_H__
#define __FONTS_H__

#include <stdint.h>

typedef struct {
    const uint8_t width;
    uint8_t height;
    const uint16_t *data;
} FontDef;


extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;
/*
extern unsigned short testImage[];
extern const uint16_t gateBrandenburg_gate [];
extern const uint8_t dot_matrix[];
extern const uint8_t Brandenburg_gate_resized_bits[];*/

extern const uint16_t image_data_cat_resized[];
extern const uint8_t ming[];
extern const uint16_t acBrandenburg_gate_cropped_low[];
extern const uint16_t test_128x128[][128];
extern const uint16_t acBrandenburg_gate_cropped[120][94];
#endif // __FONTS_H__
