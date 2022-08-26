#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <string>
#include "Rest_API.h"
#include <filesystem>

class HomeAssistant{
private:
    std::string haIpPort, entityID, token;

public:
    //Constructor, will read out the port/ip of home-assistant and the token from the secrets file
    HomeAssistant(){
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
    void GET_api(){
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
    void GET_api_config(){

    }

    //GET - /api/events
    void GET_api_events(){

    }

    //GET - /api/services
    void GET_api_services(){

    }

    //GET - /api/history/period/<timestamp>
    void GET_api_history_period(std::string timestamp){

    }

    //GET - /api/logbook/<timestamp>
    void GET_api_logbook(std::string timestamp){

    }

    //GET - /api/states
    void GET_api_states(){

    }

    //GET - /api/states/<entity_id>
    void GET_api_states(std::string entity_id){

    }

    //GET - /api/error_log
    void GET_api_error_log(){

    }

    //GET - /api/camera_proxy/<camera entity_id>
    void GET_api_camera_proxy(std::string camera_entity_id){

    }

    //GET - /api/calendars
    void GET_api_calendars(){

    }

    //GET - /api/calendars/<calendar entity_id>
    void GET_api_calendars(std::string calendar_entity_id){

    }

    //POST - /api/states/<entity_id>
    void POST_api_states(std::string entity_id){

    }

    //POST - /api/events/<event_type>
    void POST_api_events(std::string event_type){

    }

    //POST - /api/services/<domain>/<services>
    void domainTurnOn(std::string domain, std::string service){
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
    void domainTurnOff(std::string domain, std::string service){
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
    void mqttPublish(std::string payload, std::string topic, std::string retain){
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
    void POST_api_template(){

    }

    //POST - /api/config/core/check_config
    void POST_api_config_core_check_config(){

    }

    //POST - /api/intent/handle
    void POST_api_intent_handle(){

    }
};

int main() {
    HomeAssistant ha;
    //ha.domainTurnOff("switch", "thomas_fernseher");
    ha.GET_api();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
