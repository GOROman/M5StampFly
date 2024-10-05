/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef BUZZER_H
#define BUZZER_H

#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
//#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556

#define NOTE_C5 523   // ド (C5)
#define NOTE_D5 587   // レ (D5)
#define NOTE_E5 659   // ミ (E5)
#define NOTE_F5 698   // ファ (F5)
#define NOTE_G4 392   // ソ (G4)
#define NOTE_A4 440   // ラ (A4)
#define NOTE_B4 494   // シ (B4)
#define NOTE_G5 784   // 高いソ (G5)


void setup_pwm_buzzer(void);
void beep(void);
void start_tone(void);
void buzzer_sound(uint32_t frequency, uint32_t duration_ms);

#endif
