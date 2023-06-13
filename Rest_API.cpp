#include "Rest_API.h"


//Constructor, will read out the port/ip of home-assistant and the token
HomeAssistant::HomeAssistant(std::string haipport, std::string token){
    this->haIpPort = haipport;
    this->token = token;
}

CURLcode HomeAssistant::curlGetFormatter(std::string _request)
{
    CURL *curl;
    struct curl_slist *list = NULL;
    CURLcode res;
    std::string url = "http://" + this->haIpPort + _request;
    std::string auth = "Authorization: Bearer " + this->token;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, &url[0]);
        //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Follow redirects
        list = curl_slist_append(list, &auth[0]);
        list = curl_slist_append(list, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed");
            std::cout << res;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return res;
}

CURLcode HomeAssistant::curlPostFormatter(std::string _url, std::string _postfields)
{
    CURL *curl;
    struct curl_slist *list = NULL;
    CURLcode res;
    std::string url = _url;
    std::string postfields = _postfields;
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
        {
            fprintf(stderr, "curl_easy_perform() failed");
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return res;
}

void HomeAssistant::GET_api(){
    this->curlGetFormatter("/api/");
}

void HomeAssistant::GET_api_config(){
    this->curlGetFormatter("/api/config");
}

void HomeAssistant::GET_api_events(){
    this->curlGetFormatter("/api/events");
}

void HomeAssistant::GET_api_services(){
    this->curlGetFormatter("/api/services");
}

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

void HomeAssistant::GET_api_states(){
    this->curlGetFormatter("/api/states");
}

void HomeAssistant::GET_api_states(std::string entity_id){ //E.G. sensor.kitchen_temperature
    this->curlGetFormatter("/api/states/" + entity_id);
}

void HomeAssistant::GET_api_error_log(){
    this->curlGetFormatter("/api/error_log");
}

void HomeAssistant::GET_api_camera_proxy(std::string camera_entity_id){ //E.G. camera.my_sample_camera
    this->curlGetFormatter("/api/camera_proxy/" + camera_entity_id);
}

//Doesn't work? 404
void HomeAssistant::GET_api_calendars(){
    this->curlGetFormatter("/api/calendars");
}

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

void HomeAssistant::domainTurnOn(std::string domain, std::string service){
    std::string url = "http://" + haIpPort + "/api/services/"+ domain + "/turn_on";
    std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";

    this->curlPostFormatter(url, postfields);
}

void HomeAssistant::domainTurnOff(std::string domain, std::string service){
    std::string url = "http://" + haIpPort + "/api/services/"+ domain + "/turn_off";
    std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";

    this->curlPostFormatter(url, postfields);
}

void HomeAssistant::mqttPublish(std::string payload, std::string topic, std::string retain){
    std::string url = "http://" + haIpPort + "/api/services/mqtt/publish";
    std::string postfields = "{\"payload\": \"" + payload + "\", \"topic\": \"" + topic + "\", \"retain\": \"" + retain + "\"}";

    this->curlPostFormatter(url, postfields);
}

void HomeAssistant::POST_api_template(std::string data){
    std::string url = "http://" + haIpPort + "/api/template";
    //std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
    std::string postfields = "{" + data + "}";

    this->curlPostFormatter(url, postfields);
}

void HomeAssistant::POST_api_config_core_check_config(){

    std::string url = "http://" + haIpPort + "/api/config/core/check_config";
    //std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
    //no postfields needed????
    this->curlPostFormatter(url, "");
}

void HomeAssistant::POST_api_intent_handle(std::string data){
    std::string url = "http://" + haIpPort + "api/intent/handle";
    //std::string postfields = "{\"entity_id\": \"" + domain + "." + service + "\"}";
    std::string postfields = "{" + data + "}";

    this->curlPostFormatter(url, postfields);
}

