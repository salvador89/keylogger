#ifndef BASE_64_H
#define BASE_64_H

#include <vector>
#include <string>

namespace Base64
{
    std::string base64_encode(const std::string &);

    std::string EncryptB64(std::string s)
    {
        //TODO add encryption
        return s;
    }

    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string base64_encode(const std::string &s)
    {
        std::string ret;
        int val = 0;
        int bits = -6;
        const unsigned int b63 = 0x3F;

        for(const auto &c : s)
        {
            val = (val << 8) + c;
            bits += 8;
            while(bits >= 0)
            {
                ret.push_back(BASE64_CODES[(val >> bits)&b63]);
                bits -= 6;
            }

            if(bits > -6)
            {
                ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) & b63]);
            }

            while(ret.size()%4)
            {
                ret.push_back('=');
            }
            return ret;
        }
    }
}

#endif // BASE_64_H
