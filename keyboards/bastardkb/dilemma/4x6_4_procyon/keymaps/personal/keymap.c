/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_ONE,
    LAYER_TWO,
    LAYER_THREE,
    LAYER_POINTER,
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define L_1 MO(LAYER_ONE)
#define L_2 MO(LAYER_TWO)
#define L_3 MO(LAYER_THREE)

#define LT_L3_GUI LT(LAYER_THREE, KC_LGUI)
#define LT_L2_SPC LT(LAYER_TWO, KC_SPC)

#define T_C_ENT LCTL_T(KC_ENT)
#define T_C_Z LCTL_T(KC_Z)
#define T_C_SLSH RCTL_T(KC_SLSH)

#define T_A_NO LALT_T(KC_NO)
#define T_A_TAB LALT_T(KC_TAB)

#define T_G_DOT RGUI_T(KC_DOT)
#define T_G_X LGUI_T(KC_X)
#define T_G_ENT LGUI_T(KC_ENT)

//#define T_CS_CAPS LCS_T(KC_CAPS)
#define T_CS_CAPS LCTL_T(CW_TOGG) //caps word

#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        T_A_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    LT_A_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       T_CS_CAPS,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,  T_C_Z,   T_G_X,   KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, T_G_DOT, T_C_SLSH,KC_RSFT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX,  LT_L3_GUI,L_1,  OS_LSFT,   T_C_ENT, LT_L2_SPC,L_1,  XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_ONE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_F2,   C(KC_F5),G(KC_E), LCA(KC_R),C(KC_T),  C(KC_Y), KC_HOME, KC_UP,   KC_END, KC_NO, S(KC_BSLS),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, TD(TD_1), TD(TD_2), TD(TD_0), C(KC_F), KC_F3,    KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_F12,    KC_PGUP,LCS(KC_LEFT),_______,LCS(KC_RIGHT),KC_PGDN, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, _______, KC_NO,   _______,    KC_LSFT,   KC_BSPC, KC_LGUI, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_TWO] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     S(KC_GRV),  S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),   S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINUS),S(KC_DEL),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_7,    KC_8,    KC_9,    KC_0,    KC_RGUI, KC_SCLN,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, S(KC_SLSH), KC_NO, KC_NO,  S(KC_6), KC_6,       S(KC_6), S(KC_SLSH),KC_COMM,KC_DOT, KC_SLSH, KC_BSLS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, KC_LGUI, KC_BSPC, L_3,        _______, KC_NO,   _______, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_THREE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  KC_KB_VOLUME_UP,LCG(KC_1),LCG(KC_2),LCG(KC_3),LCG(KC_4),LCG(KC_5),KC_F6, _______, LCA(KC_UP), _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       G(KC_G), G(KC_1),  G(KC_2), G(KC_3), G(KC_4), G(KC_5),   XXXXXXX, LSG(KC_LEFT), LCA(KC_DOWN), LSG(KC_RIGHT), KC_RGUI, KC_RGUI,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  KC_KB_VOLUME_DOWN, KC_F1, KC_F2, KC_F3,   KC_F4,   KC_F5,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, KC_NO,    KC_LGUI,KC_KB_MUTE, T_G_ENT, KC_BSPC, KC_NO,   XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, MS_BTN2, MS_BTN1, MS_BTN3,    MS_BTN3, MS_BTN1, MS_BTN2, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};
// clang-format on

// Tap Dance

// Tap Dance declarations
enum {
    TD_0,
    TD_1,
    TD_2
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_0] = ACTION_TAP_DANCE_DOUBLE(S(KC_F3), KC_LGUI), // (x, y) tap once for x, tap twice for y
    [TD_1] = ACTION_TAP_DANCE_DOUBLE(C(KC_A), KC_LSFT),
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(C(KC_S), KC_LCTL)
};

