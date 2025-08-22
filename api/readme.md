# How to Use the SASDL API
## Rundown
If you've used the SA2 Render Fix or Input Controls APIs, the process for this is similar but there are notable differences.

It's recommended that you have at least a basic understanding of C or C++ before using the API, as this assumes you already have knowledge on the foundations of the language.

The SASDL API is the common interface for accessing and using SDL2 in a standard and more cross-mod compatible way. SASDL handles the very basic processes for you, such as Init, Quit, and dispersing SDL events to all mods using the API. Everything else, including handling those events, is up to you.

The "API" itself is a structure containing basic version data and functions that give you direct access to the internal functions of the mod. You can get this structure in a few ways, but the main way is allowing SASDL to call a special exported function in your mod; it's also in this function that you can define what flags you want `SDL_Init` to be called with.

This all may sound complicated, but the process is actually fairly trivial and I'll walk you through it step by step in this readme. It is recommended you have the API header open while you read this, to give additional context as I explain things.

## Step by Step
### The API Headers
First, you need to import any API headers into your project. This can be done any way you like, including just copying them. The headers are important as it defines the API structures and types; without them you'll be programming blind.

Once it's in your project, make sure to include it in any source files that will be using the API directly. It's recommended to make a seperate source file specifically to handle the API, essentially making "wrapper" functions for your own mod, although it's not necessary.

Not all API modules/structures can be used at the same time, some might only have small windows of availability. These times are clearly labled at the top of the headers, and look like this:
```c
*   Availability:
*     - API_Func0       : No
*     - API_Func1       : Yes
*     - After Init      : Yes
```
In this case, this structure can be used inside of `API_Func1` and after the game is done booting (player is in-game), but it can't be used inside of `API_Func0`. Attempting to use an API outside of it's availability window is usually undefined behavior, so make sure to double check this before using anything. Luckily, it applies to whole modules, and not individual functions (and for SASDL, that means only 1 module).

Every callable function also has a description to help you use them as intended. For example:
```c
    /*
    *   Description:
    *     Takes a list of things, and does stuff to them.
    * 
    *   Parameters:
    *     - pThings     : pointer to things
    *     - nbThings    : number of things
    */
    void (__cdecl* example_v0)( thing* pThings, int nbThings );
```
It's normally more descripive than this example, but you can see the function explaining how to use it and what each parameter does. Follow these carefully.

Over time, the API may be expanded to support new features. When this happens the structure `version`, a struct member located directly at the top, will be increased - it looks like this:
```c
typedef struct
{
    uint32_t version;                   /* structure version                                    */
    
    /****** Version >= 0 ************************************************************************/
    /*
    *   ...
    */
    void (__cdecl* example_v0)( ... );  /* member example, v0                                   */                  
    
    /****** Version >= 1 ************************************************************************/
    /*
    *   ...
    */
    void (__cdecl* example_v1)( ... );  /* member example, v1                                   */    
...
```
You can also see here the large span comments seperating what each version supports. These versions start at `0`, indicating no changes since release. In this case, a `version` of `1` indicates `example_v0` and `example_v1` are available, but a `version` of `0` means only `example_v0` is available and that attempting to use `example_v1` will likely crash. It's important you refer to the version variable when calling API functions, as the user may have an older version that doesn't include the function you wish to call yet.

With this, you can also enforce a minimum API version that your mod will work with. Try not to just set this to the latest version though, take a second to see what the lowest version you can use is so as many people as possible can enjoy your mod!

Now that you have the headers and structures, you need to actually get the API. This is pretty easy, so let's go through it.

### Getting the API
In order to use the API, you need to actually get it somehow. This can be done in 1 of 2 ways:

1. Creating a user-exported function for the API to call your mod. (Recommended)
2. Directly getting the exported API from the API's DLL handle.

Method '2' should be avoided, and it's only an option for power-users who have some specific use case the regular method doesn't fill. We will be using method '1' going forward.

With that out of the way, what is a "user-exported function" and how do we make one?

### User-Exported Functions
The API is capable of calling a special set of functions in your mod directly, these are called "user-exported functions". They are very similar in form to the normal `Init` functions DLL mods have to make; if you've made one of those, this part will be a breeze.

