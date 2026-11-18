#include "Status.h"
//Status
std::string Status :: getName () const {return STATUS_NAME;}
//Approved
Approved::Approved(): Status();
std::string Approved :: getName() const {return STATUS_NAME;}
//Denied 
Denied:: Denied(): Status();
std::string Denied :: getName () const {return STATUS_NAME;}
//Waiting
Waiting :: Waiting() : Status(); 
std::string Waiting :: getName () const {return STATUS_NAME;}

//Status Creator
std::unique_ptr<Approved> StatusCreator::createApproved() const {
    return std::make_unique<Approved>();
}
std::unique_ptr<Denied> StatusCreator::createDenied() const {
    return std::make_unique<Denied>();
}
std::unique_ptr<Denied> StatusCreator::createWaiting() const {
    return std::make_unique<Waiting>();
}

StatusCreator::StatusCreator(){
    creator["approved"] = [](){ return createApproved();};
    creator["denied"] = [](){ return createDenied();};
    creator["waiting"] = [](){ return createWaiting();};
}

unique_ptr<Status> StatusCreator::creates(const std::string& name) const{
    return (creator.at(name)());
}