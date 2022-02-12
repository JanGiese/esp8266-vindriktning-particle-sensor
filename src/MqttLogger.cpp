#include "MqttLogger.h"
#include "Arduino.h"

MqttLogger::MqttLogger (PubSubClient* mqttClient, std::string logTopic) {
    Serial.begin(115200);
    this->useMqtt = false;
    this->println("initializing logger");
    this->mqttClient = mqttClient;
    this->LOG_TOPIC = logTopic;
    this->println("logger initialized");
};
void MqttLogger::startMqttLog(){
    this->useMqtt = true;
    this->println("Start mqtt logging");
}

void MqttLogger::print(const char* msg){
    Serial.print(msg);
    if (this->useMqtt) {
        this->mqttClient->publish(this->LOG_TOPIC.c_str(), msg);
    }
};
void MqttLogger::print(int msg){
    char cstr[16];
    itoa(msg, cstr, 10);
    this->print(cstr);
};
void MqttLogger::println(const char* msg){
    this->print(msg);
    this->print("\n");
};
void MqttLogger::println(int msg){
    char cstr[16];
    itoa(msg, cstr, 10);
    this->println(cstr);
};
void MqttLogger::println(String msg){
    this->println(msg.c_str());
};