For SASDL, the only function available is `SASDLAPI_Init` - it both gives you access to the API structure and gives you a chance to set the `SDL_Init` flags via a return value (and if you're using SDL, you likely want to set some init flags).

Here's a crude example of `SASDLAPI_Init` for us to dissect:
```c
extern "C" __declspec(dllexport)
int32_t SASDLAPI_Init(const SASDLAPI* pApi, const char* puPath, const HelperFunctions* pHelpFuncs, size_t ixMod)
{
    // return wanted SDL_Init flags
    return SDL_INIT_GAMECONTROLLER;
}
```

Now, a lot is going on there, but let's break it down:

1. `extern "C"`: 
    This makes the function name fixed, it's otherwise random\* - this is only needed when using C++. You can also place the function in an `extern "C"` block using `{` & `}`, either way works. 

2. `__declspec(dllexport)`: 
    This tells marks the function to be exported from your DLL file. This will allow the API to search for and find your function using its name.

3. Return Type/Value:
    The function must return any `SDL_Init` flags you want SASDL to use for you. In this case, we're requesting the `SDL_INIT_GAMECONTROLLER` flag.
    
4. Parameters: 
    The params from left to right are:
    1. `const SASDLAPI*`        : this is a pointer to the core API structure
    2. `const char*`            : this is a string path to *your* mod's folder (in UTF-8 if you were curious)
    3. `const HelperFunctions*` : this is a reference/pointer to the Mod Loader's HelperFunctions
    4. `size_t`                 : this is the mod index of *your* mod, if you wish to use it

\*It's not actually random, there is method to the madness, but it is a lot harder to work with and would restrict the API to C++ only.

All user-exported functions are ran during the API's own `Init` function, these means you can't guarantee that your exported API function will run before your own `Init` function does. Because of this, it's not recommended to access the API inside of your `Init` function and to either restrict it to your exported API function, or just wait until the game is actually running - after all `Init`s have been called. This *also* means you can't use the exported API function to check if the API is installed, that should be done seperately with the `ModInfo` stuff given by the Mod Loader.

Now that you have the API, it's time to make use of it.

### Using the API
Once you have the API pointer, it's up to you how you use it! It's recommended you save any pointers you want to use for later - either by saving only the core module pointer, saving each module pointer, or by saving each individual function pointer as needed. The pointers are constant for the lifetime of the program and none of the structures will be changed or free'd after you're given them. 

Now, let's do some full examples!

## Complete examples
Checking each API structure version individually:
```c
extern "C" __declspec(dllexport)
int32_t SASDLAPI_Init(const SASDLAPI* pApi, const char* puPath, const HelperFunctions* pHelpFuncs, size_t ixMod)
{
    if ( pApi->version >= 1 )    // module 'version' check
    {
        pApi->example_v0( ... ); // function available in version 0
        pApi->example_v1( ... ); // function available in version 1
    }

    // return wanted SDL_Init flags
    return SDL_INIT_GAMECONTROLLER;
}
```

Checking the SASDL mod version:
```c
extern "C" __declspec(dllexport)
int32_t SASDLAPI_Init(const SASDLAPI* pApi, const char* puPath, const HelperFunctions* pHelpFuncs, size_t ixMod)
{
    if ( SASDL_CHECKVER( pApi, 1,1,0,0 ) ) // equal or higher than v1.1.0.0
    {
        pApi->example_v0( ... ); // function available in version 0, part of v1.0.0
        pApi->example_v1( ... ); // function available in version 1, part of v1.1.0
    }

    // return wanted SDL_Init flags
    return SDL_INIT_GAMECONTROLLER;
}
```

Using API after Init:
```c
const SASDLAPI* SasdlApi;

void FunctionThatRunsLater(void)
{
    if ( SasdlApi )
    {
        SasdlApi->example_v1( ... );
    }
}

extern "C" __declspec(dllexport)
int32_t SASDLAPI_Init(const SASDLAPI* pApi, const char* puPath, const HelperFunctions* pHelpFuncs, size_t ixMod)
{
    if ( pApi->version >= 1 )       // module 'version' check
    {
        pApi->example_v0( ... );    // function available in version 0
        
        SasdlApi = pApi;
    }

    // return wanted SDL_Init flags
    return SDL_INIT_GAMECONTROLLER;
}
```

## Additional Notes
The API will never have breaking changes. Names may change, but your old code will always continue work. Sometimes functions are depricated, but continued suppport of old mods is a top priority. At worst, a function will just do nothing past a point, but that is always a last resort when all else has failed.

The examples used a `const HelperFunctions*` for user-exported function parameters, this is exactly the same as a `const HelperFunctions&` just used a bit differently - the compiled code underneath is exactly the same. So, either is fine.

These examples were in C++, as that's most commonly used by modders, but it all works the same in C. If you're using C, I'm sure you can figure out what you need to change on your own.
