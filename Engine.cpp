//
// Created by xiodine on 4/15/15.
//

#include "Engine.h"
#include "log.h"
#include "controllers/Controller.h"
#include "controllers/Viewer.h"

#include <fstream>
#include <iostream>

void Engine::run() {
    std::string query;
    do {
        std::cout << "Query (vezi README): ";
        getline(std::cin, query);
        Controller *controller = NULL;
        if (query == "1") {
            controller = new Viewer();
        } else {
            if (query != "STOP") {
                std::cout << "Nu am inteles!\n";
            }
        }

        if (controller != NULL) {
            controller->run();
            delete controller;
        }
    } while (query != "STOP");
//    std::vector<std::string> trasaturi;
//    trasaturi.push_back("bruna");
//    trasaturi.push_back("blonda");
//    stoc_.addBun(Bun("Bere", "halba", trasaturi, 0, 15.0, 13.0));
}

void Engine::load() {
    d("");
    std::ifstream input("data/models.dat");
    stoc_.loadSettings(input);
}

Engine::Engine() {
    d("engine started");
    load();
}

Engine::~Engine() {
    std::ofstream output("data/models.dat");
    stoc_.saveSettings(output);
    d("engine stopped");
}
