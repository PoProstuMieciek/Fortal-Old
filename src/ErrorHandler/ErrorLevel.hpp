enum ReportingLevel
{
    E_NOPREFIX = 0,
    E_FATAL = 1 << 5,
    E_ERROR = 1 << 4,
    E_WARN  = 1 << 3,
    E_INFO  = 1 << 2,
    E_EXTRA = 1 << 1,
    E_DEBUG = 1 << 0,

    E_ALL     = E_FATAL | E_ERROR | E_WARN | E_INFO | E_EXTRA | E_DEBUG,
    E_VERBOSE = E_FATAL | E_ERROR | E_WARN | E_INFO | E_EXTRA,
    E_DEFAULT = E_FATAL | E_ERROR | E_WARN | E_INFO,
    E_QUIET   = E_FATAL | E_ERROR
};

class ErrorLevel
{
    public:

        int level = E_DEFAULT;

        ErrorLevel(ReportingLevel level = E_DEFAULT) : level(level) {}
        ErrorLevel(int level) : level(level) {}

        void setLevel(int level) { this->level = level; }
        void setFlag(int flag) { this->level |= flag; }
        void unsetFlag(int flag) { this->level &= ~flag; }
        void toggleFlag(int flag) { this->level ^= flag; }
        bool testFlag(int flag) { return (this->level & flag) == flag; }

        operator ReportingLevel() const { return (ReportingLevel) this->level; }
};