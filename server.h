enum ServerStatus
{
    IDLE,
    BUSY
};

class Server
{
private:
    ServerStatus status;

public:
    Server();
    ServerStatus getServerStatus();
    void setServerStatus(ServerStatus _status);
};