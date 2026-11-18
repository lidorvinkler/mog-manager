#include "Status.h"

#include <stdexcept>
const std::string Status::STATUS_NAME = "unknown";
const std::string Approved::STATUS_NAME = "approved";
const std::string Denied::STATUS_NAME = "denied";
const std::string Waiting::STATUS_NAME = "waiting";

const Factory<Status>& Status::statusFactory() {
    static const Factory<Status> factory = []{
        Factory<Status> f;
        f.addElem<Approved>("approved");
        f.addElem<Denied>("denied");
        f.addElem<Waiting>("waiting");
        return f;
    }();
    return factory;
}

std::unique_ptr<Status> Status::creates(const std::string& name) {
    return statusFactory().creates(name);
}

//Status
std::string Status :: getName () const {return STATUS_NAME;}
//Approved
Approved::Approved(): Status(){}
std::string Approved :: getName() const {return STATUS_NAME;}
//Denied 
Denied:: Denied(): Status(){}
std::string Denied :: getName () const {return STATUS_NAME;}
//Waiting
Waiting :: Waiting() : Status() {}
std::string Waiting::getName() const { return STATUS_NAME; }

