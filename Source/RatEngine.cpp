/*
  ==============================================================================

    RatEngine.cpp
    Created: 11 Feb 2022 2:06:39am
    Author:  Charles S. Hubbard, Jr.

  ==============================================================================
*/

#include "RatEngine.h"
#include <string>
#include <iostream>
//#include <chrono>
//#include <thread>
/*
RatEngine::RatEngine(int portno) {
    cbport = portno;
    connectToSocket("127.0.0.1", cbport, 10000);
    std::string mystr = "Hello World!";
    bool sent;
    for (int r = 0; r < 4; r++) {
        MemoryBlock myMessage;
        myMessage.setSize(12);
        for (int i = 0; i < 12; i++) {
            myMessage[i] = mystr[i];
        }
        sent = sendMessage(myMessage);
    }
    int g;
    std::cin >> g;
    //startTimer(100000);
//    std::function<void()> endItAll = [&]() {this->active = false; };
//    while (active) {
//        callAfterDelay(100000, endItAll);
//    }
}*/

RatEngine::RatEngine(int port) : 
    cbport(port),
    juce::InterprocessConnection::InterprocessConnection(false) {
    
}

void RatEngine::run() {
    std::cout << "Well howdy do!" << std::endl;
    //int cbport = 5899;
    bool connected = connectToSocket("127.0.0.1", cbport, 5000);
    std::cout << (connected ? "Connected " : "Not connected ") << cbport << std::endl;
    std::string mystr = "Hello World!";
    bool sent;
/*    for (int r = 0; r < 4; r++) {
        MemoryBlock myMessage;
        myMessage.setSize(12);
        for (int i = 0; i < 12; i++) {
            myMessage[i] = mystr[i];
        }
        sent = sendMessage(myMessage);
    }*/
    std::cout << "running..." << std::endl;
//    int g;
//    std::cin >> g;
}

void RatEngine::endItAll() {
    //active = false;
    while (active) {

    }
    std::cout << "ending..." << std::endl;
//    int g;
//    std::cin >> g;
}

RatEngine::~RatEngine() {
    disconnect();
}

void RatEngine::messageReceived(const juce::MemoryBlock &msg) 
{
//    sendMessage(msg);
    juce::String textMessage = msg.toString();
    std::cout << "Message: " << textMessage << std::endl;
    if (textMessage.compare("END") == 0) {
        std::cout << "That's all, folks!" << std::endl;
        active = 0;
    }
    juce::MemoryBlock checker = msg;
    int a = 0;
//    std::cin >> a;
}

void RatEngine::connectionMade()
{

}

void RatEngine::connectionLost()
{

}