//
// Created by yinlei on 2020/5/19.
//

#include "learn_boost.h"
#include <iostream>
#include <string>
#include "jsoncpp/json/json.h"

/**
 * curl返回数据的回调函数。可以直接返回每次的数据量，不处理数据。使用string接收和处理。
 * 一旦收到需要保存的数据，libcurl 就会立即调用此回调函数。对于大多数传输，此回调将被调用多次，每次调用都会传递另一块数据。
 * ptr 指向传递的数据，该数据的大小为 data_length；size大小始终为 1。
 * 关于该函数的使用说明可以参考 CURLOPT_WRITEFUNCTION explained 和 getinmemory.c
 *
 * @param ptr 指向传递的数据的指针，保存所有的数据。
 * @param size 每次都是1，size * data_length 表示返回的数据长度
 * @param data_length 每次返回的内容的长度
 * @param stream 数据流，本次收到的数据
 * @return
 */
size_t write_data(void *ptr, size_t size, size_t data_length, void *stream) {
    auto *str = dynamic_cast<std::string *>((std::string *)stream); // 强制转换
    str->append((char*) ptr, size * data_length); // size * mem 表示接受数据的多少
//    std::cout << *str << std::endl;
    return size * data_length;
}

int main() {
    learn_boost learnBoost;
    std::cout << learnBoost.str << std::endl;

    // 一个程序只能调用一次，非线程安全的，参数一般是CURL_GLOBAL_ALL，除非你知道怎么控制curl
    curl_global_init(CURL_GLOBAL_ALL);
//    auto curl = curl_easy_init();
    CURL* curl = curl_easy_init(); // 获得curl的句柄
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com");
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
//    auto ipInfo = curl_easy_getinfo(curl, CURLINFO_LOCAL_IP, 0);
    auto result = curl_easy_perform(curl);
    curl_easy_cleanup(curl); // 清理，释放资源
    if (result == CURLcode::CURLE_OK) {
        std::cout << response << std::endl;
        // 这里可以处理返回的值
        JSONCPP_STRING json_string; // std::string的别名
    } else {
        return -1;
    }
    return 0; // 7月10号，10点-11点。我们是第6组，200号，户口本原件复印件，要父母、户主、小朋友页。小朋友不需要去。
}
