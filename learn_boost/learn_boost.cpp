//
// Created by yinlei on 2020/5/19.
//

#include "learn_boost.h"
#include <iostream>
#include <string>
#include <cassert>
#include "jsoncpp/json/json.h"
#include "myhtml/api.h"

/**
 * curl返回数据的回调函数。可以直接返回每次的数据量，不处理数据。使用string接收和处理。
 * 一旦收到需要保存的数据，libcurl 就会立即调用此回调函数。对于大多数传输，此回调将被调用多次，每次调用都会传递另一块数据。
 * ptr 指向传递的数据，该数据的大小为 nmemb；size大小始终为 1。
 * 关于该函数的使用说明可以参考 CURLOPT_WRITEFUNCTION explained 和 getinmemory.c
 *
 * @param ptr 指向传递的数据的指针，保存所有的数据。
 * @param size 每次都是1，size * nmemb 表示返回的数据长度
 * @param nmemb 每次返回的内容的长度
 * @param stream 数据流，本次收到的数据
 * @return
 */
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    auto *str = dynamic_cast<std::string *>((std::string *)stream); // 强制转换
    str->append((char*) ptr, size * nmemb); // size * mem 表示接受数据的多少
//    std::cout << *str << std::endl;
    return size * nmemb;
}

mystatus_t serialization_callback(const char* data, size_t len, void* ctx)
{
//    printf("%.*s", (int)len, data);
    std::cout << std::string(data) << std::endl;
    return MyCORE_STATUS_OK;
}

static bool filter_node(myhtml_tree_node_t* node)
{
    assert(node);
    myhtml_tag_id_t tag = myhtml_node_tag_id(node);
    return (tag != MyHTML_TAG__TEXT) && (tag != MyHTML_TAG__END_OF_FILE) && (tag != MyHTML_TAG__COMMENT) && (tag != MyHTML_TAG__UNDEF);
}

/* depth-first lefthand tree walk */
static void walk_subtree(myhtml_tree_t* tree, myhtml_tree_node_t* root, int level)
{
    if (!root) {
        return;
    }

    /* Check if we handle this node type */
    if (!filter_node(root)) {
        return;
    }

    /* start sexpr */
    putchar('(');

    /* print this node */
    printf("%s", myhtml_tag_name_by_id(tree, myhtml_node_tag_id(root), NULL));
    myhtml_tree_attr_t* attr = myhtml_node_attribute_first(root);
    while (attr != NULL) {
        /* attribute sexpr (name value)*/
        const char *key = myhtml_attribute_key(attr, NULL);
        const char *value = myhtml_attribute_value(attr, NULL);

        if(key == NULL)
            printf("(KEY IS NULL)");
        else if (value)
            printf("(%s \'%s\')", key, value);
        else
            printf("(%s)", key);

        attr = myhtml_attribute_next(attr);
    }

    /* left hand depth-first recoursion */
    myhtml_tree_node_t* child = myhtml_node_child(root);
    while (child != NULL) {
        walk_subtree(tree, child, level + 1);
        child = myhtml_node_next(child);
    }

    /* close sexpr */
    putchar(')');
}

