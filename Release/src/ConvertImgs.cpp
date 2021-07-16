#include "Logic.hpp"
#include "esp_spiffs.h"
#include "ConvertImgs.hpp"
#include <iostream>
#include <cstdio>

void convertImgPre () {
    // Konfigurace datového oddílu
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = NULL,
        .max_files = 5,
        .format_if_mount_failed = true,
    };

    // Připojení datového oddílu na /spiffs
    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            printf("Failed to mount or format filesystem\n");
        } else if (ret == ESP_ERR_NOT_FOUND) {
            printf("Failed to find SPIFFS partition\n");
        } else {
            printf("Failed to initialize SPIFFS (%d)\n", ret);
        }
        return;
    }
}

void convertImgSnake() {

    // Otevření souboru
    FILE* soubor = fopen("/spiffs/SnakeIcon.data", "r");
    if (!soubor) {
        printf("Failed to open file: %s\n", strerror(errno));
        return;
    }

    // Načtení dat ze souboru, pixel po pixelu.
    uint8_t pixel[3];
    for (int i = 0; i < display.width() * display.height(); ++i) {
        size_t res = fread(pixel, 1, 3, soubor);
        if (res != 3) {
            printf("Nepodarilo se precist 3 byty %d\n", res);
            break;
        }
        // Nastavení do displeje
        display[i] = Rgb(pixel[0], pixel[1], pixel[2]);
    }

    // Zavření souboru - nezapomeňte na to!
    fclose(soubor);

    display.show();
}

void convertImgFlappyBird () {

    // Otevření souboru
    FILE* soubor = fopen("/spiffs/FlappyBirdLogo.data", "r");
    if (!soubor) {
        printf("Failed to open file: %s\n", strerror(errno));
        return;
    }

    // Načtení dat ze souboru, pixel po pixelu.
    uint8_t pixel[3];
    display.clear();
    for (int i = 0; i < display.width() * display.height(); ++i) {
        size_t res = fread(pixel, 1, 3, soubor);
        //printf("%dx%d: %d:%d:%d %d\n", i%10, i/10, pixel[0], pixel[1], pixel[2], res);
        if (res != 3) {
            printf("Nepodarilo se precist 3 byty %d\n", res);
            break;
        }
        // Nastavení do displeje
        display[i] = Rgb(pixel[0], pixel[1], pixel[2]);
    }

    // Zavření souboru - nezapomeňte na to!
    fclose(soubor);

    display.show();
}

void convertImgMineSweeper() {


    // Otevření souboru
    FILE* soubor = fopen("/spiffs/MineSweeperLogo.data", "r");
    if (!soubor) {
        printf("Failed to open file: %s\n", strerror(errno));
        return;
    }

    // Načtení dat ze souboru, pixel po pixelu.
    uint8_t pixel[3];
    for (int i = 0; i < display.width() * display.height(); ++i) {
        size_t res = fread(pixel, 1, 3, soubor);
        if (res != 3) {
            printf("Nepodarilo se precist 3 byty %d\n", res);
            break;
        }
        // Nastavení do displeje
        display[i] = Rgb(pixel[0], pixel[1], pixel[2]);
    }

    // Zavření souboru - nezapomeňte na to!
    fclose(soubor);

    display.show();
}