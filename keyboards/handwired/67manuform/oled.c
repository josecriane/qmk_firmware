#include "67manuform.h"

#ifdef OLED_DRIVER_ENABLE
char timer_str[10];
uint32_t anim_sleep = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
}

static void render_layer(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("L: "), false);

    switch (get_highest_layer(layer_state)) {
				case DVORAK:
					oled_write("Dvorak", false);
					break;
				case MOD:
					oled_write_ln("Mods", true);
					break;
				case ARR:
					oled_write_ln("Arrows", false);
					break;
				case GAME:
					oled_write_ln("Gaming", false);
					break;
				case M_DVORAK:
					oled_write_ln("M Dvora", false);
					break;
				case M_MOD:
					oled_write_ln("M mods", false);
					break;
				case M_ARR:
					oled_write_ln("M arrow", false);
					break;
				case CH:
					oled_write_ln("Changin", false);
					break;
				default:
					oled_write_ln("Unknown", false);
					break;
    }
}

bool check_off(void)
{
		if(get_current_wpm() != 000) {
				oled_on();
				anim_sleep = timer_read32();
		} else if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
				oled_off();
				return false;
		}
		return true;
}

void oled_task_user(void) {
  if (is_keyboard_master() && check_off()) {
		render_layer();
  }
}

#endif
