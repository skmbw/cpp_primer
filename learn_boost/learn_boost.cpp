//
// Created by yinlei on 2020/5/19.
//

#include "learn_boost.h"
#include <iostream>

int main() {
    learn_boost learnBoost;
    std::cout << learnBoost.str << std::endl;

    // 一个程序只能调用一次，非线程安全的，参数一般是CURL_GLOBAL_ALL，除非你知道怎么控制curl
    curl_global_init(CURL_GLOBAL_ALL);
//    auto curl = curl_easy_init();
    CURL* curl = curl_easy_init(); // 获得curl的句柄
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com");
    auto ipInfo = curl_easy_getinfo(curl, CURLINFO_LOCAL_IP, 0);
    auto result = curl_easy_perform(curl);

    curl_easy_cleanup(curl); // 清理，释放资源
    return 0;
}
