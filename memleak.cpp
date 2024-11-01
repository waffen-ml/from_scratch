/* Debug memory allocation support */
#ifndef NDEBUG 
# define _CRTDBG_MAP_ALLOC
# include <crtdbg.h> 
# define SetDbgMemHooks() \
  _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | \
  _CRTDBG_ALLOC_MEM_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
static class __Dummy
{
public:
    /* Class constructor */
    __Dummy(void)
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
        _CrtSetBreakAlloc(9554);
        _CrtSetBreakAlloc(9553);
        _CrtSetBreakAlloc(9552);
        SetDbgMemHooks();
    } /* End of '__Dummy' constructor */
} __oops;

#endif /* _DEBUG */
