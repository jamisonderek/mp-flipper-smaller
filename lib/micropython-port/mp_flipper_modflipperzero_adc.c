#include <furi_hal.h>

#include <mp_flipper_modflipperzero.h>
#include <mp_flipper_runtime.h>

#include "mp_flipper_context.h"

inline static FuriHalAdcChannel decode_pin_to_adc_channel(uint8_t pin) {
    switch(pin) {
    case MP_FLIPPER_GPIO_PIN_PC0:
        return FuriHalAdcChannel1;
    case MP_FLIPPER_GPIO_PIN_PC1:
        return FuriHalAdcChannel2;
    case MP_FLIPPER_GPIO_PIN_PC3:
        return FuriHalAdcChannel4;
    case MP_FLIPPER_GPIO_PIN_PA4:
        return FuriHalAdcChannel9;
    case MP_FLIPPER_GPIO_PIN_PA6:
        return FuriHalAdcChannel11;
    case MP_FLIPPER_GPIO_PIN_PA7:
        return FuriHalAdcChannel12;
    default:
        return FuriHalAdcChannelNone;
    }
}

inline uint16_t mp_flipper_adc_read_pin(uint8_t raw_pin) {
    mp_flipper_context_t* ctx = mp_flipper_context;

    furi_check(ctx->adc_handle, "missing ADC handle");

    FuriHalAdcChannel channel = decode_pin_to_adc_channel(raw_pin);

    return furi_hal_adc_read(ctx->adc_handle, channel);
}

inline float mp_flipper_adc_convert_to_voltage(uint16_t value) {
    mp_flipper_context_t* ctx = mp_flipper_context;

    furi_check(ctx->adc_handle, "missing ADC handle");

    return furi_hal_adc_convert_to_voltage(ctx->adc_handle, value);
}