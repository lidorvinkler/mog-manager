class Status{
    private:
        Status() = default;
    public:
        virtual ~Status () = default;
        virtual bool isApproved() const;
        virtual bool isDenied() const;
        virtual std::String getName() const;
};

class Approved : Status{
    public:
        Approved();
        ~Approved() = default;
        bool isApproved() const override;
        std::getName() const override;
}
class Denied : Status{
    public:
        Denied();
        
} 
class Waiting : Status{}

