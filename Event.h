#pragma once
#include <memory>
#include <string>
#include <ctime>
#include "Units.h"

class Event{
    private:
        std::string id;
        std::string name;
        std::unique_ptr<Unit> requester;
        std::string dateTime;
        std::unique_ptr<Status>currStatus;
        std::unique_ptr<UnitComposite> unitsToApprove;
    public:
        Event(const std::string& id, const std::string& name,
            const std::string& requester, const std::string& dateTime);
        ~Event() = default;
        const std::string& getId() const;
        const std::string& getName() const;
        const std::string& getRequester() const;
        const std::string& getDateTime() const;
        void setName(const std::string& newName);
        void setRequester(const std::string& newRequester);
        void setDateTime(const std::string& newDateTime);
        std::string getStatus() const;
        void setStatus(const std::string& status);
        void addApproval(const std::string& label);
        bool removeApproval(const std::string& label);
        void setApprovalStatus(const std::string& label, const std::string& status);
        bool isUrgent(std::time_t now) const;
        std::string toJson() const;
        static std::string statusFromHebrew(const std::string& hebrew);
        static std::string statusToHebrew(const std::string& status, bool forApproval);
};
