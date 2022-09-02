#include <SPI.h> //INCLUSÃO DE BIBLIOTECA
#include <MFRC522.h> //INCLUSÃO DE BIBLIOTECA



#define SS_PIN 10 //PINO SDA
#define RST_PIN 9 //PINO DE RESET



/////Json
#include <ArduinoJson.h>
const int TAMANHO = 50;  //define o tamanho do buffer para o json




#include <Servo.h>  //importa a biblioteca do servo motor



Servo myservo1;      // cria o objeto meuservo



MFRC522 rfid(SS_PIN, RST_PIN); //PASSAGEM DE PARÂMETROS REFERENTE AOS PINOS



void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  SPI.begin(); //INICIALIZA O BARRAMENTO SPI
  rfid.PCD_Init(); //INICIALIZA MFRC522



 myservo1.attach(5);  // configura o pino 9 do arduino para o servo motor
  
}



void loop() {
  
  StaticJsonDocument<TAMANHO> json; //Aloca buffer para objeto json
  
  if (Serial.available() > 0) {
    //Lê o JSON disponível na porta serial:
    deserializeJson(json, Serial);
    if(json.containsKey("motor")) {
      int valor = json["motor"];
      myservo1.write(valor);
    }
  }
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) //VERIFICA SE O CARTÃO PRESENTE NO LEITOR É DIFERENTE DO ÚLTIMO CARTÃO LIDO. CASO NÃO SEJA, FAZ
    return; //RETORNA PARA LER NOVAMENTE



 /***INICIO BLOCO DE CÓDIGO RESPONSÁVEL POR GERAR A TAG RFID LIDA***/
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();
  /***FIM DO BLOCO DE CÓDIGO RESPONSÁVEL POR GERAR A TAG RFID LIDA***/



 //Serial.print("Identificador (UID) da tag: "); //IMPRIME O TEXTO NA SERIAL
  //Serial.println(strID); //IMPRIME NA SERIAL O UID DA TAG RFID



 rfid.PICC_HaltA(); //PARADA DA LEITURA DO CARTÃO
  rfid.PCD_StopCrypto1(); //PARADA DA CRIPTOGRAFIA NO PCD





 //formato de escrita do json
  json["tagid"] = strID;



 serializeJson(json, Serial);
  Serial.println();





 
}
