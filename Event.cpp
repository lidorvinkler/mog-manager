Class Event{
    private:
        std::string name;
        std::string date;
        std::unique_ptr<Unit> demand; 
        std::unique_ptr<Status>currStatus;
        std::unique_ptr<Unit> unitsToApprove;
    public:
        Event()
}