class Status{
    private:
        Status() = default;
        static const std::string STATUS_NAME; 
    public:
        virtual ~Status () = default;
        virtual std::String getName() const;

};
const std::string Status::STATUS_NAME = "unknown";

class Approved : Status{
    private:
        static const std::string STATUS_NAME; 
    public:
        Approved();
        ~Approved() = default;
        std::getName() const override;
};

const std::string Approved::STATUS_NAME = "approved";

class Denied : Status{
    private:
        static const std::string STATUS_NAME; 
    public:
        Denied();
        ~Denied() = default;
};
const std::string Denied::STATUS_NAME = "denied";

class Waiting : Status{
    private:
        static const std::string STATUS_NAME; 
    public:
        Waiting();
        ~Waiting() = default;
};
const std::string Waiting::STATUS_NAME = "waiting";


class StatusCreator {
    private:
        std::map<std::string, std::unique_ptr<Status>(*func)()> creator;
        std::unique_ptr<Approved> createApproved() const;
        std::unique_ptr<Denied> createDenied() const;
        std::unique_ptr<Denied> createWaiting() const;
    public:
        packageCreator();
        unique_ptr<Status> creates(const std::string& name) const;
};