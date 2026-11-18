#pragma once
#include <map>
#include <memory>
#include <string>

#include "factory.h"

class Status{
    private:
        static const std::string STATUS_NAME;
        static const Factory<Status>& statusFactory();
    protected:
        Status() = default;
    public:
        virtual ~Status () = default;
        virtual std::string getName() const;
        static std::unique_ptr<Status> creates(const std::string& name);
};

class Approved : public Status{
    private:
        static const std::string STATUS_NAME;
    public:
        Approved();
        ~Approved() override = default;
        std::string getName() const override;
};


class Denied : public Status{
    private:
        static const std::string STATUS_NAME;
    public:
        Denied();
        ~Denied() override = default;
        std::string getName() const override;
};

class Waiting : public Status{
    private:
        static const std::string STATUS_NAME; 
    public:
        Waiting();
        ~Waiting() override = default;
        std::string getName() const override;

};

