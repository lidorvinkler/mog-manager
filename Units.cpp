#include "Units.h"

#include <stdexcept>

const Factory<Unit>& Unit::unitFactory() {
    static const Factory<Unit> factory = [] {
        Factory<Unit> f;
        f.addElem<Aman>("aman");
        f.addElem<Avir>("avir");
        f.addElem<Yam>("yam");
        f.addElem<Padam>("padam");
        f.addElem<Patzan>("patzan");
        f.addElem<Pakmaz>("pakmaz");
        f.addElem<Shabak>("shabak");
        return f;
    }();
    return factory;
}

// Unit
Unit::Unit()
    : approveStatus(std::make_unique<Waiting>()),
      statusCreator(std::make_unique<StatusCreator>()) {
}

void Unit::setStatus(const std::string& name) {
    approveStatus = Status::creates(name);
}

std::string Unit::getName() const { return UNIT_NAME; }
std::string Unit::getStatus() const { return approveStatus->getName(); }
const Status& Unit::getStatusObject() const { return *approveStatus; }
std::string Unit::print() const { return getName() + " : " + getStatus(); }
std::unique_ptr<Unit> Unit::creates(const std::string& name) {
    return unitFactory().creates(name);
}
std::string Aman::getName() const   { return UNIT_NAME; }
std::string Avir::getName() const   { return UNIT_NAME; }
std::string Yam::getName() const    { return UNIT_NAME; }
std::string Padam::getName() const  { return UNIT_NAME; }
std::string Patzan::getName() const { return UNIT_NAME; }
std::string Pakmaz::getName() const { return UNIT_NAME; }
std::string Shabak::getName() const { return UNIT_NAME; }

void UnitComposite::setStatus(const std::string& stat) {
    for (const auto& elem : units) {
        elem->setStatus(stat);
    }
}

std::string UnitComposite::print() const {
    std::string res;
    for (const auto& elem : units) {
        res +=  elem.second -> print() +  "\n";
    }
    return res;
}





std::string UnitComposite::getStatus() const{
    for(const auto& elem : this -> units){
        if (elem.second->getStatus() != Approved().getName()) {
            return elem.second->getStatus();
        }
    }
    return Approved().getName();
}

void UnitComposite::addUnit(const std::string& name){
    units[name] = creates(name);
}