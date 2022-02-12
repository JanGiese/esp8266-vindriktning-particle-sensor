
#ifndef MQTT_LOGGER_h
#define MQTT_LOGGER_h

#include <PubSubClient.h>
#include <string>

class MqttLogger {
    private:
        PubSubClient* mqttClient;
        bool useMqtt;
    public:
        std::string LOG_TOPIC;
        MqttLogger ();
        MqttLogger (PubSubClient* mqttClient, std::string logTopic);
        void startMqttLog();
        void print(const char* msg);
        void print(int msg);
        void println(const char* msg);
        void println(int msg);
        void println(String msg);

};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_EEPROM)
extern MqttLogger Logger;
#endif

#endif