#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <string>
#include "Rest_API.h"

//class HomeAssistant{
//private:
//    std::string haIpPort, entityID, token;

//public:
    //Constructor, will read out the port/ip of home-assistant and the token from the secrets file
    HomeAssistant::HomeAssistant(){
        std::string searchHaIpPort = "HAIPPORT";
        std::string searchToken = "TOKEN";
        std::string currentLine;
        //std::string filename = "/home/thomas/CLionProjects/home-assitant-Rest-API/secrets"; //Change to relative Filepath!!!!!!!!!!!
        std::string filename = "secrets.txt";
        std::ifstream secretsFile(filename);
        if(!secretsFile.is_open()){
            std::cout << "File failed to open: " << filename << "\n";
        }
        else{
            while(getline(secretsFile, currentLine)){
                if(currentLine.find(searchHaIpPort) != std::string::npos){
                    haIpPort = currentLine.substr(searchHaIpPort.length() + 1);
                    //std::cout << haIpPort << "\n"; //Debug
                }
                if(currentLine.find(searchToken) != std::string::npos){
                    token = currentLine.substr(searchToken.length() + 1);
                    //std::cout << token << "\n"; //Debug
                }
            }
        }

    }

    //GET - /api/
    void HomeAssistant::GET_api(){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/config
    void HomeAssistant::GET_api_config(){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/config";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/events
    void HomeAssistant::GET_api_events(){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/events";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/services
    void HomeAssistant::GET_api_services(){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/services";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/history/period/<timestamp>
    //No arguments defaults to 1 day before the time of the request
    //NOT DONE
    void HomeAssistant::GET_api_history_period(std::string timestamp, //<timestamp> with format: YYYY-MM-DDThh:mm:ssTZD (E.G. 2022-06-11T00:00:00+00:00)
                                std::string filter_entity_id, //<entity_ids> with format: domain.service (E.G. sensor.weather_temperature)
                                std::string end_time, //<timestamp> with format: YYYY-MM-DDThh:mm:ssTZD (defaults to 1 day)
                                std::string minimal_response, //"minimal_response" or empty
                                std::string no_attributes, //"no_attributes" or empty
                                std::string significant_changes_only //"significant_changes_only" or empty
                                        ){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/history/period/" + timestamp;
        if(!filter_entity_id.empty()){

        }
        else if(!end_time.empty()){

        }
        else if(!minimal_response.empty()){

        }
        else if(!no_attributes.empty()){

        }
        else if(!significant_changes_only.empty()){

        }
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }


    //GET - /api/logbook/<timestamp>
    void HomeAssistant::GET_api_logbook(std::string timestamp,
                         std::string entity,
                         std::string end_time
                                 ){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/logbook/";
        if(!timestamp.empty()){

        }
        else if(!entity.empty()){

        }
        else if(!end_time.empty()){

        }
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/states
    void HomeAssistant::GET_api_states(){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/states";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/states/<entity_id>
    void HomeAssistant::GET_api_states(std::string entity_id){ //E.G. sensor.kitchen_temperature
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/states/" + entity_id;
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/error_log
    void HomeAssistant::GET_api_error_log(){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/error_log";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/camera_proxy/<camera entity_id>
    void HomeAssistant::GET_api_camera_proxy(std::string camera_entity_id){ //E.G. camera.my_sample_camera
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/camera_proxy/" + camera_entity_id;
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/calendars
    void HomeAssistant::GET_api_calendars(){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/calendars";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //GET - /api/calendars/<calendar entity_id>
    void HomeAssistant::GET_api_calendars(std::string calendar_entity_id, //E.G. calendar.holidays
                           std::string start, //dateTime or date
                           std::string end //dateTime or date
                                   ){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/calendars/";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
            curl_easy_cleanup(curl);
        }
        return;
    }

    //POST - /api/states/<entity_id>
    void HomeAssistant::POST_api_states(std::string entity_id,
                         std::string data //E.G. "state": "25", "attributes": {"unit_of_measurement": "°C"}
                         ){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/states/"+ entity_id;
        //std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
        std::string postfields = "{" + data + "}";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &postfields[0]);
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    //POST - /api/events/<event_type>
    //NOT DONE!!!!!!!!!
    void HomeAssistant::POST_api_events(std::string event_type){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/events/"+ event_type;
        //std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
        //no postfields needed?
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &postfields[0]);
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    //POST - /api/services/<domain>/<services>
    void HomeAssistant::domainTurnOn(std::string domain, std::string service){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/services/"+ domain + "/turn_on";
        std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &postfields[0]);
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    //POST - /api/services/<domain>/<services>
    void HomeAssistant::domainTurnOff(std::string domain, std::string service){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/services/"+ domain + "/turn_off";
        std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &postfields[0]);
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    //POST - /api/services/<domain>/<services>
    void HomeAssistant::mqttPublish(std::string payload, std::string topic, std::string retain){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/services/mqtt/publish";
        std::string postfields = "{\"payload\": \"" + payload + "\", \"topic\": \"" + topic + "\", \"retain\": \"" + retain + "\"}";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &postfields[0]);
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            std::cout << url << std::endl << postfields << std::endl << auth;
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    //POST - /api/template
    void HomeAssistant::POST_api_template(std::string data){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/template";
        //std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
        std::string postfields = "{" + data + "}";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &postfields[0]);
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    //POST - /api/config/core/check_config
    void HomeAssistant::POST_api_config_core_check_config(){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "/api/config/core/check_config";
        //std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
        //no postfields needed????
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &postfields[0]);
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    //POST - /api/intent/handle
    void HomeAssistant::POST_api_intent_handle(std::string data){
        CURL *curl;
        struct curl_slist *list = NULL;
        CURLcode res;
        std::string url = "http://" + haIpPort + "api/intent/handle";
        //std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
        std::string postfields = "{" + data + "}";
        std::string auth = "Authorization: Bearer " + token;

        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &postfields[0]);
            list = curl_slist_append(list, &auth[0]);
            list = curl_slist_append(list, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed");
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }
//};

