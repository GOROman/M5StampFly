/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */
#include "Arduino.h"
#include <driver/ledc.h>
#include "buzzer.h"

const int buzzerPin = 40;
const int channel   = 5;

void setup_pwm_buzzer(void) {
    ledcSetup(channel, 4000, 8);        // 配置PWM通道：通道0，频率3000Hz，分辨率8位
    ledcAttachPin(buzzerPin, channel);  // 将PWM通道绑定到GPIO
}

void buzzer_sound(uint32_t frequency, uint32_t duration_ms) {
    ledcWriteTone(channel, frequency);
    ledcWrite(channel, 127);

    vTaskDelay(duration_ms / portTICK_PERIOD_MS);

    ledcWriteTone(channel, 0);
    digitalWrite(channel, 0);
}

void beep(void) {
    buzzer_sound(4000, 100);
}

void start_tone(void) {
    // Happy Birthday to you
    buzzer_sound(NOTE_G4, 200); // ソ
    buzzer_sound(NOTE_G4, 200); // ソ
    buzzer_sound(NOTE_A4, 400); // ラ
    buzzer_sound(NOTE_G4, 400); // ソ
    buzzer_sound(NOTE_C5, 400); // ド
    buzzer_sound(NOTE_B4, 800); // シ
    
    // Happy Birthday to you
    buzzer_sound(NOTE_G4, 200); // ソ
    buzzer_sound(NOTE_G4, 200); // ソ
    buzzer_sound(NOTE_A4, 400); // ラ
    buzzer_sound(NOTE_G4, 400); // ソ
    buzzer_sound(NOTE_D5, 400); // レ
    buzzer_sound(NOTE_C5, 800); // ド
    
    // Happy Birthday dear [name]
    buzzer_sound(NOTE_G4, 200); // ソ
    buzzer_sound(NOTE_G4, 200); // ソ
    buzzer_sound(NOTE_G5, 400); // 高ソ
    buzzer_sound(NOTE_E5, 400); // ミ
    buzzer_sound(NOTE_C5, 400); // ド
    buzzer_sound(NOTE_B4, 400); // シ
    buzzer_sound(NOTE_A4, 400); // ラ
    
    // Happy Birthday to you
    buzzer_sound(NOTE_F5, 200); // ファ
    buzzer_sound(NOTE_F5, 200); // ファ
    buzzer_sound(NOTE_E5, 400); // ミ
    buzzer_sound(NOTE_C5, 400); // ド
    buzzer_sound(NOTE_D5, 400); // レ
    buzzer_sound(NOTE_C5, 800); // ド
}