// combos
enum {
    cb_f_d,
    cb_w_d,
    cb_d_s,
    cb_s_f,
    cb_q_w,
    cb_a_f,
    cb_home_up,
    cb_up_end,
    cb_j_k,
    cb_k_l,
    cb_u_o,
    cb_u_o_i,
    cb_m_comm,
    cb_comm_dot,
    cb_f_d_s,
    cb_l_semi,
    cb_dot_slash,
    cb_v_b,
    cb_r_t,
    cb_caps_a_l3,
    cb_f_g_l3,
    cb_c_v,
    cb_x_c,
    cb_z_x,
    cb_l_semi,
    cb_tab_q,
    cb_q_r
}

const uint16_t PROGMEM cb_f_d[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM cb_w_d[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM cb_d_s[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM cb_s_f[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM cb_q_w[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM cb_a_f[] = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM cb_home_up[] = {KC_HOME, KC_UP, COMBO_END};
const uint16_t PROGMEM cb_up_end[] = {KC_UP, KC_END, COMBO_END};
const uint16_t PROGMEM cb_j_k[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cb_k_l[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cb_u_o[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM cb_u_o_i[] = {KC_U, KC_O, KC_I COMBO_END};
const uint16_t PROGMEM cb_m_comm[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cb_comm_dot[] = {KC_COMM, T_G_DOT, COMBO_END};
const uint16_t PROGMEM cb_f_d_s[] = {KC_F, KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM cb_l_semi[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM cb_dot_slash[] = {T_G_DOT, T_C_SLSH, COMBO_END};
const uint16_t PROGMEM cb_v_b[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cb_r_t[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cb_caps_a_l3[] = {C(KC_CAPS), KC_A, LT(LAYER_THREE, KC_LGUI), COMBO_END};
const uint16_t PROGMEM cb_f_g_l3[] = {KC_F, KC_G, LT(LAYER_THREE, KC_LGUI), COMBO_END};
const uint16_t PROGMEM cb_c_v[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cb_x_c[] = {G(KC_X), KC_C, COMBO_END};
const uint16_t PROGMEM cb_z_x[] = {C(KC_Z), G(KC_X), COMBO_END};
const uint16_t PROGMEM cb_l_semi[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM cb_tab_q[] = {A(KC_TAB), KC_Q, COMBO_END};
const uint16_t PROGMEM cb_q_r[] = {KC_Q, KC_R, COMBO_END};

combo_t key_combos[] = {
    COMBO(cb_f_d, S(KC_MINUS)),
    COMBO(cb_w_d, KC_EQUAL),
    COMBO(cb_d_s, KC_MINUS),
    COMBO(cb_s_f, S(KC_EQUAL)),
    COMBO(cb_q_w, KC_GRAVE),
    COMBO(cb_a_f, KC_ESC),
    COMBO(cb_home_up, KC_LBRC),
    COMBO(cb_up_end, KC_RBRC),
    COMBO(cb_j_k, S(KC_9)),
    COMBO(cb_k_l, S(KC_0)),
    COMBO(cb_u_o, KC_LBRC),
    COMBO(cb_u_o_i, KC_RBRC),
    COMBO(cb_m_comm, S(KC_LBRC)),
    COMBO(cb_comm_dot, S(KC_RBRC)),
    COMBO(cb_f_d_s, KC_ESC),
    COMBO(cb_l_semi, S(KC_SCLN)),
    COMBO(cb_dot_slash, S(KC_DOT)),
    COMBO(cb_v_b, G(KC_V)),
    COMBO(cb_r_t, KC_PRINT_SCREEN),
    COMBO(cb_caps_a_l3, LSG(KC_TAB)),
    COMBO(cb_f_g_l3, G(KC_TAB)),
    COMBO(cb_c_v, C(KC_V)),
    COMBO(cb_x_c, G(KC_C)),
    COMBO(cb_z_x, C(KC_X)),
    COMBO(cb_l_semi, S(KC_SCLN)),
    COMBO(cb_tab_q, S(KC_GRAVE)),
    COMBO(cb_q_r, KC_ESC)
};

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLEE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_ONE]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_TWO]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_THREE]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
