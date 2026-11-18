#pragma once
#include "Status.h"

Class Unit{
    private:
        unique_ptr<Status::Status> approveStatus;
        unique_ptr<StatusCreator> statusCreator;
        const static std::string UNIT_NAME;
    protected: 
        Unit();
    public:
        virtual ~Unit();
        virtual setStatus(const std::string& stat);
        virtual const Status& getStatus() const;
        virtual std::string getStatus() const;
        std::string getName() const;
        std::string print() const;
        
};
const static std::string Unit::UNIT_NAME = "unknown";

class UnitComposite : Unit{
    private:
        std::vector <std::unique_ptr<Unit>>units;
    public:
        UnitComposite();
        ~UnitComposite() = default;
        setStatus(const std::string& stat) override;
        std::string getStatus() const override;
        void addUnits(const std::string& name);
};

class Aman : Unit{
    private:
        const static std::string UNIT_NAME;
    public:
        Aman();
        ~Aman() = default;
        std::string getName() const override;
};
const static std::string Aman::UNIT_NAME = "aman";

class Avir : Unit{
    private:
        const static std::string UNIT_NAME;
    public:
        Avir();
       ~Avir();
        std::string getName() const override;
};
const static std::string Avir::UNIT_NAME = "avir";

class Yam : Unit{
    private:
        const static std::string UNIT_NAME;
    public:
        Yam();
       ~Yam();
        std::string getName() const override;
};
const static std::string Yam::UNIT_NAME = "yam";

class Padam : Unit{
    private:
        const static std::string UNIT_NAME;
    public:
        Padam();
        ~Padam();
        std::string getName() const override;
};
const static std::string Padam::UNIT_NAME = "padam";

class Patzan : Unit{
    private:
        const static std::string UNIT_NAME;
    public:
        Patzan();
        ~Patzan();
        std::string getName() const override;
};
const static std::string Patzan::UNIT_NAME = "patzan";

class Pakmaz : Unit{
    private:
        const static std::string UNIT_NAME;
    public:
        Pakmaz();
        ~Pakmaz();
        std::string getName() const override;
};
const static std::string Pakmaz::UNIT_NAME = "pakmaz";

class Shabak {
    private:
        const static std::string UNIT_NAME;
    public:
        Shabak();
        ~Shabak();
        std::string getName() const override;
};
const static std::string Shabak::UNIT_NAME = "shabak";