int test_walk_tree(std::string &data)
{
    mystatus_t res;

    // basic init
    myhtml_t* myhtml = myhtml_create();
    if (!myhtml) {
        printf("myhtml_create failed\n");
    }

    res = myhtml_init(myhtml, MyHTML_OPTIONS_DEFAULT, 1, 0);
    if (MYHTML_FAILED(res)) {
        printf("myhtml_init failed with %d\n", res);
    }

    // init tree
    myhtml_tree_t* tree = myhtml_tree_create();
    if (!tree) {
        printf("myhtml_tree_create failed\n");
    }

    res = myhtml_tree_init(tree, myhtml);
    if (MYHTML_FAILED(res)) {
        printf("myhtml_tree_init failed with %d\n", res);
    }

    // parse html
    myhtml_parse(tree, MyENCODING_UTF_8, data.c_str(), data.size());

    walk_subtree(tree, myhtml_tree_get_node_html(tree), 0);
    printf("\n");

    // release resources
    myhtml_tree_destroy(tree);
    myhtml_destroy(myhtml);

    return EXIT_SUCCESS;
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

        // 遍历html tree
        test_walk_tree(response);

        // 初始化my html
        myhtml_t *myHtml = myhtml_create();
        myhtml_init(myHtml, MyHTML_OPTIONS_DEFAULT, 1, 0);
        // 初始化my html tree
        myhtml_tree_t *myHtmlTree = myhtml_tree_create();
        myhtml_tree_init(myHtmlTree, myHtml);

        // 解析html字符串
        myhtml_parse(myHtmlTree, MyENCODING_UTF_8, response.c_str(), response.size()); // size_type and size_t
        mycore_string_raw_t stringRaw = {nullptr};
        myhtml_serialization_tree_buffer(myhtml_tree_get_node_body(myHtmlTree), &stringRaw);
//        printf("%s\n", stringRaw.data);

        const char* attr_key = "type";
        // get and print
        myhtml_collection_t *collection = myhtml_get_nodes_by_attribute_key(myHtmlTree, NULL, NULL, attr_key, strlen(attr_key), NULL);
        for(size_t i = 0; i < collection->length; i++) {
            mycore_string_raw_t stringRawBuffer = {nullptr};
            // 这个回调会获取一个完整的div标签，但是没有标签内的内容啊
            myhtml_serialization_node_buffer(collection->list[i], &stringRawBuffer);
            std::cout << stringRawBuffer.data << std::endl;
            mycore_string_raw_destroy(&stringRawBuffer, false);
        }

        const char* name = "div";
        myhtml_collection_t *collection2 = myhtml_get_nodes_by_name(myHtmlTree, NULL, name, strlen(name), NULL);
        myhtml_collection_t *nodes_by_tag_id_collections = myhtml_get_nodes_by_tag_id(myHtmlTree, nullptr, MyHTML_TAG_DIV, nullptr);
        for(size_t i = 0; i < collection2->length; i++) {
            mycore_string_raw_t stringRawBuffer = {nullptr};
            mycore_string_raw_t childStringRawBuffer = {nullptr};
            // 这个回调会获取一个完整的div标签，但是没有标签内的内容啊
            myhtml_serialization_node_buffer(collection2->list[i], &stringRawBuffer);

            myhtml_tree_node_t *node_child = myhtml_node_child(collection2->list[i]);
            if (node_child) {
                myhtml_serialization_node_buffer(node_child, &childStringRawBuffer);
            }
            std::cout << stringRawBuffer.data << std::endl;
            std::cout << childStringRawBuffer.data << std::endl;
            mycore_string_raw_destroy(&stringRawBuffer, false);
            mycore_string_raw_destroy(&childStringRawBuffer, false);
        }

        for (size_t i = 0; i < nodes_by_tag_id_collections->length; i++) {
            myhtml_tree_node_t *tree_node = myhtml_node_child(nodes_by_tag_id_collections->list[i]);
            if (tree_node) {
                std::cout << myhtml_node_text(tree_node, nullptr) << std::endl;
            }
        }

        for(size_t i = 0; i < collection2->length; i++)
            myhtml_serialization_node_callback(collection2->list[i], serialization_callback, NULL);

        // parse html
        myhtml_parse_fragment(myHtmlTree, MyENCODING_UTF_8, response.c_str(), response.size(), MyHTML_TAG_DIV, MyHTML_NAMESPACE_HTML);

        // print fragment
        myhtml_serialization_tree_callback(myhtml_tree_get_document(myHtmlTree), serialization_callback, NULL);

        // 释放资源
        mycore_string_raw_destroy(&stringRaw, false);
        myhtml_tree_destroy(myHtmlTree);
        myhtml_destroy(myHtml);

        // 这里可以处理返回的值
        JSONCPP_STRING json_string; // std::string的别名
    } else {
        return -1;
    }
    return 0; // 7月10号，10点-11点。我们是第6组，200号，户口本原件复印件，要父母、户主、小朋友页。小朋友不需要去。
}

