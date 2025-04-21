#include <igloo/igloo.h>
#include <unistd.h>
#include "../src/Application.h"
#include <thread>

using namespace igloo;
using namespace bobcat;

Context(AppTest){

    static Application* app;

    static void func(){
        app->run();
    }

    void SetUp(){
        std::cout.flush();
    }

    void TearDown(){
        std::thread t1(func);
        usleep(2000000);
        t1.detach();
    }
};

Application* AppTest::app = new Application();

int main(int argc, const char** argv){
    return TestRunner::RunAllTests(argc, argv);
}