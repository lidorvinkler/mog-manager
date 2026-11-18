Class Unit{
    private:
        unique_ptr<Status::Status> approveStatus;
    protected: 
        Unit();
        
    public:
        virtual ~Unit();
        bool isApproved();
}

class UnitComposite :: Unit{
    private:
        std::vector <std::unique_ptr<Unit>>units;

}