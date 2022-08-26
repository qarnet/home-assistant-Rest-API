//
// Created by thomas on 26/08/22.
//
#include <string>
#ifndef HOME_ASSITANT_REST_API_REST_API_H
#define HOME_ASSITANT_REST_API_REST_API_H
class HomeAssistant{
private:
    std::string haIpPort, entityID, token;
public:
    HomeAssistant();
    void GET_api();
    void GET_api_config();
    void GET_api_events();
    void GET_api_services();
    void GET_api_history_period(std::string timestamp = "", //<timestamp> with format: YYYY-MM-DDThh:mm:ssTZD (E.G. 2022-06-11T00:00:00+00:00)
                                std::string filter_entity_id = "", //<entity_ids> with format: domain.service (E.G. sensor.weather_temperature)
                                std::string end_time = "", //<timestamp> with format: YYYY-MM-DDThh:mm:ssTZD (defaults to 1 day)
                                std::string minimal_response = "", //"minimal_response" or empty
                                std::string no_attributes = "", //"no_attributes" or empty
                                std::string significant_changes_only = "" //"significant_changes_only" or empty
                                );
    void GET_api_logbook(std::string timestamp = "",
                         std::string entity = "",
                         std::string end_time = ""
    );
    void GET_api_states();
    void GET_api_states(std::string /*entity_id*/);
    void GET_api_error_log();
    void GET_api_camera_proxy(std::string /*camera_entity_id*/);
    void GET_api_calendars();
    void GET_api_calendars(std::string calendar_entity_id = "", //E.G. calendar.holidays
                           std::string start = "", //dateTime or date
                           std::string end = "" //dateTime or date
    );
    void POST_api_states(std::string /*entity_id*/,
                         std::string /*data*/ //E.G. "state": "25", "attributes": {"unit_of_measurement": "°C"}
    );
    void POST_api_events(std::string /*event_type*/);
    void domainTurnOn(std::string /*domain*/, std::string /*service*/);
    void domainTurnOff(std::string /*domain*/, std::string /*service*/);
    void mqttPublish(std::string /*payload*/, std::string /*topic*/, std::string /*retain*/);
    void POST_api_template(std::string /*data*/);
    void POST_api_config_core_check_config();
    void POST_api_intent_handle(std::string /*data*/);

};
#endif //HOME_ASSITANT_REST_API_REST_API_H
