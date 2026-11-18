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
        std::unique_ptr<StatusCreator> statusCreator;
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
    const std::string Unit::UNIT_NAME = "unknown";

class Aman : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Aman() = default;
        ~Aman() override = default;
        std::string getName() const override;
};
    const std::string Aman::UNIT_NAME = "aman";
class Avir : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Avir() = default;
        ~Avir() override = default;
        std::string getName() const override;
};
    const std::string Avir::UNIT_NAME = "avir";

class Yam : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Yam() = default;
        ~Yam() override = default;
        std::string getName() const override;
};
    const std::string Yam::UNIT_NAME = "yam";

class Padam : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Padam() = default;
        ~Padam() override = default;
        std::string getName() const override;
};
    const std::string Padam::UNIT_NAME = "padam";

class Patzan : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Patzan() = default;
        ~Patzan() override = default;
        std::string getName() const override;
};
    const std::string Patzan::UNIT_NAME = "patzan";

class Pakmaz : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Pakmaz() = default;
        ~Pakmaz() override = default;
        std::string getName() const override;
};
    const std::string Pakmaz::UNIT_NAME = "pakmaz";

class Shabak : public Unit {
    private:
        static const std::string UNIT_NAME;
    public:
        Shabak() = default;
        ~Shabak() override = default;
        std::string getName() const override;
};
    const std::string Shabak::UNIT_NAME = "shabak";

class UnitComposite : public Unit {
    private:
        std::map<std::string, std::unique_ptr<Unit>> units;
    public:
        UnitComposite() = default;
        ~UnitComposite() override = default;
        void setStatus(const std::string& stat) override;
        std::string getStatus() const override;
        void addUnit(const std::string& name);
        void addUnit(std::unique_ptr<Unit> unit);
        std::string print() const override;
};
