#if 0
Copyright <2018> <Feng Wang>

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#endif
#ifndef BKSDMLDVRLVOKOCTERXUEIKDNCRAQXFWSMBUNVVYFAPNJYHYEBBVBMCDQGBQWGARFUYWEDMFN
#define BKSDMLDVRLVOKOCTERXUEIKDNCRAQXFWSMBUNVVYFAPNJYHYEBBVBMCDQGBQWGARFUYWEDMFN

#ifdef __clang__
#define SUPPRESS_WARNINGS \
_Pragma("clang diagnostic push ") \
_Pragma("clang diagnostic ignored \"-Wglobal-constructors\"") \
_Pragma("clang diagnostic ignored \"-Wc++98-compat\"") \
_Pragma("clang diagnostic ignored \"-Wexit-time-destructors\"") \
_Pragma("clang diagnostic ignored \"-Wc++98-c++11-c++14-compat\"") \
_Pragma("clang diagnostic ignored \"-Wmissing-variable-declarations\"" )
#define RESTORE_WARNINGS \
_Pragma( "clang diagnostic pop" )
#else
#define SUPPRESS_WARNINGS
#define RESTORE_WARNINGS
#endif

#include <map>
#include <string>

SUPPRESS_WARNINGS

namespace color
{

    const static std::map<std::string, std::string> color_foreground =
    {
        { "Default", "39" },
        { "Black", "30" },
        { "Red", "31" },
        { "Green", "32" },
        { "Yellow", "33" },
        { "Blue", "34" },
        { "Magenta", "35" },
        { "Cyan", "36" },
        { "Light Gray", "37" },
        { "Dark Gray", "90" },
        { "Light Red", "91" },
        { "Light Green", "92" },
        { "Light Yellow", "93" },
        { "Light Blue", "94" },
        { "Light Magenta", "95" },
        { "Light Cyan", "96" },
        { "White", "97" }
    };

    const static std::map<std::string, std::string> color_background =
    {
        { "Default", "49" },
        { "Black", "40" },
        { "Red", "41" },
        { "Green", "42" },
        { "Yellow", "43" },
        { "Blue", "44" },
        { "Megenta", "45" },
        { "Cyan", "46" },
        { "Light Gray", "47" },
        { "Dark Gray", "100" },
        { "Light Red", "101" },
        { "Light Green", "102" },
        { "Light Yellow", "103" },
        { "Light Blue", "104" },
        { "Light Magenta", "105" },
        { "Light Cyan", "106" },
        { "White", "107" }
    };


    const static std::map<std::string, std::string> formatting_set =
    {
        { "Default", "0" },
        { "Bold", "1" },
        { "Dim", "2" },
        { "Underlined", "4" },
        { "Blink", "5" },
        { "Reverse", "7" },
        { "Hidden", "8" }
    };

    const static std::map<std::string, std::string> formatting_reset =
    {
        { "All", "0" },
        { "Bold", "21" },
        { "Dim", "22" },
        { "Underlined", "24" },
        { "Blink", "25" },
        { "Reverse", "27" },
        { "Hidden", "28" }
    };

    // Usage:
    //
    //      auto new_message = color::rize( "I am a banana!", "Yellow", "Green" );
    //      std::cout << new_message << std::endl;
    //
    inline std::string rize( std::string const& source,
                             std::string foreground_color = "Default",
                             std::string background_color = "Default",
                             std::string set_formatting = "Default",
                             std::string reset_formatting = "All"
                           )
    {
        std::string const control = "\033";

        if ( color_foreground.find( foreground_color ) == color_foreground.end() )
            foreground_color = "Default";

        if ( color_background.find( background_color ) == color_background.end() )
            background_color = "Default";

        if ( formatting_set.find( set_formatting ) == formatting_set.end() )
            set_formatting = "Default";

        if ( formatting_reset.find( reset_formatting ) == formatting_reset.end() )
            reset_formatting = "All";

        std::string ans =   control  + std::string{"["} +
                            formatting_set.at( set_formatting ) + std::string{";"} +
                            color_background.at( background_color ) + std::string{";"} +
                            color_foreground.at( foreground_color ) + std::string{"m"} +
                            source +
                            control + std::string{"["} +
                            formatting_reset.at( reset_formatting ) + std::string{"m"};
        return ans;
    }

}//namespace color

RESTORE_WARNINGS

#endif//BKSDMLDVRLVOKOCTERXUEIKDNCRAQXFWSMBUNVVYFAPNJYHYEBBVBMCDQGBQWGARFUYWEDMFN

