#include <stdint.h>

#include <furi.h>
#include <gui/gui.h>
#include <dialogs/dialogs.h>

#include <mp_flipper_modflipperzero.h>

#define MP_FLIPPER_GPIO_PIN_OFF     (1 << 15)
#define MP_FLIPPER_GPIO_PIN_BLOCKED (1 << 7)
#define MP_FLIPPER_GPIO_PIN_PWM     ((MP_FLIPPER_GPIO_PIN_BLOCKED) | (1 << 8))

typedef uint16_t mp_flipper_gpio_pin_t;

typedef struct {
    Gui* gui;
    ViewPort* view_port;
    Canvas* canvas;
    FuriPubSub* input_event_queue;
    FuriPubSubSubscription* input_event;
    DialogMessage* dialog_message;
    const char* dialog_message_button_left;
    const char* dialog_message_button_center;
    const char* dialog_message_button_right;
    FuriHalAdcHandle* adc_handle;
    mp_flipper_gpio_pin_t* gpio_pins;
} mp_flipper_context_t;
