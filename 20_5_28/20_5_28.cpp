#include <iostream>
#include <string>

#include "httplib.h"

int main()
{
    using namespace httplib;
    Server svr;
    //拉姆达表达式，是一个回调注册
    svr.Get("/", [](const Request& req, Response& resp){
            (void)req;
            resp.set_content("<html><h1>linux-61 niubi</h1></html>", "text/html");
            });
    svr.listen("0.0.0.0", 18888);
    return 0;
}