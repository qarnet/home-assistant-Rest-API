#ifndef HOME_ASSISTANT_REST_API_REST_API_H
#define HOME_ASSISTANT_REST_API_REST_API_H
#include <string>
#include <iostream>
#include <curl/curl.h>
#include <string>

class HomeAssistant{
private:
    std::string ha_ip_port, entity_ID, token;
    CURLcode curlGetFormatter(std::string _request);
    CURLcode curlPostFormatter(std::string _url, std::string _postfields);
public:
    HomeAssistant(std::string _ha_ip_port, std::string _token);
    // Works
    void getApi();
    // Works
    void getApiConfig();
    // Works
    void getApiEvents();
    // Works
    void getApiServices();
    void getApiHistoryPeriod(std::string _timestamp, //<timestamp> with format: YYYY-MM-DDThh:mm:ssTZD (E.G. 2022-06-11T00:00:00+00:00)
                                std::string _filter_entity_id, //<entity_ids> with format: domain.service (E.G. sensor.weather_temperature)
                                std::string _end_time, //<timestamp> with format: YYYY-MM-DDThh:mm:ssTZD (defaults to 1 day)
                                std::string _minimal_response, //"minimal_response" or empty
                                std::string _no_attributes, //"no_attributes" or empty
                                std::string _significant_changes_only); //"significant_changes_only" or empty
    void getApiLogbook(std::string _timestamp,
                         std::string _entity,
                         std::string _end_time);
    // Works
    void getApiStates();
    // Works
    void getApiStates(std::string _entity_id);
    // Works
    void getApiErrorLog();
    void getApiCameraProxy(std::string _camera_entity_id);
    void getApiCalendars();
    void getApiCalendars(std::string _calendar_entity_id, //E.G. calendar.holidays
                           std::string _start, //dateTime or date
                           std::string _end); //dateTime or date
    void postApiStates(std::string _entity_id,
                         std::string _data); //E.G. "state": "25", "attributes": {"unit_of_measurement": "°C"}
    void postApiEvents(std::string _event_type);
    // Works
    void domainTurnOn(std::string _domain, std::string _service);
    // Works
    void domainTurnOff(std::string _domain, std::string _service);
    void mqttPublish(std::string _payload, std::string _topic, std::string _retain);
    void postApiTemplate(std::string _data);
    void postApiConfigCoreCheckConfig();
    void postApiIntentHandle(std::string _data);

};
#endif //HOME_ASSISTANT_REST_API_REST_API_H
