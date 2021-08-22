#include "server.h"

Server::Server(){
    this->status = ServerStatus::IDLE;
}

ServerStatus Server::getServerStatus(){
    return this->status;
}

void Server::setServerStatus(ServerStatus _status){
    this->status = _status;
}