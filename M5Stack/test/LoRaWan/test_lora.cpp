/**
 * @brief fichier test du M5Stack pour module Lora
 * @author Benaitier Loris
 * @date 05/05/2022
 * @version 0.1
 */

#include <M5Core2.h>
#include <unity.h>
#include "fonction_send_lora.h"

/**
 * @brief fonction d'initialisation du programme
 * @param none
 * @return none
 */
void setup() {
    M5.begin();
    Serial.begin(9600);

    UNITY_BEGIN();
    RUN_TEST([](){
        TEST_ASSERT_EQUAL(lora::is_init, false); //test qui vérifie que is_init est bien initialisé a false
    });

    lora::init();

    RUN_TEST([](){
        TEST_ASSERT_EQUAL(lora::is_init, true); //test qui vérifie que is_init passe bien a true après init()
    });
}


/**
 * @brief boucle d'exécution du programme
 * @param none
 * @return none
 */
void loop() {
    navi::data_navi data;
    lora::Send_Message_Lorawan(data);
    
    Serial.println("ok");
    
    delay(100);
    UNITY_END(); // termine le test unitaire
}