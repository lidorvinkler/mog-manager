#pragma once
#include <memory>
#include <string>
#include <vector>

#include "factory.h"
#include "Status.h"

class Unit {
    private:
        static const std::string UNIT_NAME;
        std::unique_ptr<Status> approveStatus;
        static const Factory<Unit>& unitFactory();
    protected:
        Unit();
        virtual const Status& getStatusObject() const;
    public:
        virtual ~Unit() = default;
        virtual void setStatus(const std::string& stat);
        virtual std::string getStatus() const;
        virtual std::string getName() const;
        virtual std::string print() const;
        static std::unique_ptr<Unit> creates(const std::string& name);
};

class Aman : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Aman() = default;
        ~Aman() override = default;
        std::string getName() const override;
};
class Avir : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Avir() = default;
        ~Avir() override = default;
        std::string getName() const override;
};

class Yam : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Yam() = default;
        ~Yam() override = default;
        std::string getName() const override;
};

class Padam : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Padam() = default;
        ~Padam() override = default;
        std::string getName() const override;
};

class Patzan : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Patzan() = default;
        ~Patzan() override = default;
        std::string getName() const override;
};

class Pakmaz : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Pakmaz() = default;
        ~Pakmaz() override = default;
        std::string getName() const override;
};

class Shabak : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Shabak() = default;
        ~Shabak() override = default;
        std::string getName() const override;
};

class UnitComposite : public Unit {
    private:
        std::map<std::string, std::unique_ptr<Unit>> units;
    public:
        UnitComposite() = default;
        ~UnitComposite() override = default;
        void setStatus(const std::string& name, const std::string& stat);
        std::string getStatus() const override;
        void addUnit(const std::string& name);
        std::string print() const override;
};
