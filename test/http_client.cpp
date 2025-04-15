#include "../src/HttpClient.h"
#include <iostream>

int main() {
    try {
        HttpClient client("http://127.0.0.1:8001");
        {
            std::string response = client.get("/api/v1/health");
            std::cout << "GET response: " << response << std::endl;
        }
        {
            std::string response = client.get("/api/v1/state");
            std::cout << "GET response: " << response << std::endl;
        }
        {
            std::string postData = R"({"kitchen":"on"})";
            std::string postResp = client.post("/api/v1/state", postData, {
                "Content-Type: application/json"
            });
            std::cout << "POST response: " << postResp << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "HTTP error: " << e.what() << std::endl;
    }

    return 0;
}
