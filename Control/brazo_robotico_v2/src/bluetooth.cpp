#include <BluetoothSerial.h>
#include "configuration.h"
#include "bluetooth.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

bool BT_client(){
    return SerialBT.hasClient();
}

void BTbegin(String name){
    SerialBT.begin(name);
}

int BT_available(){
    return SerialBT.available();
}

String BT_read(){ //se arma el mensaje que se ha enviado
    String message = "";
    while (SerialBT.available()){ 
        char incomingChar = SerialBT.read();
        if (incomingChar != '\n'){
            message += String(incomingChar);
        }
        else{
        }
    }
    return message;
}